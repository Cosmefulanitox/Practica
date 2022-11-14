#include <iostream>
using namespace std;
#include "parcial2.h"

//3)	Generar un vector dinámico con los aviones de tipo propio y mostrarlo por pantalla. El vector debe contener el código de avión, el nombre y la marca.
class Avionpropio
{
private:
    int _codigo;
    char _nombre[30];
    char _marca[30];
public:
    void setCodigo(int codigo){_codigo=codigo;}
    void setNombre(const char *nombre){strcpy(_nombre,nombre);}
    void setMarca(const char *marca){strcpy(_marca,marca);}
    void mostrar ()
    {
        cout<<"Codigo: "<<_codigo <<endl;
        cout<<"Nombre: "<<_nombre <<endl;
        cout<<"Marca: "<<_marca <<endl;
    }
    bool operator =(Avion &aviones)
    {
        _codigo=aviones.getCodigoAvion();
        strcpy(_nombre, aviones.getNombre());
        strcpy(_marca, aviones.getMarca());

    }

};
class CantidadDevuelos
{
private:
    int _codigo;
    char _nombre[30];
    int _cantvuelos;
public:
    void setCodigo(int codigo){_codigo=codigo;}
    void setNombre(const char *nombre){strcpy(_nombre,nombre);}
    void setCantvuelos(int cantvuelos){_cantvuelos=cantvuelos;}
    void mostrar()
    {
        cout<<"Codigo avion: "<<_codigo<<endl;
        cout<<"Nombre avion: "<<_nombre<<endl;
        cout<<"Cantidad vuelos: "<<_cantvuelos<<endl;
    }


};
int cantidadRegistros(Pasaje &pasaje);
int cantidadRegistros (Pasajero &pasajero);
int cantidadRegistros (Avion &aviones);
int leertodoRegistro(Pasajero &pasajero, int pos);
bool grabarArchivospasajero (Pasajero pasajero);
void punto2();
int modificarRegistro(Avion aviones, int pos);
int contarAvionespropios();
void copiarAvionespropios(Avionpropio *aviones);
void mostrarAvionpropio(Avionpropio *av, int cant);
void punto3 ();


void punto1 ();




int main()
{

 punto3();



    return 0;

}
int leertodoRegistro(Pasajero &pasajero, int pos)
{
    FILE* p=fopen ("archivoPasajero.dat","rb");
    if (p==nullptr)
    {
        exit (1550);
    }
    fseek(p,sizeof(Pasajero)*pos,0);
    int leer = fread(&pasajero, sizeof (Pasajero),1,p);
    fclose (p);
    return leer;
}
bool operator == (Pasaje pasaje, Pasajero pasajero)
{
    if (pasaje.getNumeroPasajero()==pasajero.getNumeroPasajero())
    {
        return true;
    }
    return false;
}
int cantidadRegistros (Pasaje &pasaje)
{
    int tam=0;
    FILE * p= fopen("pasajes.dat","rb");
    if(p==nullptr)
    {
        cout<<"El archivo no pudo abrisse"<<endl;

        exit(1550);
    }
    fseek(p,0,SEEK_END);
    tam=ftell(p)/sizeof(Pasaje);
    fclose(p);

    return tam;


}
int cantidadRegistros (Pasajero &pasajero)
{
    int tam=0;
    FILE * p= fopen("pasajeros.dat","rb");
    if(p==nullptr)
    {
        cout<<"El archivo no pudo abrisse"<<endl;

        exit(1550);
    }
    fseek(p,0,SEEK_END);
    tam=ftell(p)/sizeof(Pasaje);
    fclose(p);

    return tam;


}
void punto1 ()
{
    Pasaje *pasaje;
    int cantidadPasajes = cantidadRegistros(*pasaje);
    pasaje = new Pasaje [cantidadPasajes];

    Pasajero *pasajeros;
    int cantidadPasajeros = cantidadRegistros(*pasajeros);
    pasajeros = new Pasajero [cantidadPasajeros];

    for (int i= 0; i< cantidadPasajes;i++)
    {
        pasaje[i].leerDeDisco(i);
        for (int j=0; j< cantidadPasajeros; j++)
        {
            pasajeros[j].leerDeDisco(j);
            if (pasaje[i] == pasajeros [j] && pasaje[i].getFechaCompra().getAnio() != 2022)
                pasajeros[j].setActivo(false);
                grabarArchivospasajero(pasajeros[j]);
                pasajeros[j].Mostrar();
        }
    }
    delete []pasaje;
    delete []pasajeros;
}

bool grabarArchivospasajero (Pasajero pasajero)
{
    FILE* p=fopen("archivoPasajero.dat","ab");
    if (p==nullptr)
    {
        cout<<"El archivo no puedo abrirse"<<endl;
        exit (1550);
    }
    bool grabo= fwrite(&pasajero, sizeof(Pasajero),1,p);
    fclose(p);

return grabo;


}
void punto2()
{
    Avion *aviones;
    int tam = cantidadRegistros(*aviones);
    aviones = new Avion [tam];
    for(int x=0;x<tam;x++)
    {
        aviones[x].leerDeDisco(x);
        if(strcmp(aviones[x].getMarca(),"boeing")==0)
        {
            aviones[x].setCantidadAsientos(aviones[x].getCantidadAsientos()*0.95);
            modificarRegistro(aviones[x],x);
        }
    }
    delete []aviones;

}
int cantidadRegistros (Avion &aviones)
{
     int tam=0;
    FILE * p= fopen("aviones.dat", "rb");
    if(p==nullptr)
    {
        cout<<"El archivo no pudo abrisse"<<endl;

        exit(1550);
    }
    fseek(p,0,SEEK_END);
    tam= ftell(p) / sizeof(Avion);
    fclose(p);

    return tam;
}
int modificarRegistro(Avion aviones,int pos)
{
    int tam=0;
    FILE * p= fopen("aviones.dat", "rb+");
    if(p==nullptr)
    {
        cout<<"El archivo no pudo abrisse"<<endl;

        exit(1550);
    }
    fseek(p,sizeof(Avion)*pos,SEEK_SET);
    tam=fwrite(&aviones,sizeof(Avion),1,p);
    fclose(p);

    return tam;

}
void punto3 ()
{
    int cant=0;
    Avionpropio *av;
    cant= contarAvionespropios();
    av= new Avionpropio [cant];
    if(av==nullptr) exit (1550);
    copiarAvionespropios(av);
    mostrarAvionpropio(av,cant);


}
int contarAvionespropios()
{

    Avion aviones;
    int cant=0,pos=0;
    while(aviones.leerDeDisco(pos++))
    {
        if(aviones.getTipo()==1) cant++;
    }
     return cant;
}
void copiarAvionespropios(Avionpropio *aviones)
{
    int i=0;
    Avion av;
    int cant=0,pos=0;
    while(av.leerDeDisco(pos++))
    {
        if(av.getTipo()==1)
        {
            aviones[i++]=av;
        }
    }


}
void mostrarAvionpropio(Avionpropio *av, int cant)
{
    int i=0;
    for (i=0;i<cant;i++)
    {
        av[i].mostrar();
    }
}
//6)	Generar un archivo con la cantidad de vuelos realizados por los aviones.
//Cada registro debe tener el código de avión, el nombre y la cantidad de vuelos.
void punto6()
{

}


