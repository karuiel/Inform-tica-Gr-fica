#ifndef MALLAIND_HPP
#define MALLAIND_HPP

#include "Objeto3D.hpp"
#include <vector>
#include "aux.hpp"
#include "tuplasg.hpp"
#include <string>
class MallaInd : public Objeto3D
{
	protected:
		int tam1,tam2;
		//declarar aquí tablas de vértices y caras
		std::vector<Tupla3i> caras;
		std::vector<Tupla3f> vertices;
		std::vector<Tupla3i> caras2;
		std::vector<Tupla3f> normalCaras;
		std::vector<Tupla3f> normalVertices;
		std::vector<Tupla2f> textura;
	public:
		virtual void visualizarGL( ContextoVis & cv ) ;
		void calcularNormales();
} ;
#endif