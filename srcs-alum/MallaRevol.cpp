#include "MallaRevol.hpp"
#include <cstring>
  MallaRevol::MallaRevol(const std::string & nombre_arch ,const unsigned nperfiles,const bool crear_tapas, const bool cerrar_malla, bool textura){



     std::vector<float> vertices_ply ; // coordenadas de vértices
     ply::read_vertices( nombre_arch.c_str(), vertices_ply );
     int tam = vertices_ply.size();
     int n=tam/3;

    if(cerrar_malla){
     

     for (int j=0;j<nperfiles;j++){
         for (int i=0;i<tam;i=i+3){
           vertices.push_back(Tupla3f(vertices_ply[i]*cos(2*PI*j/nperfiles),
           vertices_ply[i+1],vertices_ply[i]*sin(2*PI*j/nperfiles)));
         }
     }


     for(int j=0;j<nperfiles-1;j++){
        for(int i=0;i<n-1;i++){
         caras.push_back(Tupla3i(i+n*j,i+1+n*j,i+n*(j+1))); 
         caras.push_back(Tupla3i(i+n*(j+1),i+1+n*(j+1),i+1+n*j));
        }
     }
      for(int i=0;i<n-1;i++){
           caras.push_back(Tupla3i(i+n*(nperfiles-1),i+1+n*(nperfiles-1),i));
           caras.push_back(Tupla3i(i,i+1,i+1+n*(nperfiles-1)));
      }
    }else{

        for (int j=0; j <= nperfiles; ++j){
          for (int i=0; i < n; ++i){

           vertices.push_back(Tupla3f(vertices_ply[3*i]*cos(2*PI*j/nperfiles),
           vertices_ply[3*i+1],vertices_ply[3*i]*sin(2*PI*j/nperfiles)));

            if(i!=0 && j!=nperfiles){
                caras.push_back(Tupla3i(j*n + i,(j+1) * n + i,j*n + i-1));

                caras.push_back(Tupla3i( j*n + i-1,(j+1) * n + i,(j+1) * n + i-1));
            }
          }
        }


    }
     
if(crear_tapas){
  if(cerrar_malla){
    vertices.push_back(Tupla3f(0,vertices_ply[1],0));
    vertices.push_back(Tupla3f(0,vertices_ply[tam-2],0));

    for(int i=0;i<nperfiles-1;i++){
          caras.push_back(Tupla3i(i*n,n*nperfiles,(i+1)*n));   
    }
    for (int i=0;i<nperfiles-1;i++){
      caras.push_back(Tupla3i(n-1+i*n,n*nperfiles+1,(n-1)+(i+1)*n)); 
    }

      caras.push_back(Tupla3i(0,n*nperfiles,n*(nperfiles-1)));
      caras.push_back(Tupla3i(n-1+(nperfiles-1)*n,n*nperfiles+1,(n-1)));
    }else{

        vertices.push_back(Tupla3f(0.0, vertices_ply[1], 0.0));
        vertices.push_back(Tupla3f(0.0, vertices_ply[n*3-2], 0.0));

        // Metemos las tapas superior e inferior
        for (int j=0; j < nperfiles; ++j){
            caras.push_back(Tupla3i((j+1)*n-1,vertices.size()-1,(j+2)*n - 1));
        }

        for (int j=0; j < nperfiles; ++j){
            caras.push_back(Tupla3i(j * n,(j+1) * n,vertices.size()-2));
        }
    }
}

calcularNormales();
  if(textura){ 
      float s=0;
      float m=0;
      std::vector<float> d ;
      d.push_back(0);
      Tupla3f distancia;
      for (int k = 1; k < n; k++) {
        distancia=(vertices[k]-vertices[k-1]);
        d.push_back(d[k-1]+sqrt(distancia.lengthSq()));
      }
      for (int i=0;i<nperfiles;i++){
        s=(i/(nperfiles-1.0));
        //calculo dn
        for (int j=0;j<n;j++){
          this->textura.push_back(Tupla2f(1-s,1-(d[j]/d[n-1])));
          
        }
      }
}


}