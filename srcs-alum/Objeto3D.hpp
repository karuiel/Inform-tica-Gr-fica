
#ifndef OBJETO3D_HPP
#define OBJETO3D_HPP
#include <string>
#include "practicas.hpp"

class Objeto3D
{
	protected:
		std::string nombre_obj ; // nombre asignado al objeto
	public:
	// visualizar el objeto con OpenGL
		virtual void visualizarGL( ContextoVis & cv ) = 0 ;
	// devuelve el nombre del objeto
		std::string nombre() ;
} ;

#endif