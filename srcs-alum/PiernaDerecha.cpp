#include "PiernaDerecha.hpp"

PiernaDerecha::PiernaDerecha(){
  std::vector<Tupla3f> verticesPiernaD;
  Tupla3f v0(2,4,-1), v1(2,4,1), v2(0,4,1), v3(0,4,-1),
  v4(2,0,-1), v5(2,0,1), v6(0,0,1), v7(0,0,-1);
  verticesPiernaD.push_back(v0);
  verticesPiernaD.push_back(v1);
  verticesPiernaD.push_back(v2);
  verticesPiernaD.push_back(v3);
  verticesPiernaD.push_back(v4);
  verticesPiernaD.push_back(v5);
  verticesPiernaD.push_back(v6);
  verticesPiernaD.push_back(v7);

  agregar(MAT_Traslacion(0,4,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(MAT_Traslacion(0,-4,0));
  agregar(new Cubo(verticesPiernaD));
}

void PiernaDerecha::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}