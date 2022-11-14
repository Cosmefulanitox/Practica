#include <iostream>
#include "ResumenDiarioArchivo.h"
#include "ModeloParcial.h"
using namespace std;

int main()
{
    int idest;
    float aux=0;
    int idt=0;
    int x=0;
    ModeloParcial Parcial;
    //Parcial.Litromascaro();//Punto 1
    Parcial.npromcom();
   // Parcial.getNosuper(idest);


 /* ResumenDiarioArchivo resumen;
  int cantidad = resumen.getCantidad();
  ResumenDiario* resumenes = new ResumenDiario[cantidad];
  resumen.leerTodos(resumenes, cantidad);

  for(int i=0;i<cantidad;i++)
  {


          cout<<resumenes[i].getIDEstacion()<<endl;
          cout<< resumenes[i].getIDTipoCombustible()<<endl;
          cout<<resumenes[i].getLitrosFinales()<<endl;
          cout<< resumenes[i].getLitrosIniciales()<<endl;
          cout<<resumenes[i].getPrecioPorLitro()<<endl;

  }

  // mostrar
 /* for (int i = 0; i < cantidad; i++) {
    cout << resumenes[i].getIDEstacion() << endl;
  }
   for (int i = 0; i < cantidad; i++)
   {

       cout << resumenes[i].getPrecioPorLitro() << endl;
       if (resumenes[i].getPrecioPorLitro()>aux)
       {
           aux=resumenes[i].getPrecioPorLitro();
           idt=resumenes[i].getIDTipoCombustible();
       }
   }
   cout<<"Precio:"<<aux<<endl;
   cout<<"El id de la nafta es"<<idt<<endl;*/





  return 0;
}
