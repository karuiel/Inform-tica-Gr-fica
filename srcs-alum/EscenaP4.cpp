#include "EscenaP4.hpp"
#include "NodoGrafoEscena.hpp"
#include "MaterialesP4.hpp"
EscenaP4::EscenaP4(){

agregar (MAT_Traslacion(0,1.5,6));
agregar(new MaterialMadera());
agregar (new MallaRevol("./peon.ply",100,true,false,true));
agregar (MAT_Traslacion(2,0,0));
agregar(new MaterialBlanco());
agregar (new MallaRevol("./peon.ply",100,true,false,false));
agregar (MAT_Traslacion(2,0,0));
agregar(new MaterialNegro());
agregar (new MallaRevol("./peon.ply",100,true,false,false));

agregar (MAT_Traslacion(-4,-1.5,-6));
agregar (MAT_Escalado(5,5,5));

agregar(new MaterialLataPcuerpo());
agregar (new MallaRevol("./lata-pcue.ply",100,false,false,true));

agregar(new MaterialTapasLata());
agregar (new MallaRevol("./lata-psup.ply",100,true,false,true));
agregar (MAT_Traslacion(0,0.02,0));
agregar (new MallaRevol("./lata-pinf.ply",100,true,false,true));

}
