//METODO DE CUADRADOS MEDIOS

#include <iostream>
#include <stdio.h>
#include <windows.h>
using namespace std;

long NUMBASE = 3708;

void CONCATENAR(char CAD,char **CADSALIDA){int i = 0;
    for(;*(*(CADSALIDA)+i);i++);
    *(*(CADSALIDA)+i) = CAD;
    *(*(CADSALIDA)+i+1) = '\0';
}

int CONVERTIR_INT_A_CAD(char **R,long long NUM){int TAM=0,i=0;
    for(long long AUX=NUM;AUX!=0;i++,AUX/=10);
    *R = new char [i];TAM=i;*(*(R)+i)='\0';i-=1;
    for(;i>=0;i--,NUM/=10){
        *(*(R)+i)=(char)(NUM%10+48);
    }
    return TAM;
}

void SELECCION(char *CAD,char **CADSALIDA, int MEDIO){
    for(int i = MEDIO-2; i < MEDIO+2; i++){
        CONCATENAR(CAD[i],*&CADSALIDA);
    }
    return;
}

int main()
{
    char *CADENTRADA,*CADSALIDA;

    double NUMDEC;
    NUMDEC = (double)NUMBASE/10000;
    cout<<NUMBASE;

    for(int i = 0; i<8; i++){
        CADSALIDA = new char[20];
        *(CADSALIDA+0) = '\0';
        int T = CONVERTIR_INT_A_CAD(&CADENTRADA,NUMBASE*NUMBASE);
        SELECCION(CADENTRADA,&CADSALIDA,T/2);
        NUMBASE = atoi(CADSALIDA);
        *(CADSALIDA+0) = '\0';
        NUMDEC = (double)NUMBASE/10000;
        cout<<" "<<NUMDEC<<"\n"<<NUMBASE;
    }

    return 0;
}
