#ifndef MALLAPLY_HPP
#define MALLAPLY_HPP

//clase mallas indexadas obtenidas de un archivo PLY
 #include "file_ply_stl.hpp"
#include "MallaInd.hpp"
class MallaPLY : public MallaInd 
{

public:
//constructor
// se debe especificar el nombre completo del archivo a leer
MallaPLY( const std::string & nombre_arch ) ;
} ;
#endif