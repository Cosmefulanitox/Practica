#pragma once
#include "ResumenDiario.h"
class ResumenDiarioArchivo
{
public:
  ResumenDiario leer(int pos);

  bool leerTodos(ResumenDiario* resumen, int cantidad);
  
  bool grabar(ResumenDiario reg);
  bool grabar(ResumenDiario reg, int pos);
  
  int getCantidad();
};

