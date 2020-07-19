#ifndef MALLAREVOL_HPP
#define MALLAREVOL_HPP
#define PI 3.141592653
  #include "file_ply_stl.hpp"
  #include "MallaInd.hpp"
#include <string>
  // clase mallas indexadas obtenidas de un archivo PLY
  class MallaRevol : public MallaInd
  {
     public:
        // constructor
        // se debe especificar el nombre completo del archivo a leer
        //                      el número de copias del perfil
        MallaRevol(const std::string & nombre_arch, const unsigned nperfiles,const bool crear_tapas, const bool cerrar_malla,bool textura) ;
  } ;

#endif