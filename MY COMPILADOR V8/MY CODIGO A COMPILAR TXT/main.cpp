#include <iostream>

using namespace std;

int Bucle(){
    for(int i=0;i<5;i++){
        cout<<"Hola Mundo";
    }
}

int Condicionales(){
    int a=1;
    int b=2;
    if(a<b){
        cout<<"si";
    }
    if(4<6){
        cout<<"si";
    }else{
        cout<<"NO";
    }
}

int alex,escalante,maron=0;

int Operaciones(){
    int a=15;
    int b=10;
    int c=3;
    int respuesta=0;
    respuesta=(a*b)/c;
}

string Retornos(){
    string a="Alex";
    return a;
}

double Mostrar(){
   int a=12,b=10;
   cin>>a;
   cout<<"\t \t \t \t Hola soy alex Y ESTO \n ES UNA PRUEBA DE CANTIDAD";
   cout<<"TENGO 19 AÑOS \n XDDD";
   cout<<"VIVO EN PUNO"<<a<<b;
   cout<<"ESTUDIO EN UNAP\n \t xdxdxd";
}

int Declaraciones(int x,long y){

    int a=1,S,b,c=2;
    long d,e=3,g,f;

    string nombre="alex",apellido="escalante",colegio;

    char cad='Cad',inicial='A',cad2;

    float m=12.1,n,o=1.1;

    double r=12,s,t=12.22;
    double aaa=12,aaaaa=33;
    double aaab=12.11,aaaaab=33.44;
    double aaabd=12.11,aaaaabd;
    double aaabc,aaaaabc=33.44;
}

int Entrada_de_datos(){
    int a=10;
    float c=12.1;
    char O='1';
    string CADENA;
    cin>>a;
    cin>>c>>CADENA>>O;
}

int Recurcion(int a,int b,int c){
    cout<<"hola mundo";
    Recurcion(1,2,3);
}

int main(){
    ///Bucle();
    ///Condicionales();
    ///Operaciones();
    ///Retornos();
    ///Mostrar();
    ///Declaraciones(2,3);
    Entrada_de_datos();
    ///Recurcion(1,2,3);
}
