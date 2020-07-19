#include "MaterialesP4.hpp"

MaterialBlanco::MaterialBlanco(){
  textura=NULL;
  color[0]=Tupla4f(0.5,0.5,0.5,1.0);
  color[1]=Tupla4f(0.05,0.05,0.05,1.0);
  color[2]=Tupla4f(0.2,0.2,0.2,1.0);
  color[3]=Tupla4f(0.0,0.0,0.0,0.0);
  exponente=5;
}

MaterialNegro::MaterialNegro(){
  textura=NULL;
  color[0]=Tupla4f(0.0, 0.0, 0.0, 1.0);
  color[1]=Tupla4f(0.0, 0.0, 0.0, 1.0);
  color[2]=Tupla4f(0.01,0.01,0.01,1.0);
  color[3]=Tupla4f(0.7,0.7,0.7,1.0);
  exponente=5;
}
MaterialMadera::MaterialMadera(){
  textura = new Textura("../imgs/text-madera.jpg",2);
  color[0]=Tupla4f(0.3,0.3,0.3,1.0);
  color[1]=Tupla4f(0.05,0.05,0.05,1.0);
  color[2]=Tupla4f(0.7,0.7,0.7,1.0);
  color[3]=Tupla4f(1.0,1.0,1.0,1.0);
  exponente=6;
}
MaterialLataPcuerpo::MaterialLataPcuerpo(){
  textura = new Textura("../imgs/lata-coke.jpg",0);
  color[0]=Tupla4f(0.2,0.2,0.2,1.0);
  color[1]=Tupla4f(0.02,0.02,0.02,1.0);
  color[2]=Tupla4f(0.4,0.4,0.4,1.0);
  color[3]=Tupla4f(1.0,1.0,1.0,1.0);
  exponente=5;
}
MaterialTapasLata::MaterialTapasLata(){
  textura = NULL;
  color[0]=Tupla4f(0.3,0.3,0.3,1.0);
  color[1]=Tupla4f(0.03,0.03,0.03,1.0);
  color[2]=Tupla4f(0.3,0.3,0.3,1.0);
  color[3]=Tupla4f(1.0,1.0,1.0,1.0);
  exponente=1;
}