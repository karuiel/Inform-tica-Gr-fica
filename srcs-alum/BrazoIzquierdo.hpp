#ifndef BRAZOIZQUIERDO_HPP
#define BRAZOIZQUIERDO_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "practica1.hpp"

class BrazoIzquierdo : public NodoGrafoEscena {
  public:
    BrazoIzquierdo();
    void Girar(float k);
  };

#endif