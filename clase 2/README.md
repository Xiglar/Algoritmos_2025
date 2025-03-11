
# Clase II
*Algoritmos y estructuras de datos*

## 1. Subarray con la suma máxima
- **Descripción**: Dado un array de números enteros, encuentra el subarray contiguo (que contiene al menos un número) que tenga la suma más grande y devuelve esa suma.
- **Entrada**: Un array de enteros.
- **Salida**: Un entero que representa la suma máxima de un subarray.

### Ejemplo:
- **Entrada**: `[-2, 1, -3, 4, -1, 2, 1, -5, 4]`
- **Salida**: `6`

## 2. Producto de arrays excepto el propio elemento
- **Descripción**: Dado un array de números enteros, devuelve un array `output` tal que `output[i]` es igual al producto de todos los elementos de `nums` excepto `nums[i]`.
- **Entrada**: Un array de enteros.
- **Salida**: Un array de enteros con los productos.

### Ejemplo:
- **Entrada**: `[1, 2, 3, 4]`
- **Salida**: `[24, 12, 8, 6]`

## 3. Buscar el primer número que falta en una secuencia ordenada
- **Descripción**: Dado un array de números enteros que representa una secuencia ordenada, pero con algunos números faltantes, encuentra el primer número que falta en la secuencia.
- **Entrada**: Un array de enteros ordenados y sin repetidos.
- **Salida**: Un entero que representa el primer número faltante en la secuencia.

### Ejemplo:
- **Entrada**: `[1, 2, 3, 5, 6]`
- **Salida**: `4`

## 4. Inversión de una expresión matemática
- **Descripción**: Dada una expresión matemática en forma de cadena que contiene números, operadores (`+`, `-`, `*`, `/`) y paréntesis, invierte la expresión respetando la precedencia de operadores.
- **Entrada**: Una cadena que representa la expresión matemática.
- **Salida**: Una cadena con la expresión matemática invertida.

### Ejemplo:
- **Entrada**: `"3 + (2 * 5)"`
- **Salida**: `"(5 * 2) + 3"`

## 5. Primera ocurrencia de un carácter no repetido en una cadena
- **Descripción**: Dada una cadena, encuentra el primer carácter que no se repite y devuelve su índice. Si no existe, devuelve -1.
- **Entrada**: Una cadena de caracteres.
- **Salida**: El índice del primer carácter no repetido o -1 si no hay ninguno.

### Ejemplo:
- **Entrada**: `"([{}])"`
- **Salida**: `-1`

## 6. Enunciado: Máximo Producto de una Subcadena
- **Descripción**: Dada una cadena de números enteros positivos representada como una cadena de caracteres, encuentra el máximo producto de una subcadena de longitud k. La subcadena puede ser cualquier subsecuencia continua dentro de la cadena original.

- **Entrada**:

  - Una cadena str que contiene solo dígitos (0-9).
  - Un entero k que representa la longitud de la subcadena.

- **Salida**:
  - Un entero que representa el máximo producto de una subcadena de longitud k.

- **Ejemplo**
  - Entrada:
    - str = "123456789"
    - k = 3
  - Salida: 504
  - Explicación: Las posibles subcadenas de longitud 3 son "123", "234", "345", "456", "567", "678", y "789". Los productos correspondientes son 6, 24, 60, 120, 210, 336, y 504. El máximo es 504.
 
- **Restricciones**:
  - La longitud de la cadena str será al menos k y no excederá los 1000 caracteres.
  - k será un entero positivo menor o igual a la longitud de str.