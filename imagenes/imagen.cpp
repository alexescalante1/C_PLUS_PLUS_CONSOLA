#include "imagen.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
imagen::imagen()
//aqui se llama al constructor de pixeles por defecto
{
    _alto = 0;
    _ancho = 0;
}

imagen::imagen(int ancho,int alto)
: _pixels(ancho * alto, 0)
{
    _ancho = ancho;
    _alto = alto;
}

imagen::imagen(const imagen& other)
: _pixels(other._pixels)
{
    _alto = other._alto;
    _ancho = other._ancho;
}

void imagen::lee(string nombrefichero){
    ifstream F(nombrefichero.c_str());
    if(!F.is_open()){
        cout<<"No se pudo abrir";
        return;
    }
    string linea;
    getline(F, linea);
    if(linea!= "P2"){
        cout<<"Formato incorrecto";
        return;
    }
    getline(F,linea);
    while(linea[0] == '#'){
        getline(F,linea);
    }
    istringstream S(linea);

    S >> _ancho >> _alto;

    int Max;
    F >> Max;
    _pixels.resize(_ancho*_alto);
    for(int i=0; i< _pixels.size(); i++){
        F >> _pixels[i];
    }
}

void imagen::escribe(string nombrefichero) const{
    ofstream F(nombrefichero.c_str());
    F << "P2" << endl;
    F << "# Firmado por Alex " <<endl;
    F << _ancho <<" "<< _alto <<endl;
    F << 255 << endl;
    for(int i = 0; i< _pixels.size(); i++){
        F << _pixels[i] << ' ';
    }
}
