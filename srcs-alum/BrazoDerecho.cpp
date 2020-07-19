#include "BrazoDerecho.hpp"


BrazoDerecho::BrazoDerecho(){
  std::vector<Tupla3f> verticesBrazoD;
  Tupla3f v0(3,10,-1), v1(3,10,1), v2(2,10,1), v3(2,10,-1),
  v4(3,6,-1), v5(3,6,1), v6(2,6,1), v7(2,6,-1);
  verticesBrazoD.push_back(v0);
  verticesBrazoD.push_back(v1);
  verticesBrazoD.push_back(v2);
  verticesBrazoD.push_back(v3);
  verticesBrazoD.push_back(v4);
  verticesBrazoD.push_back(v5);
  verticesBrazoD.push_back(v6);
  verticesBrazoD.push_back(v7);

  agregar(MAT_Traslacion(0,10,0));
  agregar (MAT_Rotacion(0,1,0,0));
  agregar(MAT_Traslacion(0,-10,0));
  agregar(new Cubo(verticesBrazoD));

}

void BrazoDerecho::Girar(float k){
  *entradas[1].matriz= MAT_Rotacion(k,1,0,0);
}