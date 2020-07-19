#include "MallaInd.hpp"

void MallaInd::visualizarGL( ContextoVis & cv ){
	if(cv.modoVisu == modoPuntos){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]); // establer direccion y estructuras
        glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);     //Visualiza primitivas
		glDisableClientState( GL_VERTEX_ARRAY );

	}

	if(cv.modoVisu == modoAlambre){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]); // establer direccion y estructuras
        glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);     //Visualiza primitivas
		glDisableClientState( GL_VERTEX_ARRAY );

	}

	if(cv.modoVisu == modoSolido){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]); // establer direccion y estructuras
        glColor3f(0.5,0.5,0.5);
        glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);     //Visualiza primitivas
		glDisableClientState( GL_VERTEX_ARRAY );

	}

	if(cv.modoVisu == modoAjedrez){
		glDisable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		if(caras2.size()==0){
			
			if(caras.size()%2==0){
				tam1=caras.size()/2;
				tam2=caras.size()/2;
			}else{
				tam1=(caras.size()/2)+1;
				tam2=caras.size()/2;

			}
			int k=0,j=0;
			for(int i=0;i<caras.size();i++){
				if(i%2==0){
					caras2.push_back(caras.at(i));
				}
			}
			for(int i=0;i<caras.size();i++){
				if(i%2!=0){
					caras2.push_back(caras.at(i));
				}
			}
		}
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]); // establer direccion y estructura
        glColor3f(0.7,0.7,0.0); 	
	    glDrawElements(GL_TRIANGLES,tam1*3,GL_UNSIGNED_INT,&caras2[0]);     //Visualiza primitivas
		glColor3f(0.0,0.0,0.0);
		glDrawElements(GL_TRIANGLES,tam2*3,GL_UNSIGNED_INT,&caras2[(caras.size()/2)]);
		glDisableClientState( GL_VERTEX_ARRAY );
	}

	if(cv.modoVisu == modoIluPlano){
      glEnable(GL_LIGHTING);
      glShadeModel(GL_FLAT); //caras es como solido

      if(normalVertices.size() != 0)
    		glEnableClientState( GL_NORMAL_ARRAY );

    	glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
    	if(textura.size() != 0)
    		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
    	if(normalVertices.size() != 0)
    			glNormalPointer(GL_FLOAT, 0, &normalVertices[0]);

    	if(textura.size() != 0)
    		glTexCoordPointer( 2, GL_FLOAT, 0, &textura[0] );

      glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]);
      glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);
      if(textura.size() != 0)
      		glDisableClientState( GL_TEXTURE_COORD_ARRAY );
    	if(normalVertices.size() != 0)
      		glDisableClientState( GL_NORMAL_ARRAY );
      	glDisableClientState( GL_VERTEX_ARRAY );
    }
    if(cv.modoVisu==modoIluSuave){
        glEnable(GL_LIGHTING);
        glShadeModel(GL_SMOOTH); //caras es como solido

        if(normalVertices.size() != 0)
          glEnableClientState( GL_NORMAL_ARRAY );
        glEnableClientState( GL_VERTEX_ARRAY ); // habilitar array de vertices
        if(textura.size() != 0)
          glEnableClientState( GL_TEXTURE_COORD_ARRAY );

        if(normalVertices.size() != 0)
            glNormalPointer(GL_FLOAT, 0, &normalVertices[0]);

        if(textura.size() != 0)
          glTexCoordPointer( 2, GL_FLOAT, 0, &textura[0] );

        glVertexPointer( 3, GL_FLOAT, 0, &vertices[0]); // estable direccion y estructuras
        glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&caras[0]);
        if(textura.size() != 0)
            glDisableClientState( GL_TEXTURE_COORD_ARRAY );
        if(normalVertices.size() != 0)
            glDisableClientState( GL_NORMAL_ARRAY );
          glDisableClientState( GL_VERTEX_ARRAY );
    }

}


	void MallaInd::calcularNormales(){
	  Tupla3f a,b,m;	                                     
	  for(int i=0;i<caras.size();i++){
	    a=vertices[caras[i](1)]-vertices[caras[i](0)];
	    b=vertices[caras[i](2)]-vertices[caras[i](1)];
	    m=Tupla3f(a(1)*b(2)-a(2)*b(1),a(2)*b(0)-a(0)*b(2),a(0)*b(1)-a(1)*b(0));
	    if(m[0]!=0&&m[1]!=0&&m[2]!=0)
	      normalCaras.push_back(m.normalized());
	    else
	      normalCaras.push_back(Tupla3f(a(1)*b(2)-a(2)*b(1),a(2)*b(0)-a(0)*b(2),a(0)*b(1)-a(1)*b(0)));
	  }
	  for(int i=0;i<vertices.size();i++){  //creo normalVertices de tamaño numVertices inicializado a cero
	    normalVertices.push_back(Tupla3f(0,0,0));
	  }
	  /******
	  * Si la cara i-esima contiene al vertice [i](0|1|1), le sumo su normal de cara
	  * a las normales de cara que ya contenia por ser caras adyacentes a ese vertice
	  * inicialmente ninguna luego era 0, por ultimo se normaliza cada componente del vector
	  * normalVertices
	  ******/
	  for (int i=0;i<caras.size();i++){
	    normalVertices[caras[i][0]]=normalVertices[caras[i][0]]+normalCaras[i];
	    normalVertices[caras[i][1]]=normalVertices[caras[i][1]]+normalCaras[i];
	    normalVertices[caras[i][2]]=normalVertices[caras[i][2]]+normalCaras[i];
	  }
	  for(int i=0;i<normalVertices.size();i++){
	    if(normalVertices[i][0]!=0&&normalVertices[i][1]!=0&&normalVertices[i][2]!=0)
	      normalVertices[i]=normalVertices[i].normalized();
	    else
	      normalVertices[i]=normalVertices[i];
	  }

    }

