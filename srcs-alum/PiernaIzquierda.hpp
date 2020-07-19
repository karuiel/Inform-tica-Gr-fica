
#ifndef PIERNAIZQUIERDA_HPP
#define PIERNAIZQUIERDA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "practica1.hpp"

class PiernaIzquierda : public NodoGrafoEscena {
  public:
    PiernaIzquierda();
    void Girar(float k);
  };

#endif