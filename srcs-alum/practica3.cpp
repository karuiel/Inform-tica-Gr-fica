#include "practica3.hpp"


static bool animacion= false;
static Robot *miRobot=NULL;
static int p3_grado_libertad_activo=0;
static float cantidadG0=0; //cantidad para traslaciones
static float cantidadG1=0;   //cantidad para giros
static float cantidadG2=0;   //cantidad para giros
static float velocidadG0=0.1; //cantidad de velocidad para traslaciones en animacion
static float velocidadG1=0.5;   //cantidad para velocidad giros de extremidades en animacion
static float velocidadG2=0.5;   //cantidad para velocidad giros de cabeza en animacion

static int nG=3;
static bool restaAngulo=false, restaAngulo2=false , restaDistancia=false;


void P3_Inicializar( int argc, char *argv[] )
{
  miRobot= new Robot();
  glEnable(GL_RESCALE_NORMAL);
  }
 void P3_DibujarObjetos( ContextoVis & vis)
 {
       miRobot->visualizarGL(vis);
 }
 bool P3_FGE_PulsarTeclaNormal( unsigned char tecla )
 {
   bool redisp=true;
   switch (tecla)
   {
     case '<':
      if(animacion==false){
        switch (p3_grado_libertad_activo) {
          case 0:
            cantidadG0=cantidadG0-0.5;
            if (cantidadG0<-100){
              cerr<<"Minimo pulsa >"<<endl;
              cantidadG0=cantidadG0+0.5;
              redisp=false;
              }
            break;
          case 1:
            cantidadG1=cantidadG1-0.5;
            if (cantidadG1<-40){
              cerr<<"Minimo pulsa >"<<endl;
              cantidadG1=cantidadG1+0.5;
              redisp=false;
            }
            break;

            case 2:
            cantidadG2=cantidadG2-0.5;
            if (cantidadG2<-40){
              cerr<<"Minimo pulsa >"<<endl;
              cantidadG2=cantidadG2+0.5;
              redisp=false;
            }
            break;
          
        }
      }else{
        switch (p3_grado_libertad_activo) {
        case 0:
          velocidadG0=velocidadG0-0.1;
          if (velocidadG0<0.1){
            velocidadG0=0.1;
            cerr<<"Limite de velocidad inferior alcanzado"<<endl;
            cerr<<"Aumentala con >"<<endl;
          }
          break;
        case 1:
          velocidadG1=velocidadG1-0.5;
          if (velocidadG1<0.1){
            velocidadG1=0.1;
            cerr<<"Limite de velocidad inferior alcanzado"<<endl;
            cerr<<"Aumentala con >"<<endl;
          }
          break;
        case 2:
          velocidadG2=velocidadG2-0.5;
          if (velocidadG2<0.1){
            velocidadG2=0.1;
            cerr<<"Limite de velocidad inferior alcanzado"<<endl;
            cerr<<"Aumentala con >"<<endl;
          }
          break;        
          default:
          break;
          }
      }
      break;
    case '>':
      if(animacion==false){
        switch (p3_grado_libertad_activo) {
          case 0:
            cantidadG0=cantidadG0+0.5;
            if (cantidadG0>100){
              cerr<<"Maximo pulsa <"<<endl;
              cantidadG0=cantidadG0-0.5;
              redisp=false;
            }
            break;
          case 1:
            cantidadG1=cantidadG1+0.5;
            if (cantidadG1>40){
              cerr<<"Maximo pulsa <"<<endl;
              cantidadG1=cantidadG1-0.5;
              redisp=false;
            }
            break;
          case 2:
            cantidadG2=cantidadG2+0.5;
            if (cantidadG2>40){
              cerr<<"Maximo pulsa <"<<endl;
              cantidadG2=cantidadG2-0.5;
              redisp=false;
            }
            break;
           default:
            break;
        }
      }else{
        switch (p3_grado_libertad_activo) {
        case 0:
          velocidadG0=velocidadG0+0.1;
          break;
        case 1:
          velocidadG1=velocidadG1+0.5;
          break;
        case 2:
          velocidadG2=velocidadG2+0.5;
          break;
        default:
          break;
        }

      }
    break;
    case 'G':
    case 'g':
      p3_grado_libertad_activo++;
      p3_grado_libertad_activo=p3_grado_libertad_activo++%nG;
      break;
      case 'a':
      case 'A':
          if(animacion==true){
            animacion=false;
          }else{
            animacion = true;
            glutIdleFunc(FGE_Desocupado);
          }
      break;
      default:
        redisp = false ;
        break ;
   }
   if(redisp){
     switch (p3_grado_libertad_activo) {
       case 0:
        cerr<<"Traslacion GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG0;
        miRobot->Desplazarse(cantidadG0);
        break;
      case 1:
        cerr<<"Rotacion GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG1;
        miRobot->GirarExtremidades(cantidadG1);
        break;
      case 2:
        cerr<<"Rotacion GradoLibertad: "<<p3_grado_libertad_activo<<" Valor: "<<cantidadG2;
        miRobot->GirarCabeza(cantidadG2);
        break;
      }
   }
   return redisp;
}
 void P3_Animacion(){
  if(p3_grado_libertad_activo==0){
   if (cantidadG0>100||cantidadG0<-100){
    restaDistancia= !restaDistancia;}
   if (restaDistancia){cantidadG0=cantidadG0-velocidadG0;}
   else {cantidadG0=cantidadG0+velocidadG0;}
  } 
  if(p3_grado_libertad_activo==1){
   if (cantidadG1<-40||cantidadG1>40)
    restaAngulo= !restaAngulo;
   if (restaAngulo){cantidadG1=cantidadG1-velocidadG1;}
   else {cantidadG1=cantidadG1+velocidadG1;}
  }
  if(p3_grado_libertad_activo==2){
    if (cantidadG2<-40||cantidadG2>40)
    restaAngulo2= !restaAngulo2;
   if (restaAngulo2){cantidadG2=cantidadG2-velocidadG2;}
   else {cantidadG2=cantidadG2+velocidadG2;}
  }
   cerr<<" Velocidad Grado0: "<<velocidadG0<<" Velocidad Grado 1: "<<velocidadG1<<" Velocidad Grado 2: "<<velocidadG2<<endl;
   cerr<<" Cantidad Grado0: "<<cantidadG0<<" Cantidad Grado1: "<<cantidadG1<<" Cantidad Grado2: "<<cantidadG2<<endl;

   miRobot->Desplazarse(cantidadG0);
   miRobot->GirarExtremidades(cantidadG1);
   miRobot->GirarCabeza(cantidadG2);
}

// Func. de gestión del evento de desocupado de la práctica 3
// debe devolver: false: si queremos que se desactive el evento
// true: si queremos que el evento permanezca activado
bool P3_FGE_Desocupado (){
  // no hacer nada si no es necesario, y desactivar
  if (animacion==false){
    return false ;
  } 
  //modificar los parámetros animables según sus velocidades actuales
  P3_Animacion();
  //forzar un evento de redibujado para visualizar siguiente cuadro:
  glutPostRedisplay ();
  //terminar, manteniendo activada la gestión del evento

  return true ;

}