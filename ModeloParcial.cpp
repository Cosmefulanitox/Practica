#include <iostream>
#include "ResumenDiarioArchivo.h"
#include "ModeloParcial.h"
#include "ResumenDiario.h"
using namespace std;
void ModeloParcial::Litromascaro()
{
float aux=0;

int a;

    resumen;
     int cantidad = resumen.getCantidad();
      ResumenDiario* resumenes = new ResumenDiario[cantidad];
      resumen.leerTodos(resumenes, cantidad);


   for (int i = 0; i < cantidad; i++)
   {


       if (resumenes[i].getPrecioPorLitro()>aux)
       {
           aux=resumenes[i].getPrecioPorLitro();
           a=resumenes[i].getIDTipoCombustible();
       }

}
   cout<<"Precio:"<<aux<<endl;
   switch (a)
   {
   case 1:
       cout<<"El tipo de combustible que registro el precio mas alto fue la nafta super"<<endl;
    break;
   case 2:
       cout<<"El tipo de combustible que registro el precio mas alto fue la nafta comun "<<endl;
    break;

   case 3:
       cout<<"El tipo de combustible que registro el precio mas alto fue el diesel "<<endl;
    break;

   case 4:
      cout<<"El tipo de combustible que registro el precio mas alto fue el gasoil "<<endl;
    break;

   case 5:
       cout<<"El tipo de combustible que registro el precio mas alto fue el gnc"<<endl;
    break;
   default:

    break;
   }
}
void ModeloParcial::getNosuper(int idEst)
{
 resumen;

     int cantidad = resumen.getCantidad();
      ResumenDiario* resumenes = new ResumenDiario[cantidad];
      resumen.leerTodos(resumenes, cantidad);
    for (int x=0;x<cantidad;x++)
    {
        if(resumenes[x].getIDEstacion()==idEst)
        {
           if (resumenes[x].getIDTipoCombustible()!=1)
           {
               Fecha fecha;
               fecha=resumenes[x].getFecha();
               int m=fecha.getMes();
               cout <<"Mes "<<m<<" no hubo consumo de nafta super"<<endl;
           }
        }
    }


}
void ModeloParcial::npromcom()
{
    resumen;
    int acu[5]{};
    int cont[5]{};
    int prom [5]{};
    int band=0;
    int comb;
    int cantidad=resumen.getCantidad();
    ResumenDiario* resumenes= new ResumenDiario[cantidad];
    resumen.leerTodos(resumenes,cantidad);
    for(int x=0;x<cantidad;x++)
    {
        acu[resumenes[x].getIDTipoCombustible()]+=resumenes[x].getPrecioPorLitro();
        cont[resumenes[x].getIDTipoCombustible()]++;
    }
    for(int x=0;x<5;x++)
    {
        prom[x]=acu[x]/cont[x];
    }
      for(int x=0;x<5;x++)
    {
       if (prom[x]>band)
       {
           band=prom[x];
           comb=x;
       }
    }
    cout<<""<<band<<endl;
    cout<<""<<comb<<endl;

}
/*void resumenAnual()
void mostrarresumenAnual()
  ResumenDiarioArchivo ModeloParcial::getResumendiario()
  {



  }*/
