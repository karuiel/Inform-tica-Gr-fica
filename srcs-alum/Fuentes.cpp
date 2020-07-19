#include "Fuentes.hpp"

FuenteDireccional::FuenteDireccional( float alpha_inicial, float beta_inicial ){
  posvec = Tupla4f(0, 0, 0,0);
  longi=alpha_inicial;
  lati=beta_inicial;
  colores[0] = Tupla4f(0.9,0.9,0.9,1.0);
  colores[1] = Tupla4f(0.9,0.9,0.9,1.0);
  colores[2] = Tupla4f(0.9,0.9,0.9,1.0);
}
void FuenteDireccional::variarAngulo( unsigned angulo, float incremento ){
  if(angulo == 0)
    longi=longi+incremento;
  else
    lati = lati+incremento;
}

// colores: 0=ambiental, 1=difuso, 2=especular.
FuentePosicional::FuentePosicional( const Tupla3f & posicion ){
  posvec = Tupla4f(posicion[0], posicion[1], posicion[2], 1);
  colores[0] = Tupla4f(0.2,0.3,0.4,1.0);
  colores[1] = Tupla4f(0.2,0.3,0.4,1.0);
  colores[2] = Tupla4f(0.2,0.3,0.4,1.0);
}

ColeccionFuentesP4::ColeccionFuentesP4(){

}