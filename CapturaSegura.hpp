#ifndef CAPTURASEGURA_HPP_INCLUDED
#define CAPTURASEGURA_HPP_INCLUDED


/** \brief Captura de forma segura un numero
 *
 * \tparam T Tipo de numero a capturar
 *
 * \param n Numero a capturar
 * \param seleccion Mensaje de solicitud del numero a capturar
 * \return Nada
 *
 */
template <typename T>
void CapturarNumero(T &n,const char seleccion[]);

#include "CapturaSegura.tpp"

#endif // CAPTURASEGURA_HPP_INCLUDED
