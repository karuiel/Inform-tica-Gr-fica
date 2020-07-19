#include "BrazoIzquierdo.hpp"

BrazoIzquierdo::BrazoIzquierdo(){
  std::vector<Tupla3f> verticesBrazoI;
  Tupla3f v0(-2,10,-1), v1(-2,10,1), v2(-3,10,1), v3(-3,10,-1),
  v4(-2,6,-1), v5(-2,6,1), v6(-3,6,1), v7(-3,6,-1);
  verticesBrazoI.push_back(v0);
  verticesBrazoI.push_back(v1);
  verticesBrazoI.push_back(v2);
  verticesBrazoI.push_back(v3);
  verticesBrazoI.push_back(v4);
  verticesBrazoI.push_back(v5);
  verticesBrazoI.push_back(v6);
  verticesBrazoI.push_back(v7);

  agregar(MAT_Traslacion(0,10,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(MAT_Traslacion(0,-10,0));
  agregar(new Cubo(verticesBrazoI));


}

void BrazoIzquierdo::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}