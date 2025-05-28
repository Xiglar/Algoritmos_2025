#include "tp3.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define LOAD_FACTOR 0.7
#define INITIAL_CAPACITY 1999

typedef struct cell {
    char *key;
    void *value;
    bool used;
    bool deleted;
} cell_t;

struct dictionary {
  cell_t *table;
  size_t capacity;
  size_t count;
  destroy_f destroy;
};


///// AUXILIAR FUNCTIONS /////

char *my_strdup(const char *s) {
  size_t len = strlen(s);
  char *copy = malloc(len + 1);
  if (!copy) return NULL;
  strcpy(copy, s);
  return copy;
}

size_t fnv_hash(const char *key, size_t capacity) {
  const uint32_t FNV_OFFSET_BASIS = 2166136261u;
  const uint32_t FNV_PRIME = 16777619u;

  uint32_t hash = FNV_OFFSET_BASIS;

  for (const unsigned char *p = (const unsigned char *)key; *p != '\0'; p++) {
    hash ^= *p;
    hash *= FNV_PRIME;
  }

  return hash % capacity;
}

static bool dictionary_rehash(dictionary_t *dict) {
  size_t new_capacity = dict->capacity * 2 + 1;
  cell_t *new_table = calloc(new_capacity, sizeof(cell_t));
  if (!new_table) return false;

  for (size_t i = 0; i < dict->capacity; i++) {
    cell_t *old_cell = &dict->table[i];
    if (old_cell->used && !old_cell->deleted) {
      size_t pos = fnv_hash(old_cell->key, new_capacity);
      while (new_table[pos].used) {
        pos = (pos + 1) % new_capacity;
      }
      new_table[pos].key = my_strdup(old_cell->key);
      new_table[pos].value = old_cell->value;
      new_table[pos].used = true;
      new_table[pos].deleted = false;

      free(old_cell->key);
    }
  }

  free(dict->table);
  dict->table = new_table;
  dict->capacity = new_capacity;

  return true;
}

static cell_t *dict_find_cell(dictionary_t *dict, const char *key) {
  size_t pos      = fnv_hash(key, dict->capacity);
  size_t original = pos;

  while (true) {
    cell_t *cell = &dict->table[pos];
    if (!cell->used) return NULL;
    if (!cell->deleted && strcmp(cell->key, key) == 0)
        return cell;
    pos = (pos + 1) % dict->capacity;
    if (pos == original) return NULL;
  }
}

///// TP FUNCTIONS /////

dictionary_t *dictionary_create(destroy_f destroy) {
  dictionary_t *dict = malloc(sizeof(dictionary_t));
  if (!dict) return NULL;

  dict->table = calloc(INITIAL_CAPACITY, sizeof(cell_t));
  if (!dict->table) {
      free(dict);
      return NULL;
  }

  dict->capacity = INITIAL_CAPACITY;
  dict->count = 0;
  dict->destroy = destroy;
  
  return dict;
}

bool dictionary_put(dictionary_t *dictionary, const char *key, void *value) {
  if (!dictionary || !key || key[0] == '\0') return false;

  if ((double)(dictionary->count) / (double)(dictionary->capacity) > LOAD_FACTOR) {
    if (!dictionary_rehash(dictionary)) return false;
  }

  size_t pos = fnv_hash(key, dictionary->capacity);
  size_t original = pos;

  while (true) {
    cell_t *cell = &dictionary->table[pos];

    if (!cell->used || cell->deleted) {
      char* copy_key = my_strdup(key);
      if (!copy_key) return false;
      
      cell->key = copy_key;
      cell->value = value;
      cell->used = true;
      cell->deleted = false;
      dictionary->count++;
      return true;
    }

    if (!cell->deleted && strcmp(cell->key, key) == 0) {
      if (dictionary->destroy && cell->value) dictionary->destroy(cell->value);

      cell->value = value;
      return true;
    }

    pos = (pos + 1) % dictionary->capacity;

    if (pos == original) return false;
  }
};

void *dictionary_get(dictionary_t *dictionary, const char *key, bool *err) {
  if (!dictionary || !key || key[0]=='\0') {
    if (err) *err = true;
    return NULL;
  }
  cell_t *cell = dict_find_cell(dictionary, key);
  if (!cell) {
    if (err) *err = true;
    return NULL;
  }
  if (err) *err = false;
  return cell->value;
};

bool dictionary_delete(dictionary_t *dictionary, const char *key) {
  if (!dictionary || !key || key[0] == '\0') return false;

  cell_t *cell = dict_find_cell(dictionary, key);
  if (!cell) return false;

  free(cell->key);

  if (dictionary->destroy && cell->value) dictionary->destroy(cell->value);

  cell->deleted = true;
  dictionary->count--;

  return true;
};

void *dictionary_pop(dictionary_t *dictionary, const char *key, bool *err) {
  if (!dictionary || !key || key[0] == '\0') {
    if (err) *err = true;
    return NULL;
  }

  cell_t *cell = dict_find_cell(dictionary, key);
  if (!cell) {
    if (err) *err = true;
    return NULL;
  }

  void *value = cell->value;

  free(cell->key);

  cell->deleted = true;
  dictionary->count--;

  if (err) *err = false;
  return value;
};

bool dictionary_contains(dictionary_t *dictionary, const char *key) {
  return dict_find_cell(dictionary, key) != NULL;
};

size_t dictionary_size(dictionary_t *dictionary) { return dictionary->count; };

void dictionary_destroy(dictionary_t *dictionary){
  if (!dictionary) return;

  for (size_t i = 0; i < dictionary->capacity; i++) {
    cell_t *cell = &dictionary->table[i];

    if (cell->used && !cell->deleted) {
      free(cell->key);
      if (dictionary->destroy && cell->value) {
        dictionary->destroy(cell->value);
      }
    }
  }

  free(dictionary->table);
  free(dictionary);
};