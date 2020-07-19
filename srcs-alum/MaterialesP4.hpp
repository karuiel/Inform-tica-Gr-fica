#include "MaterialEstandar.hpp"
#include "Textura.hpp"

#ifndef MATERIALESP4_HPP
#define MATERIALESP4_HPP

class MaterialMadera : public MaterialEstandar{
public:
  MaterialMadera();
};

class MaterialBlanco : public MaterialEstandar{
public:
  MaterialBlanco();
};
class MaterialNegro : public MaterialEstandar{
public:
  MaterialNegro();
};
class MaterialLataPcuerpo : public MaterialEstandar{
public:
  MaterialLataPcuerpo();
};
class MaterialTapasLata : public MaterialEstandar
{
  public:
    MaterialTapasLata() ;
};
#endif