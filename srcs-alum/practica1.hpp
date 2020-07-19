// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (declaraciones públicas)
// **
// *********************************************************************

#ifndef IG_PRACTICA1_HPP
#define IG_PRACTICA1_HPP

#include "MallaInd.hpp"

class Cubo : public MallaInd
{
	public:
	Cubo() ; // crea las tablas del cubo, y le da nombre.
	Cubo(std::vector<Tupla3f> vertices2) ;
};

class Tetraedro : public MallaInd
{
	public:
	Tetraedro() ; // crea las tablas del cubo, y le da nombre.

};

void P1_Inicializar( int argc, char *argv[] ) ;
bool P1_FGE_PulsarTeclaNormal(  unsigned char tecla ) ;
void P1_DibujarObjetos( ContextoVis & cv ) ;

#endif
