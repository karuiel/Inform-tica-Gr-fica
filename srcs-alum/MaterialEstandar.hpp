#ifndef MATERIALESTANDAR_HPP
  #define MATERIALESTANDAR_HPP
  #include <iostream>
  #include <string>
  #include "tuplasg.hpp"
#include "Textura.hpp"
#include "Material.hpp"
  using namespace std ;

  class MaterialEstandar  : public Material{
    public:
     Textura * textura=NULL ;       
     Tupla4f   color[4] ;    
     float     exponente ;   

    virtual void activar();
    bool hayTextura();
  } ;

#endif