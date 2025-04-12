#include <iostream>
#include <fstream>  // Se añade para manejo de archivos
#include "CapturaSegura.hpp"
#include "Operaciones.cpp"
#include <filesystem> // Se añade para obtener la ruta completa del archivo

using namespace std;

int main()
{
    unsigned long long n = 0;
    unsigned long long r = 0;

    // Solicitar y validar el valor de n (debe ser > 0)
    while(n <= 0)
    {
        CapturarNumero(n, "Introduce la cantidad de elementos n (entero n >= 1): ");
        if (n <= 0)
        {
            cout << "ERROR: Se espera un valor > 0" << endl;
            n = 0;
        }
    }

    // Solicitar y validar el valor de r (debe estar entre 1 y n)
    while(r == 0 || r > n)
    {
        CapturarNumero(r, "Introduce la cantidad combinaciones r (entero n > r > 0): ");
        if (r == n || r < 0)
        {
            cout << "ERROR: Se espera un valor entre 0 y " << n << endl;
        }
    }

    int arreglo[n];

    // Definir nombre del archivo
    const string nombreArchivo = "combinaciones.csv";

    // Abrir archivo CSV
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al crear el archivo CSV" << endl;
        return 1;
    }

    // Calcular combinaciones y guardar en CSV
    int CombCalc = Combinacion(n, r, archivo);

    // Generar combinaciones y guardar en CSV
    int CombGen = GenerarCombinaciones(arreglo, n, r, archivo);

    // Cerrar el archivo
    archivo.close();

    // Obtener y mostrar la ruta completa del archivo
    filesystem::path rutaCompleta = filesystem::absolute(nombreArchivo);


    cout << "\nCombinaciones generadas: " << CombGen << endl;
    cout << "Combinaciones calculadas: " << CombCalc << endl;
    cout << ((CombGen == CombCalc) ? "Ambos valores coinciden" : "Dichos valores difieren") << endl;
    cout << "Las combinaciones se han guardado exitosamente en:" << endl <<  rutaCompleta.string() << endl;

    return 0;
}
