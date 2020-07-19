#ifndef ROBOT_HPP
#define ROBOT_HPP
#include "aux.hpp"
#include "Cabeza.hpp"
#include "BrazoIzquierdo.hpp"
#include "BrazoDerecho.hpp"
#include "PiernaDerecha.hpp"
#include "PiernaIzquierda.hpp"
#include "NodoGrafoEscena.hpp"

class Robot : public NodoGrafoEscena {
  public:
    Robot();
    void Desplazarse(float k);
    void GirarExtremidades(float k);
    void GirarCabeza(float j);
  };

#endif