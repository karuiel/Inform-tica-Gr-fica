// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Práctica 1  (implementación)
// **
// *********************************************************************

#include "aux.hpp"
#include "tuplasg.hpp"   // Tupla3f
#include "practicas.hpp"
#include "practica1.hpp"
#include <iostream>

unsigned objeto_activo = 0 ; // objeto activo: cubo (0), tetraedro (1), otros....

// ---------------------------------------------------------------------
// declaraciones de estructuras de datos....
Cubo *cubo;
Tetraedro *tetraedro;


// ---------------------------------------------------------------------
// Función para implementar en la práctica 1 para inicialización.
// Se llama una vez al inicio, cuando ya se ha creado la ventana e
// incializado OpenGL.

void P1_Inicializar( int argc, char *argv[] )
{
	cubo = new Cubo();
	tetraedro = new Tetraedro();

}

// ---------------------------------------------------------------------
// Función invocada al pulsar una tecla con la práctica 1 activa:
// (si la tecla no se procesa en el 'main').
//
//  - devuelve 'true' si la tecla se usa en esta práctica para cambiar
//    entre el cubo, el tetraedro u otros objetos (cambia el valor de
//    'objeto_activo').
//  - devuelve 'false' si la tecla no se usa en esta práctica (no ha
//    cambiado nada)

bool P1_FGE_PulsarTeclaNormal( unsigned char tecla )
{

	if (std::toupper(tecla)=='O'){
		objeto_activo=(objeto_activo+1)%2;
	}else{
		return false ;
	}
   
}


// ---------------------------------------------------------------------
// Función a implementar en la práctica 1  para dibujar los objetos
// se debe de usar el modo de dibujo que hay en el parámetro 'cv'
// (se accede con 'cv.modoVisu')

void P1_DibujarObjetos( ContextoVis & cv )
{
	if(objeto_activo==0){
		cubo->visualizarGL(cv);
	}else{
		if(objeto_activo==1){
			tetraedro->visualizarGL(cv);
		}
	}

}

Cubo::Cubo(){

	nombre_obj="Cubo";
	Tupla3f v0(-1,1,1), v1(1,1,1), v2(1,1,-1), v3(-1,1,-1),
			v4(-1,-1,1), v5(1,-1,1), v6(1,-1,-1), v7(-1,-1,-1);

	vertices.push_back(v0);
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);
	vertices.push_back(v5);
	vertices.push_back(v6);
	vertices.push_back(v7);

	Tupla3i tri1(4,1,0), tri2(4,5,1), tri3(5,2,1), tri4(5,6,2),
			tri5(6,3,2), tri6(6,7,3), tri7(7,0,3), tri8(7,4,0),
			tri9(0,2,3), tri10(0,1,2), tri11(4,6,7), tri12(4,5,6);
	
	caras.push_back(tri1);
	caras.push_back(tri2);
	caras.push_back(tri3);
	caras.push_back(tri4);
	caras.push_back(tri5);
	caras.push_back(tri6);
	caras.push_back(tri7);
	caras.push_back(tri8);
	caras.push_back(tri9);
	caras.push_back(tri10);
	caras.push_back(tri11);
	caras.push_back(tri12);
}

Cubo::Cubo(std::vector<Tupla3f> vertices2){

	vertices=vertices2;

	Tupla3i tri1(4,1,0), tri2(4,5,1), tri3(5,2,1), tri4(5,6,2),
			tri5(6,3,2), tri6(6,7,3), tri7(7,0,3), tri8(7,4,0),
			tri9(0,2,3), tri10(0,1,2), tri11(4,6,7), tri12(4,5,6);
	
	caras.push_back(tri1);
	caras.push_back(tri2);
	caras.push_back(tri3);
	caras.push_back(tri4);
	caras.push_back(tri5);
	caras.push_back(tri6);
	caras.push_back(tri7);
	caras.push_back(tri8);
	caras.push_back(tri9);
	caras.push_back(tri10);
	caras.push_back(tri11);
	caras.push_back(tri12);
}


Tetraedro::Tetraedro(){
	nombre_obj="Tetraedro";
		Tupla3f v0(0,0,1), v1(1,0,0), v2(0,0,-1), v3(0,1,0);

		vertices.push_back(v0);
		vertices.push_back(v1);
		vertices.push_back(v2);
		vertices.push_back(v3);

		Tupla3i tri1(0,1,3), tri2(1,2,3), tri3(0,2,3), tri4(0,1,2);
		
		caras.push_back(tri1);
		caras.push_back(tri2);
		caras.push_back(tri3);
		caras.push_back(tri4);
}
