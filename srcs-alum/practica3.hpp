// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 3  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA3_HPP
#define IG_PRACTICA3_HPP

#include "Robot.hpp"

#include <iostream>
using namespace std;

void P3_Inicializar( int argc, char *argv[] ) ;
void P3_DibujarObjetos( ContextoVis & cv) ;
bool P3_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P3_Animacion();
bool P3_FGE_Desocupado ();

#endif