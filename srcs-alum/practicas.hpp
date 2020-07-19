// *********************************************************************
// **
// ** Informática Gráfica, curso 2016-17
// ** Declaraciones públicas auxiliares, comunes a todas las prácticas
// **
// *********************************************************************

#ifndef IG_PRACTICAS_HPP
#define IG_PRACTICAS_HPP
#include "Material.hpp"
#include <vector>
// ---------------------------------------------------------------------
// tipo de datos enumerado para los modos de visualización:

typedef enum
{
   modoPuntos,
   modoAlambre,
   modoSolido,
   modoAjedrez,
   modoIluPlano,
   modoIluSuave
}
   ModosVisu;

const int numModosVisu = 5 ; // numero de modos distintos

// --------------------------------------------------------------------
class PilaMateriales
{
   private:
   Material * actual ; // material actualmente activado (NULL al inicio)
   std::vector<Material *> pila ; // materiales activados antes
   public:
   PilaMateriales(){
      actual=NULL;
   } // pone actual a NULL, pila está vacía
   void push(){
      if(actual!=NULL)
      pila.push_back(actual);
   }
   // añade una copia de actual en el tope de pila
   void pop(){
      if(actual!=pila.back()){
         actual=pila.back();         
         actual->activar(); 
         pila.pop_back();        
      }      
   }
   // copia tope de pila en actual, elimina el tope, activa actual
   void activarMaterial( Material * material ){
      if((material!=NULL)&&material!=actual){
         actual= material;
         material->activar();
         
      }
   }
   // activa material y lo copia en actual
} ;
void FGE_Desocupado();
class ContextoVis
{
   public:
      PilaMateriales *pilaMateriales;
      ModosVisu modoVisu ; // modo de visualización actual
      ContextoVis() { modoVisu = modoAlambre;
         pilaMateriales=new PilaMateriales(); } // poner alambre por defecto
};

#endif