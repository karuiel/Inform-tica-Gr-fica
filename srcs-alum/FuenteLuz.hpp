#include "tuplasg.hpp"
#include "aux.hpp"

#ifndef FUENTELUZ_HPP
#define FUENTELUZ_HPP

class FuenteLuz
{
public:
Tupla4f posvec ; 		// posición (si w=1) o vector de dirección (si w=0)
Tupla4f colores[3] ; 	// colores: 0=ambiental, 1=difuso, 2=especular.
float longi,lati; 		// ángulos de rotación (si direccional)

void activar( int i );  // activarla (con ident. OpenGL GL_LIGHT0+i)
} ;

#endif