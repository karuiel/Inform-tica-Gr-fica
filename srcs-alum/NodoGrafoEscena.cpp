#include "NodoGrafoEscena.hpp"


void NodoGrafoEscena::visualizarGL(ContextoVis & cv){
  int count=0;
  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPushMatrix() ; // guarda modelview actual
// recorrer todas las entradas del array que hay en el nodo:
  for( unsigned i = 0 ; i < entradas.size() ; i++ ){
    if( entradas[i].tipoE == 0 ){ // si la entrada es sub-objeto:

      entradas[i].objeto->visualizarGL(cv);
    }else if(entradas[i].tipoE==2){     
      cv.pilaMateriales->activarMaterial(entradas[i].material);
      cv.pilaMateriales->push();
      count++;      
    }else{
      glMatrixMode( GL_MODELVIEW );
      glMultMatrixf( *(entradas[i].matriz) ); // componerla
    }
    
  }
  for(int i=0;i<count;i++){
  cv.pilaMateriales->pop();
  }

  glMatrixMode( GL_MODELVIEW ); // operaremos sobre la modelview
  glPopMatrix();
}

void NodoGrafoEscena::agregar( Objeto3D * objeto ){
  entradas.push_back(EntradaNGE(objeto));
}
void NodoGrafoEscena::agregar( Material * material ){
  entradas.push_back(EntradaNGE(material));
}
void NodoGrafoEscena::agregar( const Matriz4f & pMatriz ){
  entradas.push_back(EntradaNGE(pMatriz));
}