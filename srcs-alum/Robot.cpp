#include "Robot.hpp"
#include "NodoGrafoEscena.hpp"
#include "aux.hpp"
#include "MaterialesP4.hpp"
#include "ColeccionFL.hpp"
#include "Fuentes.hpp"
#include "FuenteLuz.hpp"
#include "NodoGrafoEscena.hpp"
Robot::Robot(){
  std::vector<Tupla3f> verticesCuerpo;
  Tupla3f v0(2,10,-1), v1(2,10,1), v2(-2,10,1), v3(-2,10,-1),
  v4(2,4,-1), v5(2,4,1), v6(-2,4,1), v7(-2,4,-1);
  verticesCuerpo.push_back(v0);
  verticesCuerpo.push_back(v1);
  verticesCuerpo.push_back(v2);
  verticesCuerpo.push_back(v3);
  verticesCuerpo.push_back(v4);
  verticesCuerpo.push_back(v5);
  verticesCuerpo.push_back(v6);
  verticesCuerpo.push_back(v7);
  


    
    agregar (MAT_Escalado(1,1,1));
    agregar (MAT_Traslacion(0,0,0));
    agregar(new MaterialTapasLata());
    agregar (new Cabeza());
    agregar(new MaterialBlanco());
    agregar (new Cubo(verticesCuerpo)); 
    agregar (new BrazoIzquierdo());
    agregar (new BrazoDerecho());
    agregar(new MaterialNegro());
    agregar (new PiernaIzquierda());
    agregar (new PiernaDerecha());
}

void Robot::Desplazarse(float k){
  *entradas[1].matriz= MAT_Traslacion(0,0,k/8);
}
void Robot::GirarExtremidades(float k){
  ((BrazoIzquierdo *)(entradas[6].objeto))->Girar(k);
  ((BrazoDerecho *)(entradas[7].objeto))->Girar(-k);
  ((PiernaIzquierda *)(entradas[9].objeto))->Girar(-k);
  ((PiernaDerecha *)(entradas[10].objeto))->Girar(k);
}

void Robot::GirarCabeza(float j){
  ((Cabeza *)(entradas[3].objeto))->Girar(j);
}