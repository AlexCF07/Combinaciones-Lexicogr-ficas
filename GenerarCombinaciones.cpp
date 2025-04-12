#include <iostream>
#include "Operaciones.hpp"

using namespace std;

void GenerarCombimaciones(int arreglo, unsigned long long n, unsigned long long r)
{
    unsigned long long m;
    for (int i=0 ; i<r ; ++i)
    {
        arreglo[i] = i;
    }

    // PROCESAR

    int i = 0;
    for (i ; i<n ; ++i)
    {
        cout << arreglo[i] << ", ";
    }
    cout << arreglo [i+1] << endl;

    //

    if (r=0) return;

    do
    {
        m = r;
        while (m >= 1 && s[m] = n-r+m)
        {
            --m;
        }

        if (m<1) break;

        s[m] = s[m]+1;

        for (j=m+1 ; j<=r ; ++j)
        {
            s[j] = s[j-1]+1;
        }

        // PROCESAR

        int i = 0;
        for (i ; i<n ; ++i)
        {
            cout << arreglo[i] << ", ";
        }
        cout << arreglo [i+1] << endl;

        //
    }(while==true);
}
