# Combinaciones-Lexicogr-ficas
Programa para generar combinaciones lexicográficas para conjuntos de tamaño n y combinaciones de r elementos. 

# Generador de r-Combinaciones en Orden Lexicográfico

## Título y Descripción
Este proyecto genera todas las r-combinaciones posibles de un conjunto de n elementos en orden lexicográfico, guardando los resultados en un archivo CSV. Además, verifica que el número de combinaciones generadas coincida con el cálculo teórico de combinaciones C(n,r).

## Autor(a)
[Nombre del estudiante]

## Requisitos del sistema
- Compilador C++ compatible con C++17 (para usar `<filesystem>`)
- Sistema operativo Windows/Linux/macOS

## Instrucciones de compilación y ejecución
1. Compilar el programa:
   ```
   g++ main.cpp Operaciones.cpp -o combinaciones -std=c++17
   ```
2. Ejecutar el programa:
   ```
   ./combinaciones
   ```
3. Seguir las instrucciones para ingresar los valores de n y r.

## Explicación del algoritmo
El algoritmo implementado sigue estos pasos:
1. Inicializa un arreglo con los primeros r índices (0, 1, 2, ..., r-1)
2. Genera la siguiente combinación encontrando el índice más a la derecha que puede incrementarse
3. Incrementa ese índice y ajusta todos los índices a su derecha
4. Repite el proceso hasta que no se puedan generar más combinaciones

Este método asegura que cada combinación se genere exactamente una vez y en orden lexicográfico.

## Orden Lexicográfico
El orden lexicográfico para combinaciones es similar al orden alfabético, donde cada combinación se trata como una secuencia ordenada. Por ejemplo, para n=4 y r=2:
1. (0, 1)
2. (0, 2)
3. (0, 3)
4. (1, 2)
5. (1, 3)
6. (2, 3)

El algoritmo asegura este orden generando siempre la siguiente combinación que sería mayor en este orden.

## Validación de entrada
El programa valida que:
- n sea un entero mayor o igual a 1 (n ≥ 1)
- r sea un entero entre 0 y n inclusive (0 ≤ r ≤ n)
- Los valores ingresados sean numéricos (no permite caracteres)

## Formato de salida
El programa genera un archivo CSV (`combinaciones.csv`) con:
1. Cada combinación en una línea separada, con elementos separados por comas
2. Al final del archivo, dos líneas adicionales:
   - "Comb. Calc:" seguido del número calculado de combinaciones C(n,r)
   - "Comb. Gen:" seguido del número real de combinaciones generadas

## Verificación C(n,r)
El programa realiza una verificación importante:
1. Calcula teóricamente el número de combinaciones usando la fórmula C(n,r) = n!/((n-r)!·r!)
2. Cuenta las combinaciones realmente generadas
3. Compara ambos valores e informa si coinciden
4. Esta verificación garantiza que el algoritmo generó exactamente todas las combinaciones posibles sin repeticiones ni omisiones
