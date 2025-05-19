# Clase 12 - Hashing

## Problema 1: Perfiles Duplicados en Red Social

Has sido contratado por una compañía que desarrolla una gran red social. Tu primera tarea consiste en buscar perfiles que probablemente pertenecen a un mismo usuario.

La red social contiene `n` perfiles registrados, numerados del 1 al `n`. Algunos pares de perfiles son amigos (la relación de "amistad" es mutua, es decir, si `i` es amigo de `j`, entonces `j` también es amigo de `i`).

Se dice que dos perfiles `i` y `j` (con `i ≠ j`) son **duplicados** si para cualquier otro perfil `k` (donde `k ≠ i` y `k ≠ j`), se cumple una de las siguientes condiciones:

* `k` es amigo tanto de `i` como de `j`, o
* `k` no es amigo ni de `i` ni de `j`.

Es decir, los conjuntos de amigos de `i` y `j`, excluyéndose mutuamente, son indistinguibles desde el punto de vista de los demás perfiles. Además, `i` y `j` pueden ser amigos entre sí o no.

Tu tarea es contar el número de pares no ordenados `(i, j)` tales que los perfiles `i` y `j` son duplicados.

### Entrada

* La primera línea contiene dos enteros `n` y `m` (1 ≤ `n` ≤ 10<sup>6</sup>, 0 ≤ `m` ≤ 10<sup>6</sup>), el número de perfiles y el número de relaciones de amistad, respectivamente.
* Las siguientes `m` líneas contienen pares de enteros `v` y `u` (1 ≤ `v`, `u` ≤ `n`, `v` ≠ `u`), que indican que los perfiles `v` y `u` son amigos.

Se garantiza que cada par no ordenado de amigos aparece como mucho una vez, y que ningún perfil es amigo de sí mismo.

### Salida

* Imprime un único entero: la cantidad de pares no ordenados de perfiles que son duplicados.

### Ejemplo

#### Entrada

Si son 3 perfiles y 2 relaciones de amistad:

```
1 2
3 2
```

#### Salida

```
1
```

## Problema 2: Santa y los Palíndromos

Santa Claus adora los palíndromos. Recientemente fue su cumpleaños, y **k** de sus amigos lo visitaron para felicitarlo, cada uno regalándole una cadena de caracteres **sᵢ** de longitud **n**. Santa asigna a cada cadena una **belleza aᵢ**, que puede ser negativa si no le gusta la cadena.

Santa está pensando en cuál es **la máxima belleza total que puede obtener al concatenar algunas (o todas) de las cadenas para formar un palíndromo**. Cada regalo puede ser usado como mucho una vez. **Todas las cadenas tienen la misma longitud**.

> Recordá: un palíndromo es una cadena que se lee igual de izquierda a derecha que de derecha a izquierda.

Incluso si todas las bellezas son negativas, la respuesta no puede ser menor que 0, porque siempre puede no usar ninguna cadena (la cadena vacía también es un palíndromo).

---

### Entrada

- La primera línea contiene dos enteros positivos **k** y **n**, indicando la cantidad de amigos de Santa y la longitud de cada cadena respectivamente. (1 ≤ k, n ≤ 100000; n·k ≤ 100000).
- Luego siguen **k líneas**, cada una con una cadena **sᵢ** de longitud **n** y un número entero **aᵢ** (−10000 ≤ aᵢ ≤ 10000), indicando la belleza de esa cadena.

**Notas:**
- Pueden haber cadenas repetidas con distintas bellezas.

---

### Salida

- Imprimí un solo entero: la **máxima belleza total** que se puede obtener concatenando cadenas para formar un palíndromo.

---

### Ejemplo

#### Entrada

```
4 3
abc 3
cba 4
aba 2
def -5
```

#### Salida

```
9
```

#### Explicación

Podemos usar las cadenas "abc" y "cba" (forman un palíndromo juntas: "abccba"), y también "aba" (que es un palíndromo por sí misma). La suma de bellezas es: 3 + 4 + 2 = 9.
