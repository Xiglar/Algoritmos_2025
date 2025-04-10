def quick_sort(arr):
    # Implementa aquí el algoritmo de Quick Sort
    pass


def test_quick_sort():
    # Prueba con una lista vacía
    assert quick_sort([]) == [], "Error: lista vacía no pasó la prueba"

    # Prueba con una lista de un solo elemento
    assert quick_sort([1]) == [1], "Error: lista con un solo elemento no pasó la prueba"

    # Prueba con una lista de elementos repetidos
    assert quick_sort([5, 5, 5, 5]) == [5, 5, 5, 5], "Error: lista con elementos repetidos no pasó la prueba"

    # Prueba con una lista de elementos en orden ascendente
    assert quick_sort([1, 2, 3, 4, 5]) == [1, 2, 3, 4, 5], "Error: lista ordenada ascendentemente no pasó la prueba"

    # Prueba con una lista de elementos en orden descendente
    assert quick_sort([5, 4, 3, 2, 1]) == [1, 2, 3, 4, 5], "Error: lista ordenada descendentemente no pasó la prueba"

    # Prueba con una lista de elementos en orden aleatorio
    assert quick_sort([3, 6, 8, 10, 1, 2, 1]) == [1, 1, 2, 3, 6, 8, 10], "Error: lista desordenada no pasó la prueba"

    # Prueba con una lista de elementos negativos y positivos
    assert quick_sort([-3, -1, -7, 4, 2, 0, -2]) == [-7, -3, -2, -1, 0, 2, 4], "Error: lista con elementos negativos no pasó la prueba"

    print("¡Todas las pruebas pasaron!")


if __name__ == "__main__":
    test_quick_sort()
