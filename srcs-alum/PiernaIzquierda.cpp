#include "PiernaIzquierda.hpp"

PiernaIzquierda::PiernaIzquierda(){
  std::vector<Tupla3f> verticesPiernaI;
  Tupla3f v0(0,4,-1), v1(0,4,1), v2(-2,4,1), v3(-2,4,-1),
  v4(0,0,-1), v5(0,0,1), v6(-2,0,1), v7(-2,0,-1);
  verticesPiernaI.push_back(v0);
  verticesPiernaI.push_back(v1);
  verticesPiernaI.push_back(v2);
  verticesPiernaI.push_back(v3);
  verticesPiernaI.push_back(v4);
  verticesPiernaI.push_back(v5);
  verticesPiernaI.push_back(v6);
  verticesPiernaI.push_back(v7);

  agregar(MAT_Traslacion(0,4,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(MAT_Traslacion(0,-4,0));
  agregar(new Cubo(verticesPiernaI));
}

void PiernaIzquierda::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}