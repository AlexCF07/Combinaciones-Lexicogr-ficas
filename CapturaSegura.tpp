#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;

template <typename T>
void CapturarNumero(T &n,const char seleccion[])
{
    cout << seleccion;
    cin >> n;
    while(cin.fail()){
      cin.clear();
      cin.ignore(numeric_limits<int>::max(),'\n');
      cout << "ERROR: Se espera un numero" << endl;
      cout << seleccion;
      cin >> n;
    }
}

