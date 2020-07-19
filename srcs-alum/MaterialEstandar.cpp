#include "MaterialEstandar.hpp"



void MaterialEstandar::activar(){
  
  glEnable( GL_LIGHTING );
  glEnable( GL_NORMALIZE );
  glDisable( GL_COLOR_MATERIAL );
  glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE );
  glLightModeli( GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR ) ;
  glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE );

    glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION,  this->color[0] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT,   this->color[1] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE,   this->color[2] );
    glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR,  this->color[3] );
    glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, exponente ) ;
    glDisable( GL_COLOR_MATERIAL );

    if( textura!=NULL ){
        textura->Activar();
     
    }
    else{
        glDisable( GL_TEXTURE_2D );
    }

}

bool MaterialEstandar::hayTextura(){
    return this->textura != NULL;
}