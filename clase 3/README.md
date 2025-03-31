****# **Clase III**  
### *Algoritmos y estructuras de datos*  

## **Problema 1: Procesamiento de Eventos en Tiempo Real**  

En un sistema de monitoreo en tiempo real, los eventos tienen un tiempo de validez limitado. A medida que los eventos llegan, es necesario mantener una lista de aquellos que aún no han expirado.  

### **Requisitos:**  
- Diseña una estructura de datos que permita:  
  - **Agregar** nuevos eventos.  
  - **Eliminar** eventos que hayan expirado.  
  - **Consultar** los eventos actualmente válidos de manera eficiente.  

### **Entrada:**  
Una secuencia de pares `(timestamp, duration)`, donde:  
- `timestamp` representa el momento en que ocurrió el evento.  
- `duration` indica la cantidad de segundos que el evento es válido.  

### **Salida:**  
Después de cada inserción, la estructura debe devolver la lista de eventos que aún no han expirado.  

---

## **Problema 2: Distancia Mínima entre Elementos Iguales**  

La **distancia** entre dos valores en un arreglo se define como la cantidad de posiciones entre ellos. Dado un arreglo de enteros, encuentra la distancia mínima entre cualquier par de elementos iguales. Si no hay elementos repetidos, devuelve `-1`.  

### **Ejemplo:**  
Para el arreglo `[3, 2, 1, 2, 3]`:  
- Los valores `3` aparecen en los índices `0` y `4`, con una distancia de `4 - 0 = 4`.  
- Los valores `2` aparecen en los índices `1` y `3`, con una distancia de `3 - 1 = 2`.  
- La mínima distancia es `2`, por lo que la función debe devolver `2`.  

### **Requisitos:**  
- Implementa una función que, dado un arreglo de enteros, devuelva la menor distancia entre dos elementos iguales.  
- Si no hay elementos repetidos, devuelve `-1`.  

### **Entrada:**  
Un arreglo de enteros.  

### **Salida:**  
Un entero representando la mínima distancia entre dos elementos iguales o `-1` si no hay pares repetidos.  

---

## **Desafío: Diferencia Absoluta de Diagonales**  

Dada una **matriz cuadrada**, calcula la **diferencia absoluta** entre las sumas de sus diagonales.  

### **Ejemplo:**  
Para la siguiente matriz de `3x3`:  

```
1  2  3  
4  5  6  
9  8  9  
```
- La diagonal principal (de izquierda a derecha) es `1 + 5 + 9 = 15`.  
- La diagonal secundaria (de derecha a izquierda) es `3 + 5 + 9 = 17`.  
- La diferencia absoluta entre ambas sumas es `|15 - 17| = 2`.  

### **Requisitos:**  
- Implementa una función que reciba una matriz cuadrada y su tamaño `n`, y devuelva la diferencia absoluta entre las sumas de sus diagonales.  

### **Entrada:**  
- Una matriz cuadrada de enteros de tamaño `n x n`.  
- Un entero `n` representando el tamaño de la matriz.  

### **Salida:**  
Un entero representando la diferencia absoluta entre las sumas de las diagonales.