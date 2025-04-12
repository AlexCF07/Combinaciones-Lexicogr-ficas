#include <iostream>
#include <fstream>  // Para manejo de archivos
#include "Operaciones.hpp"

using namespace std;

/*F*************************************************************/

unsigned long long Factorial (unsigned long long num)
{
    unsigned long long anterior(num);
    unsigned long long nuevo;
    for (unsigned long long i=num-1 ; i!=0 ; i--)
    {
        nuevo = anterior*i;
        anterior = nuevo;
    }
    return nuevo;
}

/*F*************************************************************/

int Combinacion(unsigned long long n, unsigned long long r, std::ofstream& archivo)
{
    unsigned long long comb = Factorial(n)/(Factorial(n-r)*Factorial(r));

    archivo << "Comb. Calc:" << "," << comb;
    archivo << endl;

    return comb;
}

// Función para inicializar el arreglo con valores secuenciales
void CapturarElementos (int arreglo[], unsigned long long tam)
{
    for (int i = 0; i < tam; ++i)
    {
        arreglo[i] = i;
    }
}

// Función modificada para escribir en archivo CSV en lugar de imprimir en consola
void ImprimirElementos (int arreglo[], unsigned long long tam, int indice[], ofstream& archivo)
{
    for (int i = 0; i < tam; ++i)
    {
        archivo << arreglo[indice[i]];  // Escribe en el archivo en lugar de cout
        if (i < tam-1) archivo << ",";  // Usa coma como separador para CSV
    }
    archivo << endl;  // Fin de línea para cada combinación
}

// Función principal modificada para aceptar el archivo como parámetro
int GenerarCombinaciones (int arreglo[], unsigned long long n, unsigned long long r, ofstream& archivo)
{
    int contador(1);
    int m;
    int s[r];

    // Inicializar el arreglo con valores de 0 a n-1
    for (int i = 0; i < n; ++i)
    {
        arreglo[i] = i;
    }

    // Inicializar con los primeros r índices (0-based)
    CapturarElementos(s, r);

    // Procesar la primera combinación (escribe en archivo)
    ImprimirElementos(arreglo, r, s, archivo);


    if (r == 0)
    {
        return 0;  // Caso especial sin combinaciones
    }

    // Generar las combinaciones restantes
    do
    {
        // Encontrar el índice más a la derecha que puede incrementarse
        m = r - 1;
        while (m >= 0 && s[m] == n - r + m)
        {
            m--;
        }

        if (m < 0)
        {
            break;  // Todas las combinaciones han sido generadas
        }

        // Incrementar el índice en la posición m
        s[m]++;

        // Actualizar los índices a la derecha de m
        for (int j = m + 1; j < r; ++j)
        {
            s[j] = s[j - 1] + 1;
        }

        // Procesar la nueva combinación (escribe en archivo)
        ImprimirElementos(arreglo, r, s, archivo);
        contador++;

    } while(true);
    archivo << "Comb. Gen:" << "," << contador;

    return contador;
}
