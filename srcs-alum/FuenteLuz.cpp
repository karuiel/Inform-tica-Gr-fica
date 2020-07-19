#include "FuenteLuz.hpp"

// activa la fuente de luz (con número GL_LIGHT0+i)
void FuenteLuz::activar( int i ) {
  glEnable(GL_LIGHT0+i);


  //  glLightfv(GL_LIGHT0+i, GL_POSITION, fuentes[i]->posvec);
    glLightfv(GL_LIGHT0+i, GL_AMBIENT, colores[0]); // hace SiA := (ra, ga, ba)
    glLightfv(GL_LIGHT0+i, GL_DIFFUSE, colores[1]); // hace SiD := (rd, gd, bd)
    glLightfv(GL_LIGHT0+i, GL_SPECULAR, colores[2]); // hace SiS := (rs , gs , bs)
  if(posvec[3]==1){
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glLightfv(GL_LIGHT0+i, GL_POSITION, posvec);
    glPopMatrix() ;
  }
  else{
    //const float[4] ejez={0,0,1,0};
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    // hacer M = Ide glMultMatrix( A ) ; // A podría ser Ide,V o V N
    // (3) rotación α grados en torno a eje Y
    glRotatef( longi, 0.0, 1.0, 0.0 ) ; // (2) rotación β grados en torno al eje X-
    glRotatef( lati, -1.0, 0.0, 0.0 ) ; // (1) hacer li := (0, 0, 1) (paralela eje Z+)
    glLightfv( GL_LIGHT0+i, GL_POSITION, Tupla4f(0,0,1,0) );
    glPopMatrix() ;
  }
  glEnable(GL_DEPTH_TEST);   //Activa el buffer de profundidad.
}