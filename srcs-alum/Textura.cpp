#include "Textura.hpp"

  void Textura::Activar(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,id_text);


    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    if (mgct!=0){

    glEnable( GL_TEXTURE_GEN_S ); // desactivado inicialmente
    glEnable( GL_TEXTURE_GEN_T ); // desactivado inicialmente
    if(mgct==1){
      glTexGenfv( GL_S, GL_OBJECT_PLANE, cs ) ;
      glTexGenfv( GL_T, GL_OBJECT_PLANE, ct ) ;
    }
    else if(mgct==2){
      glTexGenfv( GL_S, GL_EYE_PLANE, cs ) ;
      glTexGenfv( GL_T, GL_EYE_PLANE, ct ) ;
    }
  }
  else{
     glDisable(GL_TEXTURE_GEN_S);
     glDisable(GL_TEXTURE_GEN_T);
  }
}

Textura::Textura(string archivoJPG,unsigned a )
{
  mgct=a;
  img=new jpg::Imagen(archivoJPG);
  if (mgct!=0){
        cs[0]=0.0;
        cs[1]=0.0;
        cs[2]=1.0;
        cs[3]=0.0;

        ct[0]=0.0;
        ct[1]=1.0;
        ct[2]=0.0;
        ct[3]=0.0;
}
glGenTextures(1,&id_text);
glBindTexture(GL_TEXTURE_2D,id_text);

glTexImage2D(GL_TEXTURE_2D,0,3,img->tamX(),img->tamY(),0,GL_RGB,GL_UNSIGNED_BYTE,img->leerPixels());
glBindTexture(GL_TEXTURE_2D,0);
}