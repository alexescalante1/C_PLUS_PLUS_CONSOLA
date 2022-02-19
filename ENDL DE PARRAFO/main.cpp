#include <iostream>
#include <windows.h>
using namespace std;
string PARRAFO[9999];
int NUMFILAS=0;

char AUX_CAD[200];void CONCATENAR(string CAD){int i = 0;
    for(;AUX_CAD[i];i++);
    AUX_CAD[i]=CAD[0];
    AUX_CAD[i+1]='\0';
}
bool PALABRA(string C,int i,int f){
    for(int k=1;C[k];k++,i++){
        if(C[k]==' '){
            if(i>=f){
                return 0;
            }else{
                return 1;
            }
        }
    }
    return 0;
}
void CADENA(string C,int EXPONENCIAL){

    PALABRA(&C[0],0,EXPONENCIAL);
    for(int i=0,j=0;C[i];i++,j++){
        if(C[i]==' '){
            if(!PALABRA(&C[i],j,EXPONENCIAL)){
                PARRAFO[NUMFILAS]=AUX_CAD;
                AUX_CAD[0]='\0';
                j=0;NUMFILAS++;
            }
            else{CONCATENAR(" ");}
        }
        else{
            CONCATENAR(&C[i]);
        }
    }
}
void CF(string C,int EXPONENCIAL){

    for(int i=0,j=0;C[i];i++,j++){
        if(j==EXPONENCIAL){j=0;cout<<endl;}
        if(C[i]==' '){
            cout<<"*";
            //cout<<PALABRA(&C[i],j,EXPONENCIAL)<<"->  ";
        }
        else{
            cout <<C[i];
        }

    }
    cout<<endl;
    cout<<endl;
}

void ESPACIOS(int T){int DISP;
    for(int i=0,j=0,k=0;i<NUMFILAS;i++){
        cout<<PARRAFO[i];
        for(j=0;PARRAFO[i][j];j++){
            if(PARRAFO[i][j]==' '){k++;}
        }
        if((T-j)>T/2){
            cout<<"NULL";
        }
        DISP=(T-j);
        cout<<DISP<<" "<<k<<endl;k=0;
    }
}

int main()
{
    int T=40;
    CADENA("hola soy alex escalante esta es una muestra de los caracteres almacenados en un parrafo, xd hello world hola soy alex escalante esta es una muestra de los caracteres almacenados en una parrafo, xd hello world hola soy alex escalante esta es una muestra de los caracteres almacenados en una parrafo, xd hello world",T);
    ESPACIOS(T);
    return 0;
}
