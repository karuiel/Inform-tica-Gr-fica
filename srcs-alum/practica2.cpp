
#include "practica2.hpp"

unsigned objetoActivo = 1 ; 
static MallaPLY *mallaPly=NULL;
static MallaRevol *mallaRevol=NULL;

void P2_Inicializar( int argc, char *argv[] ){
if(argc!=9){
 mallaPly= new MallaPLY("../plys/big_dodge.ply");
 mallaRevol= new MallaRevol("../plys/peon.ply",50,true,false,false);
}
else{
  	mallaPly= new MallaPLY(argv[1]);
  	mallaRevol=new MallaRevol(argv[2],atoi(argv[3]),true,true,false);
  }
}

bool P2_FGE_PulsarTeclaNormal( unsigned char tecla )
{
   bool aux=true;
   if(toupper(tecla)=='O')
   {
        objetoActivo=(objetoActivo+1)%2;
    }else{
        	 aux = false ;
   	}
   
   return aux;
 }
 void P2_DibujarObjetos( ContextoVis & cv )
 {
     if (objetoActivo==0){
       mallaPly->visualizarGL(cv);
     }
     else{
       mallaRevol->visualizarGL(cv);
     }
     
}