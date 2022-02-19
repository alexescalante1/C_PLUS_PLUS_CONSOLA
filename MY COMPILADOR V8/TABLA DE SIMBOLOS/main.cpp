#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <conio.h>
#include <string.h>
#include <fstream>

using namespace std;
bool BUSQUEDA_TABLA_DE_SIMBOLOS=0;
string TIPO_DE_DATO="\0";
void MANDAR_FUN_LISTA(string);

///CONVERSION

template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg){
        INGRESAR(arg);
    }
    T INGRESAR(T arg){
        element=arg;
    }
    T RETORNO(){
        return element;
    }
};
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer(char arg){
        INGRESAR(arg);
    }
    char INGRESAR(char arg){
        element=arg;
    }
    char uppercase (){
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
    char RETORNO(){
        return element;
    }
};
mycontainer<int> TemplateInt (1);
mycontainer<long> TemplateLong (1);
mycontainer<float> TemplateFloat (1.0);
mycontainer<double> TemplateDouble (1.0);
mycontainer<string> TemplateString ("hola mundo");
mycontainer<char>   TemplateChar ('a');


///CONVERSION


///TABLA DE SIMBOLOS

class NODOTABLA{
    public:
    bool PARAMETRO;
    string FUNCION,TIPORANGO,TIPODATO,NAMEVAR,DATVAR;
    NODOTABLA *der,*PaDr;
    NODOTABLA(string FUNCION_TABLA=0,bool PARAMETRO_TABLA=0,string TIPO_RANGO=0,string TIPO_DAT=0,string NAME_VAR=0,string DAT_VAR=0,NODOTABLA *Padr=NULL,NODOTABLA *de=NULL){
         FUNCION=FUNCION_TABLA;
         PARAMETRO=PARAMETRO_TABLA;
         TIPORANGO=TIPO_RANGO;
         TIPODATO=TIPO_DAT;
         NAMEVAR=NAME_VAR;
         DATVAR=DAT_VAR;
         der=de;
         PaDr=Padr;
    }
};

class TABLADESIMBOLOS{
    public:
    NODOTABLA *raiz,*padr;
    TABLADESIMBOLOS(){
        raiz=NULL;
        padr=NULL;
    }

    void InsertarTABLA(string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,string DAT_VAR){
         ins(FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,DAT_VAR,raiz,padr);
    }
    void ins(string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,string DAT_VAR,NODOTABLA *&R,NODOTABLA *padr){
         if(R==NULL)
            R=new NODOTABLA(FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,DAT_VAR,padr);
         else
            ins(FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,DAT_VAR,R->der,R);
    }

    int MOSTRAR_VALORES(NODOTABLA *R){
        cout<<R->FUNCION<<" "
            <<R->PARAMETRO<<" "
            <<R->TIPORANGO<<" "
            <<R->TIPODATO<<" "
            <<R->NAMEVAR<<" "
            <<R->DATVAR<<"\n";
            return 1;
    }
    void MostrarTABLA(){
         Mos(raiz);
    }
    void Mos(NODOTABLA *R){
         if(R!=NULL){
            MOSTRAR_VALORES(R);
            Mos(R->der);
         }
    }

    int ELIMINAR_NODO(string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,int MODO_BUSQUEDA){

        ELIM_NOD(raiz,FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,MODO_BUSQUEDA);

        return 1;
    }
    int ELIM_NOD(NODOTABLA *&R,string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,int MODO_BUSQUEDA){
         if(R!=NULL){

            NODOTABLA *AUX_BORRAR=R;
            NODOTABLA *ANTERIOR=NULL;

            if(MODO_BUSQUEDA==1){
                while(AUX_BORRAR!=NULL&&AUX_BORRAR->FUNCION!=FUNCION_TABLA){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==2){
                while(AUX_BORRAR!=NULL&&AUX_BORRAR->PARAMETRO!=PARAMETRO_TABLA){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==3){
                while(AUX_BORRAR!=NULL&&AUX_BORRAR->TIPORANGO!=TIPO_RANGO){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==4){
                while(AUX_BORRAR!=NULL&&AUX_BORRAR->TIPODATO!=TIPO_DAT){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==5){
                while(AUX_BORRAR!=NULL&&AUX_BORRAR->NAMEVAR!=NAME_VAR){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==12){
                while(AUX_BORRAR!=NULL&&(AUX_BORRAR->FUNCION!=FUNCION_TABLA||AUX_BORRAR->PARAMETRO!=PARAMETRO_TABLA)){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==123){

                while(AUX_BORRAR!=NULL&&(AUX_BORRAR->FUNCION!=FUNCION_TABLA||AUX_BORRAR->PARAMETRO!=PARAMETRO_TABLA||AUX_BORRAR->TIPORANGO!=TIPO_RANGO)){
                        ANTERIOR=AUX_BORRAR;
                        MOSTRAR_VALORES(AUX_BORRAR);
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==1235){
                while(AUX_BORRAR!=NULL&&(AUX_BORRAR->FUNCION!=FUNCION_TABLA||AUX_BORRAR->PARAMETRO!=PARAMETRO_TABLA||AUX_BORRAR->TIPORANGO!=TIPO_RANGO||AUX_BORRAR->NAMEVAR!=NAME_VAR)){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }
            if(MODO_BUSQUEDA==12345){
                while(AUX_BORRAR!=NULL&&(AUX_BORRAR->FUNCION!=FUNCION_TABLA||AUX_BORRAR->PARAMETRO!=PARAMETRO_TABLA||AUX_BORRAR->TIPORANGO!=TIPO_RANGO||AUX_BORRAR->TIPODATO!=TIPO_DAT||AUX_BORRAR->NAMEVAR!=NAME_VAR)){
                        ANTERIOR=AUX_BORRAR;
                        AUX_BORRAR=AUX_BORRAR->der;
                }
            }


            if(AUX_BORRAR==NULL){
                ///cout<<"NO SE ENCONTRO\n";
                return 0;
            }else if(ANTERIOR==NULL){
                R=AUX_BORRAR->der;
                ///cout<<"DELETE: "<<AUX_BORRAR->FUNCION<<" "<<AUX_BORRAR->DATVAR<<endl;

                delete AUX_BORRAR;
                if(R!=NULL){
                    ///cout<<R->DATVAR<<"---->\n";
                    if(R->der!=NULL){
                        ELIM_NOD(R,FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,MODO_BUSQUEDA);
                    }
                }

            }else{
                ANTERIOR->der=AUX_BORRAR->der;
                ///cout<<"DELETEE: "<<AUX_BORRAR->FUNCION<<" "<<AUX_BORRAR->DATVAR<<endl;

                delete AUX_BORRAR;
                if(R!=NULL){
                    ///cout<<R->DATVAR<<"---->>\n";
                    if(R->der!=NULL){
                        ELIM_NOD(R,FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,MODO_BUSQUEDA);
                    }
                }
            }
         }
         return 1;
    }

    void BuscarTABLA(string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,int MODO_BUSQUEDA,string NEW_DATO){
         Bus_TABLA(raiz,FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,MODO_BUSQUEDA,NEW_DATO);
    }
    void Bus_TABLA(NODOTABLA *R,string FUNCION_TABLA,bool PARAMETRO_TABLA,string TIPO_RANGO,string TIPO_DAT,string NAME_VAR,int MODO_BUSQUEDA,string NEW_DATO){
         BUSQUEDA_TABLA_DE_SIMBOLOS=0;
         TIPO_DE_DATO="\0";
         if(R!=NULL){

            Bus_TABLA(R->der,FUNCION_TABLA,PARAMETRO_TABLA,TIPO_RANGO,TIPO_DAT,NAME_VAR,MODO_BUSQUEDA,NEW_DATO);

            if(MODO_BUSQUEDA==1){
                if(R->FUNCION==FUNCION_TABLA){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==2){
                if(R->PARAMETRO==PARAMETRO_TABLA){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==3){
                if(R->TIPORANGO==TIPO_RANGO){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==4){
                if(R->TIPODATO==TIPO_DAT){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = TIPO_DAT;

                }
            }
            if(MODO_BUSQUEDA==46){
                if(R->TIPODATO==TIPO_DAT){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                    CONVERTIR_DATO(TIPO_DAT,R->DATVAR);


                }
            }
            if(MODO_BUSQUEDA==5){
                if(R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==12){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==123){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA&&R->TIPORANGO==TIPO_RANGO){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==1235){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->NAMEVAR==NAME_VAR){
                    MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;

                }
            }
            if(MODO_BUSQUEDA==12345){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->TIPODATO==TIPO_DAT&&R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = TIPO_DAT;

                }
            }
            if(MODO_BUSQUEDA==123456){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->TIPODATO==TIPO_DAT&&R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = TIPO_DAT;

                }
            }
         }
    }

    bool CONVERTIR_DATO(string TIPO_DAT,string DATO){

        if(TIPO_DAT=="tipo_int"||TIPO_DAT=="tipo_long"){
            int NUM1;char *INTT;
            INTT=new char[8];
            int i=0;
            for(;DATO[i];i++){
                *(INTT+i)=DATO[i];
            }*(INTT+i)='\0';
            NUM1=atoi(INTT);
            TemplateInt.INGRESAR(NUM1);
        }
        if(TIPO_DAT=="tipo_float"||TIPO_DAT=="tipo_double"){
            float NUM1;char *FLOATT;
            FLOATT=new char[8];
            int i=0;
            for(;DATO[i];i++){
                *(FLOATT+i)=DATO[i];
            }*(FLOATT+i)='\0';
            NUM1=atof(FLOATT);
            TemplateFloat.INGRESAR(NUM1);
        }
        if(TIPO_DAT=="tipo_string"){
            ///TemplateString.INGRESAR(DATO);
        }
        if(TIPO_DAT=="tipo_char"){
            char CADD;
            CADD=DATO[0];
            TemplateChar.INGRESAR(CADD);
        }
        return 0;
    }

};
TABLADESIMBOLOS GLOBALTABLA;
///TABLA DE SIMBOLOS

void insertarr(){
    GLOBALTABLA.InsertarTABLA("true",1,"normal","tipo_int","b","21");
    GLOBALTABLA.InsertarTABLA("true",1,"normal","tipo_int","b","22");
    GLOBALTABLA.InsertarTABLA("true",1,"normal","tipo_int","b","23");
    GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_int","b","1");
    GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_int","b","2");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","a","3");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","xds","4");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","a","5");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle1","tipo_int","a","6");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle1","tipo_int","a","7");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle1","tipo_int","a","8");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle2","tipo_float","a","9");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle2","tipo_double","a","10");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle2","tipo_float","b","11");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle2","tipo_float","c","12");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","a","13");
    GLOBALTABLA.InsertarTABLA("XDDD",0,"normal","tipo_int","a","13");
}

int main()
{
    ///insertarr();

    ///INSERTAR
    GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","x",12345,"\0");
    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
        cout<<"INSERTANDO\n";
        GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_double","x","22.3");
    }else{
        cout<<"YA ESTA DECLARADO\n";
    }

    GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","x",12345,"\0");
    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
        cout<<"INSERTANDO\n";
        GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_double","x","22.3");
    }else{
        cout<<"YA ESTA DECLARADO\n";
    }

    GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","y",12345,"\0");
    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
        cout<<"INSERTANDO\n";
        GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_double","y","1.2");
    }else{
        cout<<"YA ESTA DECLARADO\n";
    }

    GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","Z",12345,"\0");
    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
        cout<<"INSERTANDO\n";
        GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_double","Z","3.1");
    }else{
        cout<<"YA ESTA DECLARADO\n";
    }

    ///INSERTAR





    ///MODIFICAR

    GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","y",12345,"\0");
    if(BUSQUEDA_TABLA_DE_SIMBOLOS){
        cout<<"SI EXISTE\n";
        cout<<TIPO_DE_DATO<<endl;



        //GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_double","y","1.2");
    }else{
        cout<<"NO EXISTE\n";
    }

    ///MODIFICAR


    /*
    cout<<endl<<TIPO_DE_DATO<<"D<<--"<<endl;
    if(TIPO_DE_DATO!="\0"){
        if(TIPO_DE_DATO=="tipo_int"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_int","x",46,"\0");
            cout<<TemplateInt.RETORNO()<<endl;
        }
        if(TIPO_DE_DATO=="tipo_long"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_long","x",46,"\0");
            cout<<TemplateInt.RETORNO()<<endl;
        }
        if(TIPO_DE_DATO=="tipo_float"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_float","x",46,"\0");
            cout<<TemplateFloat.RETORNO()<<endl;
        }
        if(TIPO_DE_DATO=="tipo_double"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_double","x",46,"\0");
            cout<<TemplateFloat.RETORNO()<<endl;
        }
        if(TIPO_DE_DATO=="tipo_string"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_string","x",46,"\0");
            cout<<TemplateString.RETORNO()<<endl;
        }
        if(TIPO_DE_DATO=="tipo_char"){
            GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_char","x",46,"\0");
            cout<<TemplateChar.RETORNO()<<endl;
        }
    }
*/
/*
    GLOBALTABLA.InsertarTABLA("main",1,"normal","tipo_int","y","2");
    //GLOBALTABLA.BuscarTABLA("main",1,"normal","tipo_int","y",12345,"8");

    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","a","3");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","b","4");
    GLOBALTABLA.InsertarTABLA("main",0,"normal","tipo_int","c","5");
    GLOBALTABLA.InsertarTABLA("main",0,"bucle1","tipo_long","a","6");
*/
    cout<<endl<<endl<<endl;
    //GLOBALTABLA.MostrarTABLA();
/*
    cout<<"\n";

    GLOBALTABLA.BuscarTABLA("main",0,"bucle2","tipo_float","c",12345,"RETORNAR");
    cout <<" R->> "<< TemplateFloat.RETORNO() << endl;



    ///cout<<"\n";

    ///GLOBALTABLA.ELIMINAR_NODO("main",0,"normal","tipo_int","a",12345);

    ///GLOBALTABLA.MostrarTABLA();

    cout<<"\n\n";


    GLOBALTABLA.CONVERTIR_DATO("tipo_int","20");
    GLOBALTABLA.CONVERTIR_DATO("tipo_float","2.2");
    GLOBALTABLA.CONVERTIR_DATO("tipo_string","hola mundo");
    GLOBALTABLA.CONVERTIR_DATO("tipo_char","cas");

    cout<<TemplateFloat.RETORNO();

    cout<<"\n\n";
*/
    system("PAUSE");

    return 0;
}
