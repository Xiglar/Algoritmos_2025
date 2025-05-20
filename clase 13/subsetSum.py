
#funcion que devuelve true si hay algun subconjuto de los elementos del vector que suma target
def subsetSumEasy(vector, target):
    if (sum(vector) < target): 
        return False
    if(target < 0):
        return False
    if(target ==0): 
        return True
    if len(vector) == 0 and target == 0:
        return True
    elif len(vector) == 0 and target != 0: 
        return False
    return subsetSumEasy(vector[1:], target-vector[0]) or subsetSumEasy(vector[1:], target) 


#funcion que devuelve los subconjuntos de los elementos del vector que suman target
#en ans deben guardar las soluciones parciales, empieza como un vector vacío
def subsetSumHard(vector, target, ans):
    if(len(vector) == 0):
        if(target == 0):
            return ans
        return []

    withCurrent = subsetSumHard(vector[1:], target - vector[0], ans + [vector[0]])
    withoutCurrent = subsetSumHard(vector[1:], target , ans)
    return withCurrent + withoutCurrent

def get_input_vector():
    while True:
        try:
            entrada = input("Introduce los números del vector separados por espacio: ")
            vector = list(map(int, entrada.strip().split()))
            return vector
        except ValueError:
            print("Entrada no válida. Asegúrate de escribir solo números enteros separados por espacio.")

def get_target():
    while True:
        try:
            target = int(input("Introduce el valor objetivo: "))
            return target
        except ValueError:
            print("Entrada no válida. Por favor, introduce un número entero.")

vector = get_input_vector()
target = get_target()

resultado = subsetSumEasy(vector, target)
print(f"La respuesta de subsetSumEasy es {resultado}")

resultado = subsetSumHard(vector, target, [])
print(f"La respuesta de subsetSumHard es {resultado}")
