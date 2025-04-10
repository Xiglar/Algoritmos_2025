# 📚 Clase IV: Algoritmos y Estructuras de Datos  

## 🏆 Problema 1: Top K  

**Ejercicio 8.2**  

### 🔹 Enunciado  

Se requiere una función **top k** que reciba un arreglo de números y un valor `k`, y devuelva los `k` mayores elementos del arreglo.  

Se analizan tres implementaciones con distintas complejidades:  

1. **Ordenando el arreglo:**  
   - Se ordena el arreglo y se toman los `k` mayores.  
   - 📌 **Pregunta:** ¿Cuál es la complejidad de esta implementación?  

2. **Usando un arreglo auxiliar de `k` elementos:**  
   - Se mantiene un arreglo auxiliar con los `k` mayores elementos vistos hasta el momento.  
   - Cada nuevo número se compara con los elementos del arreglo auxiliar, y si es mayor a alguno, se reemplaza al menor de ellos.  
   - 📌 **Pregunta:** ¿Cuál es la complejidad de esta implementación?  

3. **Optimización con `O(n log k)`:**  
   - Diseñar e implementar una solución eficiente que mantenga los `k` mayores elementos con una complejidad **O(n log k)**.  

---

## 🔢 Problema 2: Mantenimiento de Mediana Dinámica  

**Ejercicio 8.6**  

### 🔹 Enunciado  

Se necesita desarrollar un sistema capaz de calcular la **mediana** de un conjunto de números en **tiempo real**.  

📌 **Requisitos:**  
- Los números llegan de forma secuencial, uno a uno.  
- Después de cada inserción, se debe devolver la **mediana actual**.  
- Si el conjunto tiene un número impar de elementos, la mediana es el valor en la posición central.  
- Si el conjunto tiene un número par de elementos, la mediana es el promedio de los dos valores centrales.  

### ✨ Ejemplo  

🔸 **Entrada:**  
```
6 5 2 1 7 5 3
```

🔹 **Salida esperada:**  
```
5 3.5 2 3.5 5 4
```

📌 **Explicación paso a paso:**  

| Números agregados | Conjunto ordenado | Mediana |
|-------------------|------------------|---------|
| `6`              | `[6]`            | `6`     |
| `5`              | `[5, 6]`         | `(5+6)/2 = 5.5` |
| `2`              | `[2, 5, 6]`      | `5`     |
| `1`              | `[1, 2, 5, 6]`   | `(2+5)/2 = 3.5` |
| `7`              | `[1, 2, 5, 6, 7]` | `5`     |
| `5`              | `[1, 2, 5, 5, 6, 7]` | `(5+5)/2 = 5` |
| `3`              | `[1, 2, 3, 5, 5, 6, 7]` | `4` |

---

## Problema 3: ¿Cuáles de estos métodos construyen un heap correctamente?  

<!-- Falso no cumple la propiedad de un heap -->
1. Ordenar el arreglo  

<!-- Falso No garantiza la correcta estructura del heap.   -->
2. Hacer heap-up de cada elemento desde el último al primero  

3. Hacer heap-up desde el primero al último  

4. Hacer heap-down desde el último al primero  

<!-- Falso No garantiza la correcta estructura del hea -->
5. Hacer heap-down desde el primero al último  
****
