#include <iostream>
#include "ResumenDiarioArchivo.h"

ResumenDiario ResumenDiarioArchivo::leer(int pos)
{
  ResumenDiario reg;
  FILE* pFile;
  pFile = fopen("ResumenDiario.dat", "rb");
  
  if (pFile == NULL){
    return reg;
  }
  
  fseek(pFile, sizeof(ResumenDiario) * pos, SEEK_SET);
  fread(&reg, sizeof(ResumenDiario), 1, pFile);
  fclose(pFile);
  
  return reg;
}

bool ResumenDiarioArchivo::leerTodos(ResumenDiario* resumen, int cantidad)
{
  FILE* pFile;
  pFile = fopen("ResumenDiario.dat", "rb");
  if (pFile == NULL) {
    return false;
  }
  
  fread(resumen, sizeof(ResumenDiario), cantidad, pFile);
  fclose(pFile);
  return true;
}

bool ResumenDiarioArchivo::grabar(ResumenDiario reg)
{
  FILE* pFile;
  pFile = fopen("ResumenDiario.dat", "ab");
  if (pFile == NULL) {
    return false;
  }

  fwrite(&reg, sizeof(ResumenDiario), 1, pFile);
  fclose(pFile);
  return true;
}

bool ResumenDiarioArchivo::grabar(ResumenDiario reg, int pos)
{
  FILE* pFile;
  pFile = fopen("ResumenDiario.dat", "rb+");
  if (pFile == NULL) {
    return false;
  }

  fseek(pFile, sizeof(ResumenDiario) * pos, SEEK_SET);
  fwrite(&reg, sizeof(ResumenDiario), 1, pFile);
  fclose(pFile);
  return true;
}

int ResumenDiarioArchivo::getCantidad()
{
  FILE* pFile;
  pFile = fopen("ResumenDiario.dat", "rb");
  if (pFile == NULL) {
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  int cantidad = ftell(pFile) / sizeof(ResumenDiario);
  fclose(pFile);
  return cantidad;
}

