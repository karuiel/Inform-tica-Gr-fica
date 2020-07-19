#ifndef MATERIAL_HPP
  #define MATERIAL_HPP
  #include <iostream>
  #include <string>
  using namespace std ;

  // clase abstracta para Material
  class Material
  {
    public:
     virtual void activar() = 0 ;
  } ;
#endif