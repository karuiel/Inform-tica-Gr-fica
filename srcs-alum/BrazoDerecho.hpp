#ifndef BRAZODERECHO_HPP
#define BRAZODERECHO_HPP
#include "aux.hpp"
#include "NodoGrafoEscena.hpp"
#include "practica1.hpp"

class BrazoDerecho : public NodoGrafoEscena {
  public:
    BrazoDerecho();
    void Girar(float k);
  };

#endif