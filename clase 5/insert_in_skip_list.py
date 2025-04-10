import random

MAX_LEVEL = 4

class Node:
    def __init__(self, key, level):
        self.key = key
        self.next = None
        self.prev = None
        self.up = None
        self.down = None

class SkipList:
    def __init__(self):
        self.heads = [Node(None, i) for i in range(MAX_LEVEL)]
        for i in range(MAX_LEVEL - 1, 0, -1):
            self.heads[i].down = self.heads[i - 1]
            self.heads[i - 1].up = self.heads[i]
        self.levels = MAX_LEVEL

    def random_level(self):
        level = 0
        while random.random() < 0.5 and level < self.levels - 1:
            level += 1
        return level

    def insert(self, key):
        level = self.random_level()
        current = self.heads[level]
        new_node = None
        
        # Vamos bajando e insertando en cada nivel hasta abajo
        for lvl in range(level, -1, -1):
            while current.next and current.next.key < key:
                current = current.next

            node = Node(key, lvl)
            node.next = current.next
            node.prev = current
            if current.next:
                current.next.prev = node
                current.next = node

            if new_node:
                node.up = new_node
                new_node.down = node
            
            new_node = node

            if current.down:
                current = current.down

