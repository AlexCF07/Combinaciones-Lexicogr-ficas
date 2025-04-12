#ifndef OPERACIONES_HPP
#define OPERACIONES_HPP
#include <fstream>

unsigned long long Factorial (unsigned long long num);
int Combinacion(unsigned long long n, unsigned long long r, std::ofstream& archivo);
void CapturarElementos(int arreglo[], unsigned long long tam);
void ImprimirElementos(int arreglo[], unsigned long long tam, int indice[], std::ofstream& archivo);
int GenerarCombinaciones(int arreglo[], unsigned long long n, unsigned long long r, std::ofstream& archivo);

#endif
