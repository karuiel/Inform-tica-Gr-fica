#include "Cabeza.hpp"

Cabeza::Cabeza(){
  std::vector<Tupla3f> verticesCabeza;
  Tupla3f v0(-1,12,1), v1(1,12,1), v2(1,12,-1), v3(-1,12,-1),
  v4(-1,10,1), v5(1,10,1), v6(1,10,-1), v7(-1,10,-1);
  	verticesCabeza.push_back(v0);
	verticesCabeza.push_back(v1);
	verticesCabeza.push_back(v2);
	verticesCabeza.push_back(v3);
	verticesCabeza.push_back(v4);
	verticesCabeza.push_back(v5);
	verticesCabeza.push_back(v6);
	verticesCabeza.push_back(v7);



  agregar (MAT_Rotacion(0,0,1,0));
  agregar(new Cubo(verticesCabeza));

}

void Cabeza::Girar(float k){
  *entradas[0].matriz= MAT_Rotacion(k,0,1,0);
}