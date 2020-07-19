#ifndef PIERNADERECHA_HPP
#define PIERNADERECHA_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "practica1.hpp"

class PiernaDerecha : public NodoGrafoEscena {
  public:
    PiernaDerecha();
    void Girar(float k);
  };

#endif