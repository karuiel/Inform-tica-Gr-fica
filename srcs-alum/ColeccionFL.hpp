#include "aux.hpp"
#include "FuenteLuz.hpp"

#ifndef COLECCIONFL_HPP
#define COLECCIONFL_HPP

class ColeccionFL
{
  public:
   std::vector<FuenteLuz *> fuentes ;  // vector de fuentes de luz
   void activar(  ) ;                  // activa todas las fuentes de luz 
                                      
} ;

#endif