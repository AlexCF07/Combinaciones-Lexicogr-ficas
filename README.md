# 🚀 Generador de Combinaciones en Orden Lexicográfico
Este programa genera todas las posibles r-combinaciones de un conjunto de n elementos en orden lexicográfico, implementando un algoritmo eficiente. Además, calcula el número teórico de combinaciones C(n,r) mediante fórmula factorial y verifica que coincida con el conteo real de combinaciones generadas.

## 👤 Autor(
Alejandro Cordero Fraga

## ⚙️ Requisitos del Sistema
- Compilador C++17 (g++ 9.0+ o equivalente)
- Sistema operativo: Windows/Linux/macOS
- Bibliotecas estándar de C++17

## 🛠️ Compilación y Ejecución

### Windows

1. **Preparación del entorno**:
   - Instalar [MinGW-w64](https://www.mingw-w64.org/) con soporte para C++17
   - Asegurar que `g++.exe` esté en el PATH del sistema

2. **Compilación** (ejecutar en PowerShell o CMD):
   ```powershell
   g++ -std=c++17 main.cpp Operaciones.cpp -o generador_combinaciones.exe
   ```

3. **Ejecución**:
   ```powershell
   .\generador_combinaciones.exe
   ```

4. **Requisitos adicionales**:
   - Habilitar ejecución de scripts si aparece error de políticas
   - Tener permisos de escritura en el directorio de trabajo

### Linux

1. **Instalación de dependencias** (Ubuntu/Debian):
   ```bash
   sudo apt update && sudo apt install g++ build-essential
   ```

2. **Compilación**:
   ```bash
   g++ -std=c++17 main.cpp Operaciones.cpp -o generador_combinaciones
   ```

3. **Dar permisos de ejecución**:
   ```bash
   chmod +x generador_combinaciones
   ```

4. **Ejecución**:
   ```bash
   ./generador_combinaciones
   ```

5. **Notas para Linux**:
   - El comando `ls` debe mostrar los archivos `.cpp` y `.hpp`
   - Si falta algún archivo, verificar la ruta de descarga
   - Para ver el archivo CSV generado: `libreoffice --calc combinaciones.csv`

El programa solicitará:
1. El valor de n (número total de elementos, n ≥ 1)
2. El valor de r (tamaño de cada combinación, 0 ≤ r ≤ n)

## 🧠 Explicación del Algoritmo

El algoritmo implementado sigue estos pasos:
1. Inicializa un arreglo con los primeros r índices en orden ascendente
2. Genera la primera combinación
3. Encuentra el índice más a la derecha que puede incrementarse
4. Incrementa ese índice y ajusta los índices siguientes
5. Repite hasta que no se puedan generar más combinaciones

**Complejidad**: O(C(n,r)) - Genera exactamente una combinación por iteración

## 📚 Orden Lexicográfico

En el contexto de combinaciones, el orden lexicográfico:
- Considera las combinaciones como "palabras" donde cada elemento es un "carácter"
- Ordena de menor a mayor como en un diccionario
- Ejemplo para n=5, r=3:  
  `0,1,2` → `0,1,3` → `0,1,4` → `0,2,3` → ... → `2,3,4`

El algoritmo asegura este orden al:
1. Siempre incrementar el índice más a la derecha posible
2. Ajustar los índices siguientes en secuencia ascendente

## ✔️ Validación de Entrada

El programa verifica:
1. `n ≥ 1` (debe tener al menos un elemento)
2. `0 ≤ r ≤ n` (r dentro de límites válidos)
3. Entradas numéricas (rechaza caracteres no válidos)

Mensajes de error específicos guían al usuario para correcciones.

## 📄 Formato de Salida

El archivo `combinaciones.csv` contiene:
1. Todas las combinaciones generadas (una por línea)
   - Elementos separados por comas
   - Ejemplo: `0,1,2`
2. Al final del archivo:
   - `Comb. Gen:[total]` (combinaciones generadas)
   - `Comb. Calc:[total]` (combinaciones calculadas)

## 🔍 Verificación C(n,r)

El programa realiza dos cálculos independientes:
1. **Cálculo teórico**: Usa la fórmula combinatoria `C(n,r) = n!/(r!(n-r)!)`
2. **Conteo real**: Durante la generación de combinaciones

Al finalizar, compara ambos valores y reporta si coinciden, validando la corrección del algoritmo.
