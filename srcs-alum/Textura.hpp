#ifndef TEXTURA_HPP
  #define TEXTURA_HPP
  #include <iostream>
  #include <string>
  #include "aux.hpp"
  #include "tuplasg.hpp"
  #include "jpg_imagen.hpp"
  #include "practicas.hpp"

  using namespace std ;

class Textura
{
  public:
   GLuint        id_text ;    
   jpg::Imagen * img ;        
   unsigned      mgct ;       
   float         cs[4],ct[4]; 

   void Activar();          
   Textura(string archivoJPG,unsigned a) ; // crea un textura a partir de un archivo
};

#endif