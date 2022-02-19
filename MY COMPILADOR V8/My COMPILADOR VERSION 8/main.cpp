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
string VALOR_DATO="\0";

void MANDAR_FUN_LISTA(string);

///lista almacena
class NODOLIST_ERROR{
    public:
    string MESSAGGES,DATO;
    int NuMeRo_FiLa;
    NODOLIST_ERROR *der;
    NODOLIST_ERROR(int NFILA,string DAT,string MESSAGG="\0",NODOLIST_ERROR *de=NULL){
         MESSAGGES=MESSAGG;
         DATO=DAT;
         NuMeRo_FiLa=NFILA;
         der=de;
    }
};
class LISTA_ERROR{
    public:
    NODOLIST_ERROR *raiz;
    LISTA_ERROR(){
        raiz=NULL;
    }
    void InsertarLIST(int Num_FIL,string DAT_ERR,string MESSAGG){
         ins(Num_FIL,DAT_ERR,MESSAGG,raiz);
    }
    void ins(int Num_FIL,string DAT_ERR,string MESSAGG,NODOLIST_ERROR *&R){
         if(R==NULL)
            R=new NODOLIST_ERROR(Num_FIL,DAT_ERR,MESSAGG);
         else
            ins(Num_FIL,DAT_ERR,MESSAGG,R->der);
    }
    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODOLIST_ERROR *R){
         if(R!=NULL){
            cout<<"LINEA: "<<R->NuMeRo_FiLa<<" --> ";
            cout<<R->DATO<<" --> ";
            cout<<R->MESSAGGES<<"\n";
            Mos(R->der);
         }
    }
}LIST_ERROR_INFORME;

/*
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
        return '0';
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

*/


int RET_DAT_INT;
float RET_DAT_FLOAT;
string RET_DAT_STRING;
char RET_DAT_CHAR;


///CONVERSION


///TABLA DE SIMBOLOS

class NODOTABLA{
    public:
    bool PARAMETRO;
    string FUNCION,TIPORANGO,TIPODATO,NAMEVAR,DATVAR;
    NODOTABLA *der,*PaDr;
    NODOTABLA(string FUNCION_TABLA="\0",bool PARAMETRO_TABLA=0,string TIPO_RANGO="\0",string TIPO_DAT="\0",string NAME_VAR="\0",string DAT_VAR="\0",NODOTABLA *Padr=NULL,NODOTABLA *de=NULL){
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
            if(MODO_BUSQUEDA==135){
                if(R->FUNCION==FUNCION_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = R->TIPODATO;
                    VALOR_DATO = R->DATVAR;
                }
            }
            if(MODO_BUSQUEDA==1235){
                if(R->FUNCION==FUNCION_TABLA&&R->PARAMETRO==PARAMETRO_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->NAMEVAR==NAME_VAR){
                    MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = TIPO_DAT;
                }
            }

            if(MODO_BUSQUEDA==1345){
                if(R->FUNCION==FUNCION_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->TIPODATO==TIPO_DAT&&R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    BUSQUEDA_TABLA_DE_SIMBOLOS = 1;
                    TIPO_DE_DATO = TIPO_DAT;
                }
            }
            if(MODO_BUSQUEDA==1356){
                if(R->FUNCION==FUNCION_TABLA&&R->TIPORANGO==TIPO_RANGO&&R->NAMEVAR==NAME_VAR){
                    ///MOSTRAR_VALORES(R);
                    R->DATVAR=NEW_DATO;
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
            RET_DAT_INT=NUM1;
            ///TemplateInt.INGRESAR(NUM1);
        }
        if(TIPO_DAT=="tipo_float"||TIPO_DAT=="tipo_double"){
            float NUM1;char *FLOATT;
            FLOATT=new char[8];
            int i=0;
            for(;DATO[i];i++){
                *(FLOATT+i)=DATO[i];
            }*(FLOATT+i)='\0';
            NUM1=atof(FLOATT);
            RET_DAT_FLOAT=NUM1;
            ///TemplateFloat.INGRESAR(NUM1);
        }
        if(TIPO_DAT=="tipo_string"){
            RET_DAT_STRING=DATO;
            ///TemplateString.INGRESAR(DATO);
        }
        if(TIPO_DAT=="tipo_char"){
            char CADD;
            CADD=DATO[0];
            RET_DAT_CHAR=CADD;
            ///TemplateChar.INGRESAR(CADD);
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

int PRUEBAS_TB_SIMBOLOS()
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
    GLOBALTABLA.MostrarTABLA();
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


///lista FUNCION

class NODOLIST_FUN{
    public:
    string DAT,DAT_AUT;
    int NUMERO_FILA;
    NODOLIST_FUN *der,*PaDr;
    NODOLIST_FUN(string D="\0",string DAT_AUTOMATA="\0",int NUM_FIL=0,NODOLIST_FUN *Padr=NULL,NODOLIST_FUN *de=NULL){
         DAT=D;
         DAT_AUT=DAT_AUTOMATA;
         NUMERO_FILA=NUM_FIL;
         der=de;
         PaDr=Padr;
    }
};
class LISTA_FUN{
    int CONTADOR_SALTOS=0;
    bool FIN_AUTOMATA=0;
    bool ERROR_AUTOMATA=0;
    public:


    NODOLIST_FUN *raiz,*padr;

    LISTA_FUN(){
        raiz=NULL;
        padr=NULL;
    }
    void InsertarLIST(string D,string DAT_AUTOMATA,int NUM_FIL){
         ins(D,DAT_AUTOMATA,NUM_FIL,raiz,padr);
    }
    void ins(string D,string DAT_AUTOMATA,int NUM_FIL,NODOLIST_FUN *&R,NODOLIST_FUN *padr){
         if(R==NULL)
            R=new NODOLIST_FUN(D,DAT_AUTOMATA,NUM_FIL,padr);
         else
            ins(D,DAT_AUTOMATA,NUM_FIL,R->der,R);
    }
    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODOLIST_FUN *R){
         if(R!=NULL){
            cout<<R->DAT<<" ("<<R->NUMERO_FILA<<") ";
            Mos(R->der);
         }
    }
    void EJECUTAR_CODIGO(string val){
         EJECUTAR(raiz,val);
    }
    void EJECUTAR_CODIGO_PARAM(string val){
         EJECUTAR_PARAM(raiz,val);
    }

    string CONCATENAR_FLOAT(string NU1,string NU2){
        int COnT=0,COnT1=0;char *T_FLOAT;
        for(;NU1[COnT];COnT++);
        for(;NU2[COnT1];COnT1++);
        T_FLOAT=new char[COnT+COnT1+2];
        for(COnT=0;NU1[COnT];COnT++){
            *(T_FLOAT+COnT)=NU1[COnT];
        }*(T_FLOAT+COnT)='.';COnT++;
        for(COnT1=0;NU2[COnT1];COnT1++,COnT++){
            *(T_FLOAT+COnT)=NU2[COnT1];
        }*(T_FLOAT+COnT)='\0';
        return T_FLOAT;
    }
    string NUMRO(char DAT_CINN){
        for(char i='0';i<='9';i++){
            if(DAT_CINN==i){
                return "tipo_int";
            }
            if(DAT_CINN=='.'){
                return "tipo_float";
            }
        }return "tipo_string";
    }
    string TipoDATO_CIN(string DAT_CINN){
        string TIPO;
        for(int i=0;DAT_CINN[i];i++){
            TIPO=NUMRO(DAT_CINN[i]);
            if(TIPO=="tipo_string"){
                return "tipo_string";
            }
            if(TIPO=="tipo_float"){
                return "tipo_float";
            }
        }return "tipo_int";
    }
    string RETURN_INT_D(string DAT_CINN){
        char TP_INT[12];int i=0;
        for(;DAT_CINN[i]!='.'&&DAT_CINN[i];i++){
            *(TP_INT+i)=DAT_CINN[i];
        }*(TP_INT+i)='\0';
        return TP_INT;
    }

    ///ERROR MESSAGGE

    void ERROR_SNTXS_INT(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"LA DECLARACION DE ENTEROS ESTA MAL DEFINIDA!!");
    }
    void ERROR_SNTXS_DOUBLE(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"LA DECLARACION DE .FLOTANTES ESTA MAL DEFINIDA!!");
    }
    void ERROR_SNTXS_STRING(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"LA DECLARACION DE STRINGS NO ESTA MAL DEFINIDA!!");
    }
    void ERROR_SNTXS_CHAR(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"LA DECLARACION DE CARACTERES ESTA MAL DEFINIDA!!");
    }
    void ERROR_SNTXS_COUT(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"COUT ESTA MAL DEFINIDO!!");
    }
    void ERROR_SNTXS_CIN(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"CIN ESTA MAL DEFINIDO!!");
    }
    void ERROR_SNTXS_LLAMADA_FUNCION(int Num_FilA,string DAT_ERROR){
        LIST_ERROR_INFORME.InsertarLIST(Num_FilA,DAT_ERROR,"LA LLAMADA A FUNCION ESTA MAL DEFINIDA!!");
    }

    ///ERROR MESSAGGE


    ///AUTOMATAS A DECLARAR

    ///automata declaraciones int-long
    int DECLARAR_PARAMETR_INT_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;

        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            string NOMBRE_FUNCION,TIPO_FUNCION,DATOSTRING;

            if(R->DAT_AUT=="tipo_int"||R->DAT_AUT=="tipo_long"){cout<<R->DAT_AUT<<"\n";TIPO_FUNCION=R->DAT_AUT; R=R->der;
                if(R->DAT_AUT=="Variable"){cout<<R->DAT_AUT<<"\n";NOMBRE_FUNCION=R->DAT;
                    if(R->der!=NULL){
                        R=R->der;
                    }else{
                        GLOBALTABLA.BuscarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,1235,"\0");
                        if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                            cout<<"INSERTANDO\n";
                            GLOBALTABLA.InsertarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                        }else{

                            cout<<"YA ESTA DECLARADO\n";
                        }
                        CONTADOR_SALTOS=1;
                        cout<<"FIN int\n\n\n";
                        return CONTADOR_SALTOS;
                    }
                    if(R->DAT_AUT=="op_asignacion"||R->DAT_AUT=="OP_coma"){
                        if(R->DAT_AUT=="op_asignacion"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R->DAT_AUT=="Numero"){cout<<R->DAT<<"\n";DATOSTRING=R->DAT;
                                if(R->der!=NULL){
                                    R=R->der;
                                }else{
                                    GLOBALTABLA.BuscarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,1235,"\0");
                                    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                        cout<<"INSERTANDO\n";
                                        GLOBALTABLA.InsertarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                    }else{
                                        cout<<"YA ESTA DECLARADO\n";
                                    }

                                    CONTADOR_SALTOS=4;
                                    cout<<"FIN int\n\n\n";
                                    return CONTADOR_SALTOS;
                                }
                                if(R->DAT_AUT=="OP_coma"){
                                    if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n";
                                        GLOBALTABLA.BuscarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,1235,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                            cout<<"INSERTANDO\n";
                                            GLOBALTABLA.InsertarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                        }else{
                                            cout<<"YA ESTA DECLARADO\n";
                                        }

                                        CONTADOR_SALTOS=4;
                                        cout<<"FIN int\n\n\n";
                                        return CONTADOR_SALTOS;
                                    }
                                }else{ERROR_AUTOMATA=1;}

                            }else{ERROR_AUTOMATA=1;}

                        }

                        if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            GLOBALTABLA.BuscarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,1235,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,1,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                cout<<"YA ESTA DECLARADO\n";
                            }
                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=2;
                            cout<<"FIN int\n\n\n";
                            return CONTADOR_SALTOS;
                        }

                        if(R==NULL){cout<<"SI NULL"<<"\n";
                        }

                    }else{ERROR_AUTOMATA=1;}

                }else{ERROR_AUTOMATA=1;}

            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                return 0;
            }

        }return 0;
    }

    int DECLARAR_LLAMADA_FUNCION(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata llamada de funciones
/*
        LISTA_FUN PASE_POR_PARAMETRO;

        PASE_POR_PARAMETRO.InsertarLIST("HOLA","mundo");
        PASE_POR_PARAMETRO.InsertarLIST("HOLA","mundo");
        PASE_POR_PARAMETRO.InsertarLIST("HOLA","mundo");
        PASE_POR_PARAMETRO.InsertarLIST("HOLA","mundo");
        PASE_POR_PARAMETRO.InsertarLIST("HOLA","mundo");

        PASE_POR_PARAMETRO.MostrarLIST();
*/
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            int NUM_FILA_F=R->NUMERO_FILA;
            string DATO_FALT_ERROR;
            string NOMBRE_FUNCION,TIPO_FUNCION,DATOSTRING;
            if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";NOMBRE_FUNCION=R->DAT;R=R->der;
                if(R==NULL){ERROR_SNTXS_LLAMADA_FUNCION(NUM_FILA_F," FALTA ( ");return 0;}
                if(R->DAT_AUT=="parentesis_abre"){cout<<R->DAT_AUT<<"\n";R=R->der;
                    int variacion=0;
                    for(int PPP=1;PPP;){
                        if(R==NULL){ERROR_SNTXS_LLAMADA_FUNCION(NUM_FILA_F," FALTA ) ");return 0;}
                        if(R->DAT_AUT!="parentesis_cierra"){cout<<R->DAT_AUT<<"<--\n";R=R->der;
                            variacion++;
                        }else{
                            PPP=0;
                        }
                    }
                    if(R==NULL){ERROR_SNTXS_LLAMADA_FUNCION(NUM_FILA_F," FALTA ) ");return 0;}
                    if(R->DAT_AUT=="parentesis_cierra"){cout<<R->DAT_AUT<<"\n";R=R->der;
                        if(R==NULL){ERROR_SNTXS_LLAMADA_FUNCION(NUM_FILA_F," FALTA ; ");return 0;}
                        if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                            MANDAR_FUN_LISTA(NOMBRE_FUNCION);

                            cout<<"llamar funcion\n";
                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=3+variacion;
                            return CONTADOR_SALTOS;
                        }else{ERROR_AUTOMATA=1;DATO_FALT_ERROR=" FALTA ; ";}
                    }else{ERROR_AUTOMATA=1;DATO_FALT_ERROR=" FALTA ) ";}
                }else{ERROR_AUTOMATA=1;DATO_FALT_ERROR=" FALTA ( ";}
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR LL_FUN!!!\n\n\n";
                ERROR_SNTXS_LLAMADA_FUNCION(NUM_FILA_F,DATO_FALT_ERROR);
                return 0;
            }

        }return 0;
    }

    int DECLARAR_INT_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata declaraciones int-float-double
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            int NUM_FILA_F=R->NUMERO_FILA;
            string DATO_FALT_ERROR;
            string NOMBRE_FUNCION,TIPO_FUNCION,DATOSTRING;
            if(R->DAT_AUT=="tipo_int"||R->DAT_AUT=="tipo_long"){cout<<R->DAT_AUT<<"\n";TIPO_FUNCION=R->DAT_AUT;R=R->der;
                int variacion=0;
                for(int PPP=1;PPP;){
                if(R==NULL){ERROR_SNTXS_INT(NUM_FILA_F," FALTA VAR ");return 0;}
                if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";NOMBRE_FUNCION=R->DAT; R=R->der;
                    if(R==NULL){ERROR_SNTXS_INT(NUM_FILA_F," FALTA ; || = || , ");return 0;}
                    if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="op_asignacion"||R->DAT_AUT=="OP_coma"){
                        if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_INT(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=2+variacion;
                            cout<<"FIN int\n\n\n";
                            return CONTADOR_SALTOS;

                        }

                        if(R->DAT_AUT=="op_asignacion"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R==NULL){ERROR_SNTXS_INT(NUM_FILA_F," FALTA NUM ");return 0;}
                            if(R->DAT_AUT=="Numero"){cout<<R->DAT<<"\n";DATOSTRING=R->DAT; R=R->der;
                                if(R==NULL){ERROR_SNTXS_INT(NUM_FILA_F," FALTA ; || , ");return 0;}
                                if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="OP_coma"){
                                    if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                            cout<<"INSERTANDO\n";
                                            GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                        }else{
                                            ERROR_SNTXS_INT(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                            cout<<"YA ESTA DECLARADO\n";
                                        }

                                        FIN_AUTOMATA=1;
                                        CONTADOR_SALTOS=4+variacion;
                                        cout<<"FIN int\n\n\n";
                                        return CONTADOR_SALTOS;
                                    }

                                    if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;

                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                            cout<<"INSERTANDO\n";
                                            GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                        }else{
                                            ERROR_SNTXS_INT(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                            cout<<"YA ESTA DECLARADO\n";
                                        }

                                        cout<<"FIN int\n\n\n";
                                        variacion=variacion+4;
                                    }

                                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || , ";}

                            }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA NUM ";}

                        }

                        if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            ///
                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_INT(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            cout<<"FIN int\n\n\n";
                            variacion=variacion+2;
                        }

                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || = || , ";}

                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA VAR ";}
                }
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                ERROR_SNTXS_INT(NUM_FILA_F,DATO_FALT_ERROR);
                return 0;
            }

        }return 0;
    }
    int DECLARAR_FLOAT_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata declaraciones float-double
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;
            int NUM_FILA_F=R->NUMERO_FILA;
            string DATO_FALT_ERROR;
            string NOMBRE_FUNCION,TIPO_FUNCION,DATOINT,DATOFLOAT,DATOSTRING;
            if(R->DAT_AUT=="tipo_float"||R->DAT_AUT=="tipo_double"){cout<<R->DAT_AUT<<"\n";TIPO_FUNCION=R->DAT_AUT;R=R->der;
                int variacion=0;
                for(int PPP=1;PPP;){
                if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA VAR ");return 0;}
                if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";NOMBRE_FUNCION=R->DAT; R=R->der;
                    if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA ; || = || , ");return 0;}
                    if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="op_asignacion"||R->DAT_AUT=="OP_coma"){
                        if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=2+variacion;
                            cout<<"FIN int\n\n\n";
                            return CONTADOR_SALTOS;

                        }

                        if(R->DAT_AUT=="op_asignacion"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA NUM ");return 0;}
                            if(R->DAT_AUT=="Numero"){cout<<R->DAT<<"\n";DATOINT=R->DAT; R=R->der;
                            if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA . || , || ; ");return 0;}
                            if(R->DAT_AUT=="OP_punto"||R->DAT_AUT=="OP_coma"||R->DAT_AUT=="cierra_sentencia"){
                                if(R->DAT_AUT=="OP_punto"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                                   if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA NUM ");return 0;}
                                   if(R->DAT_AUT=="Numero"){cout<<R->DAT<<"\n";DATOFLOAT=R->DAT; R=R->der;
                                        if(R==NULL){ERROR_SNTXS_DOUBLE(NUM_FILA_F," FALTA ; || , ");return 0;}
                                        if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="OP_coma"){
                                            if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                                                DATOSTRING=CONCATENAR_FLOAT(DATOINT,DATOFLOAT);

                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                                }else{
                                                    ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                FIN_AUTOMATA=1;
                                                CONTADOR_SALTOS=6+variacion;
                                                cout<<"FIN int\n\n\n";
                                                return CONTADOR_SALTOS;
                                            }

                                            if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;

                                                DATOSTRING=CONCATENAR_FLOAT(DATOINT,DATOFLOAT);

                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                                }else{
                                                    ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                cout<<"FIN int\n\n\n";
                                                variacion=variacion+6;
                                            }

                                        }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || , ";}

                                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA NUM ";}///
                                }

                                if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;

                                        DATOSTRING=DATOINT;

                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                            cout<<"INSERTANDO\n";
                                            GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                        }else{
                                            ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                            cout<<"YA ESTA DECLARADO\n";
                                        }

                                        cout<<"FIN int\n\n\n";
                                        variacion=variacion+4;
                                }

                                if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                                    DATOSTRING=DATOINT;

                                    GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                    if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                            cout<<"INSERTANDO\n";
                                            GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                    }else{
                                            ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                            cout<<"YA ESTA DECLARADO\n";
                                    }

                                    FIN_AUTOMATA=1;
                                    CONTADOR_SALTOS=4+variacion;
                                    cout<<"FIN int\n\n\n";
                                    return CONTADOR_SALTOS;
                                }

                            }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA . || , || ; ";}

                            }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA NUM ";}///

                        }

                        if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            ///
                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_DOUBLE(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            cout<<"FIN int\n\n\n";
                            variacion=variacion+2;
                        }

                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || = || , ";}

                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA VAR ";}
                }
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                ERROR_SNTXS_DOUBLE(NUM_FILA_F,DATO_FALT_ERROR);///DATO_FALT_ERROR=;
                return 0;
            }

        }return 0;
    }
    int DECLARAR_STRING_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata declaraciones int-float-double
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            int NUM_FILA_F=R->NUMERO_FILA;

            string DATO_FALT_ERROR;
            string NOMBRE_FUNCION,TIPO_FUNCION,DATOSTRING;
            if(R->DAT_AUT=="tipo_string"){cout<<R->DAT_AUT<<"\n";TIPO_FUNCION=R->DAT_AUT;R=R->der;
                int variacion=0;
                for(int PPP=1;PPP;){
                if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA VAR ");return 0;}
                if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";NOMBRE_FUNCION=R->DAT; R=R->der;
                    if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA ; || = || , ");return 0;}
                    if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="op_asignacion"||R->DAT_AUT=="OP_coma"){
                        if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_STRING(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=2+variacion;
                            cout<<"FIN int\n\n\n";
                            return CONTADOR_SALTOS;

                        }

                        if(R->DAT_AUT=="op_asignacion"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA COMILLA DOBLE ");return 0;}
                             if(R->DAT_AUT=="Comilla_Doble"){cout<<R->DAT<<"\n";R=R->der;
                             if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA PALABRAS ");return 0;}
                                if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";DATOSTRING=R->DAT;R=R->der;
                                if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA COMILLA DOBLE ");return 0;}
                                    if(R->DAT_AUT=="Comilla_Doble"){cout<<R->DAT<<"\n";R=R->der;
                                    if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA ; || , ");return 0;}
                                        if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="OP_coma"){
                                            if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                                }else{
                                                    ERROR_SNTXS_STRING(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                FIN_AUTOMATA=1;
                                                CONTADOR_SALTOS=6+variacion;
                                                cout<<"FIN int\n\n\n";
                                                return CONTADOR_SALTOS;
                                            }

                                            if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                                                if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA VAR ");return 0;}
                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATOSTRING);
                                                }else{
                                                    ERROR_SNTXS_STRING(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                cout<<"FIN int\n\n\n";
                                                variacion=variacion+6;
                                            }
                                        }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || , ";}

                                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA COMILLA DOBLE ";}
                                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA PALABRAS ";}
                            }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA COMILLA DOBLE ";}

                        }

                        if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R==NULL){ERROR_SNTXS_STRING(NUM_FILA_F," FALTA VAR ");return 0;}
                            ///
                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_STRING(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            cout<<"FIN int\n\n\n";
                            variacion=variacion+2;
                        }

                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || = || , ";}

                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA VAR ";}
                }
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                ERROR_SNTXS_STRING(NUM_FILA_F,DATO_FALT_ERROR);
                return 0;
            }

        }return 0;
    }
    int DECLARAR_CHAR_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata declaraciones int-float-double
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            int NUM_FILA_F=R->NUMERO_FILA;

            string DATO_FALT_ERROR;
            string NOMBRE_FUNCION,TIPO_FUNCION,DATOSTRING;
            if(R->DAT_AUT=="tipo_char"){cout<<R->DAT_AUT<<"\n";TIPO_FUNCION=R->DAT_AUT;R=R->der;
                int variacion=0;
                for(int PPP=1;PPP;){
                if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA VAR ");return 0;}
                if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";NOMBRE_FUNCION=R->DAT; R=R->der;
                    if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA ; || = || , ");return 0;}
                    if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="op_asignacion"||R->DAT_AUT=="OP_coma"){
                        if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_CHAR(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            FIN_AUTOMATA=1;
                            CONTADOR_SALTOS=2+variacion;
                            cout<<"FIN int\n\n\n";
                            return CONTADOR_SALTOS;

                        }

                        if(R->DAT_AUT=="op_asignacion"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                        if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA COMILLA SIMPLE ");return 0;}
                             if(R->DAT_AUT=="Comilla_Simple"){cout<<R->DAT<<"\n";R=R->der;
                             if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA CARACTER ");return 0;}
                                if(R->DAT_AUT=="Variable"||R->DAT_AUT=="Numero"){cout<<R->DAT<<"\n";DATOSTRING=R->DAT;R=R->der;
                                if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA COMILLA SIMPLE ");return 0;}
                                    if(R->DAT_AUT=="Comilla_Simple"){cout<<R->DAT<<"\n";R=R->der;
                                    if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA ; || , ");return 0;}
                                        if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="OP_coma"){
                                            if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                                                char DATO_CRAR[2];
                                                DATO_CRAR[0]=DATOSTRING[0];
                                                DATO_CRAR[1]='\0';
                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATO_CRAR);
                                                }else{
                                                    ERROR_SNTXS_CHAR(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                FIN_AUTOMATA=1;
                                                CONTADOR_SALTOS=6+variacion;
                                                cout<<"FIN int\n\n\n";
                                                return CONTADOR_SALTOS;
                                            }

                                            if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                                            if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA CARACTER ");return 0;}
                                                char DATO_CRAR[2];
                                                DATO_CRAR[0]=DATOSTRING[0];
                                                DATO_CRAR[1]='\0';
                                                GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                                                if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                                    cout<<"INSERTANDO\n";
                                                    GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,DATO_CRAR);
                                                }else{
                                                    ERROR_SNTXS_CHAR(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                                    cout<<"YA ESTA DECLARADO\n";
                                                }

                                                cout<<"FIN int\n\n\n";
                                                variacion=variacion+6;
                                            }
                                        }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || , ";}

                                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA COMILLA SIMPLE ";}
                                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA CARACTER ";}
                            }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA COMILLA SIMPLE ";}

                        }

                        if(R->DAT_AUT=="OP_coma"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                        if(R==NULL){ERROR_SNTXS_CHAR(NUM_FILA_F," FALTA CARACTER ");return 0;}
                            ///
                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,135,"\0");
                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==0){
                                cout<<"INSERTANDO\n";
                                GLOBALTABLA.InsertarTABLA(val,0,"NORMAL",TIPO_FUNCION,NOMBRE_FUNCION,"NULL");
                            }else{
                                ERROR_SNTXS_CHAR(NUM_FILA_F," LA VARIABLE YA ESTA DECLARADA ");
                                cout<<"YA ESTA DECLARADO\n";
                            }

                            cout<<"FIN int\n\n\n";
                            variacion=variacion+2;
                        }

                    }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA ; || = || , ";}

                }else{ERROR_AUTOMATA=1;PPP=0;DATO_FALT_ERROR=" FALTA VAR ";}
                }
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                ERROR_SNTXS_CHAR(NUM_FILA_F,DATO_FALT_ERROR);
                return 0;
            }

        }return 0;
    }
    int DECLARAR_MOSTRAR_CMD_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            int NUM_FILA_F=R->NUMERO_FILA;

            string DATO_FALT_ERROR;
            string VARIABLE_MOSTRAR;
            if(R->DAT_AUT=="mostrar"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                int variacion=0;
                for(int PP=1;PP;){
                    if(R==NULL){ERROR_SNTXS_COUT(NUM_FILA_F," FALTA << ");return 0;}
                    if(R->DAT_AUT=="doble_menor"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                    if(R==NULL){ERROR_SNTXS_COUT(NUM_FILA_F," FALTA COMILLA DOBLE || PAL || ENDL ");return 0;}
                        if(R->DAT_AUT=="Comilla_Doble"||R->DAT_AUT=="Variable"||R->DAT_AUT=="mostrar_salto_de_linea"){
                            if(R->DAT_AUT=="Comilla_Doble"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                                cout<<"PRINTF::CMD ->>    || ";
                                for(int TTT=1;TTT;){
                                    if(R->DAT_AUT=="Comilla_Doble"){cout<<endl<<R->DAT_AUT<<"\n"; R=R->der;
                                        if(R==NULL){ERROR_SNTXS_COUT(NUM_FILA_F," FALTA ; || << ");return 0;}
                                        if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="doble_menor"){
                                            if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                                                cout<<"MOSTRAR CMD \n";
                                                FIN_AUTOMATA=1;
                                                CONTADOR_SALTOS+=(4+variacion);
                                                cout<<"FIN int\n\n\n";
                                                return CONTADOR_SALTOS;
                                            }
                                            if(R->DAT_AUT=="doble_menor"){cout<<R->DAT_AUT<<"\n";
                                                variacion=variacion+3;
                                                cout<<"FIN int\n\n\n";
                                                TTT=0;
                                            }

                                        }else{ERROR_AUTOMATA=1;TTT=0;PP=0;DATO_FALT_ERROR=" FALTA ; || << ";}

                                    }else{
                                        if((int)(R->DAT[0])==92&& R->DAT[1]=='n'){
                                            cout<<"\n                   || ";
                                        }else if((int)(R->DAT[0])==92&& R->DAT[1]=='t'){
                                            cout<<"\t";
                                        }else{
                                            cout<<R->DAT<<" ";
                                        }
                                        CONTADOR_SALTOS+=1;
                                        R=R->der;
                                    }
                                }
                            }

                            if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";VARIABLE_MOSTRAR=R->DAT; R=R->der;
                            if(R==NULL){ERROR_SNTXS_COUT(NUM_FILA_F," FALTA ; || << ");return 0;}
                                if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="doble_menor"){
                                    if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";

                                        FIN_AUTOMATA=1;
                                        CONTADOR_SALTOS+=(3+variacion);

                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL","\0",VARIABLE_MOSTRAR,135,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS){
                                            cout<<"PRINTF::CMD ->>    || "<<VALOR_DATO;
                                        }else{
                                            ERROR_SNTXS_COUT(NUM_FILA_F," VARIABLE NO DECLARADA ");
                                            cout<<"VARIABLE NO DECLARADA\n";
                                        }
                                        cout<<"\nFIN int\n\n\n";
                                        return CONTADOR_SALTOS;
                                    }

                                    if(R->DAT_AUT=="doble_menor"){cout<<R->DAT_AUT<<"\n";
                                        variacion=variacion+2;
                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL","\0",VARIABLE_MOSTRAR,135,"\0");
                                        if(BUSQUEDA_TABLA_DE_SIMBOLOS){
                                            cout<<"PRINTF::CMD ->>    || "<<VALOR_DATO;
                                        }else{
                                            ERROR_SNTXS_COUT(NUM_FILA_F," VARIABLE NO DECLARADA ");
                                            cout<<"VARIABLE NO DECLARADA\n";
                                        }
                                        cout<<"\nFIN int\n\n\n";
                                    }
                                }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA ; || << ";}
                            }

                            if(R->DAT_AUT=="mostrar_salto_de_linea"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            if(R==NULL){ERROR_SNTXS_COUT(NUM_FILA_F," FALTA ; || << ");return 0;}
                                if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="doble_menor"){
                                    if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                                        cout<<"PRINTF::CMD ->>    || \n";
                                        FIN_AUTOMATA=1;
                                        CONTADOR_SALTOS+=(3+variacion);
                                        cout<<"FIN int\n\n\n";
                                        return CONTADOR_SALTOS;
                                    }
                                    if(R->DAT_AUT=="doble_menor"){cout<<R->DAT_AUT<<"\n";
                                        cout<<"PRINTF::CMD ->>    || \n";
                                        variacion=variacion+2;
                                        cout<<"FIN int\n\n\n";
                                    }
                                }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA ; || << ";}
                            }
                        }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA COMILLA DOBLE || PAL || ENDL ";}
                    }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA << ";}
                }
            }
            if(ERROR_AUTOMATA){
                    cout<<"ERROR LL_FUN!!!\n\n\n";
                    ERROR_SNTXS_COUT(NUM_FILA_F,DATO_FALT_ERROR);
                    return 0;
            }
        }return 0;
    }
    int DECLARAR_CIN_TRES(NODOLIST_FUN *R,string val){
        cout<<endl;
        ///automata declaraciones int-float-double
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;
            int NUM_FILA_F=R->NUMERO_FILA;

            string DATO_FALT_ERROR;
            string INTRODUCIR_CIN,DATOSTRING;
            if(R->DAT_AUT=="entrada_dato"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                int variacion=0;
                for(int PP=1;PP;){
                    if(R==NULL){ERROR_SNTXS_CIN(NUM_FILA_F," FALTA >> ");return 0;}
                    if(R->DAT_AUT=="doble_mayor"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                        if(R==NULL){ERROR_SNTXS_CIN(NUM_FILA_F," FALTA VAR ");return 0;}
                        if(R->DAT_AUT=="Variable"){cout<<R->DAT<<"\n";DATOSTRING=R->DAT; R=R->der;
                            if(R==NULL){ERROR_SNTXS_CIN(NUM_FILA_F," FALTA >> || ; ");return 0;}

                            GLOBALTABLA.BuscarTABLA(val,0,"NORMAL","\0",DATOSTRING,135,"\0");

                            cout<<BUSQUEDA_TABLA_DE_SIMBOLOS<<endl;
                            cout<<TIPO_DE_DATO<<endl;


                            if(BUSQUEDA_TABLA_DE_SIMBOLOS==1){
                                cout<<" CIN >>  "<<DATOSTRING<<"\t   || ";
                                cin>>INTRODUCIR_CIN;
                                if(TIPO_DE_DATO=="tipo_string"){
                                    GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_DE_DATO,DATOSTRING,1356,INTRODUCIR_CIN);
                                }
                                if(TIPO_DE_DATO=="tipo_char"){
                                    char DATO_CHARR[2];
                                    DATO_CHARR[0]=INTRODUCIR_CIN[0];
                                    DATO_CHARR[1]='\0';
                                    GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_DE_DATO,DATOSTRING,1356,DATO_CHARR);

                                }
                                if(TIPO_DE_DATO=="tipo_int"||TIPO_DE_DATO=="tipo_long"){
                                    if(TipoDATO_CIN(INTRODUCIR_CIN)=="tipo_int"||TipoDATO_CIN(INTRODUCIR_CIN)=="tipo_float"){

                                        INTRODUCIR_CIN=RETURN_INT_D(INTRODUCIR_CIN);

                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_DE_DATO,DATOSTRING,1356,INTRODUCIR_CIN);
                                    }
                                }
                                if(TIPO_DE_DATO=="tipo_float"||TIPO_DE_DATO=="tipo_double"){
                                    if(TipoDATO_CIN(INTRODUCIR_CIN)=="tipo_int"||TipoDATO_CIN(INTRODUCIR_CIN)=="tipo_float"){

                                        GLOBALTABLA.BuscarTABLA(val,0,"NORMAL",TIPO_DE_DATO,DATOSTRING,1356,INTRODUCIR_CIN);
                                    }
                                }
                            }else{
                                ERROR_SNTXS_CIN(NUM_FILA_F," VARIABLE NO ESTA DECLARADO!! ");
                                cout<<"NO EXISTE VARIABLE\n";
                            }
                            if(R==NULL){ERROR_SNTXS_CIN(NUM_FILA_F," FALTA >> || ; ");return 0;}
                            if(R->DAT_AUT=="cierra_sentencia"||R->DAT_AUT=="doble_mayor"){
                                if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                                    FIN_AUTOMATA=1;
                                    CONTADOR_SALTOS+=(3+variacion);
                                    cout<<"FIN int\n\n\n";
                                    return CONTADOR_SALTOS;
                                }
                                if(R->DAT_AUT=="doble_mayor"){cout<<R->DAT_AUT<<"\n";

                                    variacion=variacion+2;
                                    cout<<"FIN int\n\n\n";
                                }
                            }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA >> || ; ";}
                        }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA VAR ";}
                    }else{ERROR_AUTOMATA=1;PP=0;DATO_FALT_ERROR=" FALTA >> ";}
                }
            }

            if(ERROR_AUTOMATA){
                cout<<"ERROR int!!!\n\n\n";
                ERROR_SNTXS_CIN(NUM_FILA_F,DATO_FALT_ERROR);
                return 0;
            }

        }return 0;
    }
    int DECLARAR_INCLUDE_TRES(NODOLIST_FUN *R){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;

            if(R->DAT_AUT=="hastack"){cout<<R->DAT_AUT<<"\n"; R=R->der;
				if(R->DAT_AUT=="incluir_lib"){cout<<R->DAT_AUT<<"\n"; R=R->der;
					if(R->DAT_AUT=="comp_menor"){cout<<R->DAT_AUT<<"\n"; R=R->der;
						if(R->DAT_AUT=="Variable"){cout<<R->DAT_AUT<<"\n"; R=R->der;
							if(R->DAT_AUT=="comp_mayor"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                                cout<<"INCLUDE: \n";
                                FIN_AUTOMATA=1;
                                CONTADOR_SALTOS=4;
                                cout<<"FIN int\n\n\n";
                                return CONTADOR_SALTOS;

							}else{ERROR_AUTOMATA=1;}

						}else{ERROR_AUTOMATA=1;}

					}else{ERROR_AUTOMATA=1;}

				}else{ERROR_AUTOMATA=1;}

			}

        if(ERROR_AUTOMATA){
            cout<<"ERROR INCLUDE!!!\n\n\n";
            return 0;
        }

        }return 0;
    }
    int DECLARAR_USING_TRES(NODOLIST_FUN *R){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            CONTADOR_SALTOS=0;
            FIN_AUTOMATA=0;
            ERROR_AUTOMATA=0;
            if(R->DAT_AUT=="usar_lib"){cout<<R->DAT_AUT<<"\n"; R=R->der;
				if(R->DAT_AUT=="maespace_lib"){cout<<R->DAT_AUT<<"\n"; R=R->der;
					if(R->DAT_AUT=="estandar_lib"){cout<<R->DAT_AUT<<"\n"; R=R->der;
						if(R->DAT_AUT=="cierra_sentencia"){cout<<R->DAT_AUT<<"\n";
                                cout<<"USING: \n";
                                FIN_AUTOMATA=1;
                                CONTADOR_SALTOS=3;
                                cout<<"FIN int\n\n\n";
                                return CONTADOR_SALTOS;
						}else{ERROR_AUTOMATA=1;}

					}else{ERROR_AUTOMATA=1;}

				}else{ERROR_AUTOMATA=1;}

			}

        if(ERROR_AUTOMATA){
            cout<<"ERROR INCLUDE!!!\n\n\n";
            return 0;
        }

        }return 0;
    }


    ///AUTOMATAS A DECLARAR
    void EJECUTAR_PARAM(NODOLIST_FUN *R,string val){ ///EJECUTAR FUNCIONES DE PARAMETRO
        if(R!=NULL){
            int SALTOS,i;

            SALTOS=DECLARAR_PARAMETR_INT_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            if(R!=NULL){
                cout<<R->DAT<<" NULL_AUTOMATA_PARAMETRO <===>\n";
                EJECUTAR_PARAM(R->der,val);
            }
        }

    }

    void EJECUTAR(NODOLIST_FUN *R,string val){ ///EJECUTAR FUNCIONES
        if(R!=NULL){
            int SALTOS,i;

            SALTOS=DECLARAR_INCLUDE_TRES(R);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_USING_TRES(R);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_INT_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_FLOAT_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_STRING_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_CHAR_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_LLAMADA_FUNCION(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_MOSTRAR_CMD_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            SALTOS=DECLARAR_CIN_TRES(R,val);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;


            if(R!=NULL){
                cout<<R->DAT<<" NULL_AUTOMATA_FUNCION <===>\n";
                EJECUTAR(R->der,val);
            }
        }

    }
    ///AUTOMATAS A DECLARAR

    void BuscarLIST(string dat){
         Bus(raiz,dat);
    }
    void Bus(NODOLIST_FUN *R,string val){

         if(R!=NULL){
            Bus(R->der,val);
            if(R->DAT==val){
                 cout<<R->DAT<<"\n\n";
            }
         }
    }
};
///LISTA

///ARBOL DE FUNCIONES
class NODO_FUNC{
    public:
    string dato,FUNTIPO_DAT;
    LISTA_FUN listFUN,listPARAM;
    NODO_FUNC *izq,*der,*PaDr;
    NODO_FUNC(string D="\0",string FUNTIPODAT="\0",NODO_FUNC *Padr=NULL,NODO_FUNC *iz=NULL,NODO_FUNC *de=NULL){
         dato=D;
         FUNTIPO_DAT=FUNTIPODAT;
         izq=iz;
         der=de;
         PaDr=Padr;
    }
    void set_ListFUN(string DAT="\0",string DAT_AUTOMATA="\0",int NUM_FIL=0){
        listFUN.InsertarLIST(DAT,DAT_AUTOMATA,NUM_FIL);
    }
    void set_ListPARAM(string DAT="\0",string DAT_AUTOMATA="\0",int NUM_FIL=0){
        listPARAM.InsertarLIST(DAT,DAT_AUTOMATA,NUM_FIL);
    }
    LISTA_FUN get_ListFUN(){
        return listFUN;
    }
    LISTA_FUN get_ListPARAM(){
        return listPARAM;
    }
};

class ARBOL_FUNC{
    public:
    NODO_FUNC *raiz,*padr;
    ARBOL_FUNC(){
        raiz=NULL;
        padr=NULL;
    }
    void InsertarARBOLFUN(string D,string FUNTIPODAT){
         Ins(D,FUNTIPODAT,raiz,padr);
    }
    void Ins(string D,string FUNTIPODAT,NODO_FUNC *&R,NODO_FUNC *padr){
         if(R==NULL){
            R=new NODO_FUNC(D,FUNTIPODAT,padr);
         }
         else if(D<R->dato){
            Ins(D,FUNTIPODAT,R->izq,R);
         }
         else{
            Ins(D,FUNTIPODAT,R->der,R);
         }
    }
    void MostrarARBOL_FUN(){
         Mos(raiz,0);
    }
    void Mos(NODO_FUNC *R,int C){
         if(R!=NULL){
            Mos(R->der,C+1);
            for(int i=0;i<C;i++){cout<<"   ";}
            ///EJECUTAR CODIGO

                ///EJECUTAR_FUNCIONES(R->dato);

            ///EJECUTAR CODIGO
            cout<<R->dato;
            cout<<"  "<<R->FUNTIPO_DAT;
            cout<<" ->> PARAMETRO: ";R->listPARAM.MostrarLIST();
            cout<<" ->> NORMAL: ";R->listFUN.MostrarLIST();cout<<"\n\n";
            Mos(R->izq,C+1);
         }

    }
    void insertarFUN_dato(string dat,string newFUN_dato,string DAT_AUTOMATA,int NUM_FIL){
         busFUN(raiz,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
    }
    void busFUN(NODO_FUNC *R,string dat,string newFUN_dato,string DAT_AUTOMATA,int NUM_FIL){
         if(R!=NULL){
            if(R->dato==dat){
                R->set_ListFUN(newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }
            else if(R->dato>dat){
                busFUN(R->izq,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }else{
                busFUN(R->der,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }
         }
    }
    void insertarPARAM_dato(string dat,string newFUN_dato,string DAT_AUTOMATA,int NUM_FIL){
         busPARAM(raiz,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
    }
    void busPARAM(NODO_FUNC *R,string dat,string newFUN_dato,string DAT_AUTOMATA,int NUM_FIL){
         if(R!=NULL){
            if(R->dato==dat){
                R->set_ListPARAM(newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }
            else if(R->dato>dat){
                busPARAM(R->izq,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }else{
                busPARAM(R->der,dat,newFUN_dato,DAT_AUTOMATA,NUM_FIL);
            }
         }
    }
    void EJECUTAR_FUNCIONES(string dat){
         EJEC_FUN_PARAM(raiz,dat);
         EJEC_FUN(raiz,dat);                                   //////////////////////////////
    }
    void EJEC_FUN_PARAM(NODO_FUNC *R,string val){
         if(R!=NULL){
            if(R->dato==val){
                R->get_ListPARAM().EJECUTAR_CODIGO_PARAM(val);
                cout<<endl;
            }
            else if(R->dato>val){
                EJEC_FUN_PARAM(R->izq,val);
            }else{
                EJEC_FUN_PARAM(R->der,val);
            }
         }
    }
    void EJEC_FUN(NODO_FUNC *R,string val){
         if(R!=NULL){
            if(R->dato==val){
                cout<<R->dato<<" ----> ";
                R->get_ListFUN().EJECUTAR_CODIGO(val);
                cout<<endl;
            }
            else if(R->dato>val){
                EJEC_FUN(R->izq,val);
            }else{
                EJEC_FUN(R->der,val);
            }
         }
    }
};

ARBOL_FUNC FUNCIONES;

void MANDAR_FUN_LISTA(string val){
     FUNCIONES.EJECUTAR_FUNCIONES(val);
}

///ARBOL DE FUNCIONES

///lista almacena
class NODOLIST{
    public:
    string DAT,NOMB_DAT;
    int NuMeRo_FiLa;
    NODOLIST *der,*PaDr;
    NODOLIST(string D="\0",string NOMBRE_DAT="\0",int Num_FILA=0,NODOLIST *Padr=NULL,NODOLIST *de=NULL){
         DAT=D;
         NOMB_DAT=NOMBRE_DAT;
         NuMeRo_FiLa=Num_FILA;
         der=de;
         PaDr=Padr;
    }
};
class LISTA{
    public:
    NODOLIST *raiz,*padr;
    LISTA(){
        raiz=NULL;
        padr=NULL;
    }
    void InsertarLIST(string D,string NOMBRE_DAT,int Num_FIL){
         ins(D,NOMBRE_DAT,Num_FIL,raiz,padr);
    }
    void ins(string D,string NOMBRE_DAT,int Num_FIL,NODOLIST *&R,NODOLIST *padr){
         if(R==NULL)
            R=new NODOLIST(D,NOMBRE_DAT,Num_FIL,padr);
         else
            ins(D,NOMBRE_DAT,Num_FIL,R->der,R);
    }
    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODOLIST *R){
         if(R!=NULL){
            cout<<R->DAT<<" ";
            cout<<R->NOMB_DAT<<" ";
            cout<<R->NuMeRo_FiLa<<" --->   ";
            Mos(R->der);
         }
    }



    bool TIPO_DE_DATO(string TPDAT){
        if(TPDAT=="tipo_int"||TPDAT=="tipo_float"||TPDAT=="tipo_double"||TPDAT=="tipo_long"||TPDAT=="tipo_char"||TPDAT=="tipo_string"){
            return true;
        }else{
            return false;
        }
    }
    void AUTOMATA_LIST(){
        IN_LIST_TRES(raiz);
    }
    void IN_LIST(NODOLIST *R){
        bool FIN_AUTOMATA=0;
        bool ERROR_AUTOMATA=0;

        if(R!=NULL){

            string NOMBRE_FUNCION,TIPO_FUNCION;
            ///automata funciones
            if(TIPO_DE_DATO(R->DAT)){cout<<R->DAT<<"\n";TIPO_FUNCION=R->DAT;R=R->der;
                if(R->DAT=="Variable"){cout<<R->NOMB_DAT<<"\n";NOMBRE_FUNCION=R->NOMB_DAT;R=R->der;
                    if(R->DAT=="parentesis_abre"){cout<<R->DAT<<"\n";R=R->der;
                        if(R->DAT=="parentesis_cierra"||R->DAT=="llave_abre"){

                            if(R->DAT=="parentesis_cierra"){cout<<R->DAT<<"\n";R=R->der;
                                if(R->DAT=="cierra_sentencia"){cout<<R->DAT<<"\n";
                                    cout<<"MANDAR FUNCION\n";
                                    FIN_AUTOMATA=1;
                                }else{ERROR_AUTOMATA=1;}
                            }else{ERROR_AUTOMATA=1;}


                            int LLAVECONT=0;
                            if(R->DAT=="llave_abre"){cout<<R->DAT<<"\n";
                                FUNCIONES.InsertarARBOLFUN(NOMBRE_FUNCION,TIPO_FUNCION);
                                FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                R=R->der;
                                LLAVECONT++;
                                for(;;){

                                    if(R->DAT=="llave_abre"||R->DAT=="llave_cierra"){
                                        if(R->DAT=="llave_abre"){
                                            FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                            cout<<R->DAT<<"\n";
                                            LLAVECONT++;
                                        }
                                        if(R->DAT=="llave_cierra"){
                                            FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                            cout<<R->DAT<<"\n";
                                            LLAVECONT--;
                                        }if(LLAVECONT!=0){
                                            R=R->der;
                                        }
                                    }else{
                                        cout<<"CONTENIDO\n";
                                        FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                        R=R->der;
                                    }
                                    if(LLAVECONT==0){
                                        FIN_AUTOMATA=1;break;
                                    }
                                }
                            }

                        }else{ERROR_AUTOMATA=1;}
                    }else{
                        R=R->PaDr->PaDr;
                        ERROR_AUTOMATA=1;
                    }
                }else{ERROR_AUTOMATA=1;}
            }
            if(R!=NULL){
                if(FIN_AUTOMATA){
                    cout<<"FIN\n\n";
                    IN_LIST(R->der);
                }else{
                    if(ERROR_AUTOMATA){
                        cout<<"ERROR!!!\n\n\n";
                    }
                        if(R->DAT=="Variable"||R->DAT=="Numero"){
                            FUNCIONES.insertarFUN_dato("GLOBAL_FUNCIONª",R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                            cout<<"--"<<R->NOMB_DAT<<"\n";
                        }else{
                            FUNCIONES.insertarFUN_dato("GLOBAL_FUNCIONª",R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                            cout<<"--"<<R->DAT<<"\n";
                        }


                        IN_LIST(R->der);

                }
            }

            ///automata funciones
        }
    }

    void IN_LIST_TRES(NODOLIST *R){
        bool FIN_AUTOMATA=0;
        bool ERROR_AUTOMATA=0;

        if(R!=NULL){

            string NOMBRE_FUNCION,TIPO_FUNCION;
            ///automata funciones
            if(TIPO_DE_DATO(R->DAT)){cout<<R->DAT<<"\n";TIPO_FUNCION=R->DAT; R=R->der;
                if(R->DAT=="Variable"){cout<<R->NOMB_DAT<<"\n";NOMBRE_FUNCION=R->NOMB_DAT; R=R->der;
                    if(R->DAT=="parentesis_abre"){cout<<R->DAT<<"\n"; R=R->der;
                        if(TIPO_DE_DATO(R->DAT)||R->DAT=="parentesis_cierra"){

                            FUNCIONES.InsertarARBOLFUN(NOMBRE_FUNCION,TIPO_FUNCION);

                            if(TIPO_DE_DATO(R->DAT)){cout<<R->DAT<<"\n";

                                for(int PPT=1;PPT;){
                                    if(R->DAT=="parentesis_cierra"){
                                        cout<<"\nPARAMETROS\n";
                                        PPT=0;
                                    }else{
                                        FUNCIONES.insertarPARAM_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                        R=R->der;
                                    }
                                }

                            }

                            if(R->DAT=="parentesis_cierra"){cout<<R->DAT<<"\n"; R=R->der;
                                if(R->DAT=="llave_abre"){cout<<R->DAT<<"\n"; R=R->der;

                                    for(int PPP=1;PPP;){

                                        if(R->DAT=="llave_abre"||R->DAT=="llave_cierra"){
                                            if(R->DAT=="llave_abre"){cout<<R->DAT<<"\n";
                                                FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                                PPP++;
                                            }
                                            if(R->DAT=="llave_cierra"){cout<<R->DAT<<"\n";
                                                PPP--;
                                                if(PPP){
                                                    FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                                }
                                            }

                                            R=R->der;

                                        }else{
                                            cout<<"CONTENIDO\n";
                                            FUNCIONES.insertarFUN_dato(NOMBRE_FUNCION,R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                                            R=R->der;
                                        }

                                    }FIN_AUTOMATA=1;
                                }
                            }

                        }else{ERROR_AUTOMATA=1;}

                    }else{
                        R=R->PaDr->PaDr;
                        ERROR_AUTOMATA=1;
                    }

                }else{ERROR_AUTOMATA=1;}

            }
            if(R!=NULL){
                if(FIN_AUTOMATA){
                    cout<<"FIN\n\n";
                    IN_LIST_TRES(R);
                }else{

                    if(ERROR_AUTOMATA){
                        cout<<"ERROR!!!\n\n\n";
                    }
                    FUNCIONES.insertarFUN_dato("GLOBAL_FUNCIONª",R->NOMB_DAT,R->DAT,R->NuMeRo_FiLa);
                    cout<<"--"<<R->NOMB_DAT<<"\n";

                    IN_LIST_TRES(R->der);
                }
            }

            ///automata funciones
        }
    }

    void BuscarLIST(string dat){
         Bus(raiz,dat);
    }
    void Bus(NODOLIST *R,string val){
         if(R!=NULL){
            Bus(R->der,val);
            if(R->DAT==val){
                 cout<<R->DAT<<"\n\n";
            }
         }
    }
};
///LISTA DE PALABRAS
LISTA PALABRAS;
///LISTA DE PALABRAS

void INSERT_LIST_ERRORES(int LIneA,string MessaGEE){

}

///ARBOL ADAPTABLE
template <class T>
class Nodo{
    public:
    T dato;
    T TIPO;
    Nodo<T> *izq;
    Nodo<T> *der;
    Nodo(T d,T tipo){
        this->dato = d;
        this->TIPO = tipo;
        izq = der = NULL;
    }
    Nodo<T> *RetHijoIzq(){
        return izq;
    }
    Nodo<T> *RetHijoDer(){
        return der;
    }
    void AsigHijoIzq(Nodo<T> *i){
        izq = i;
    }
    void AsigHijoDer(Nodo<T> *d){
        der = d;
    }
    void AsigDato(T d){
        dato = d;
    }
    void AsigTipo(T tipo){
        TIPO = tipo;
    }
    T RetDato(){
        return dato;
    }
    T RetTipo(){
        return TIPO;
    }
};
template <class T>
class ArbolADAPTABLE{
    private:
    Nodo<T> *raiz;
    void Insert(Nodo<T> *r, Nodo<T> *n){
        if(n->RetDato() < r->RetDato()){
            if(r->RetHijoIzq() == NULL)
                r->AsigHijoIzq(n);
            else
                Insert(r->RetHijoIzq(), n);
        }
        else{
            if(r->RetHijoDer() == NULL)
                r->AsigHijoDer(n);
            else
                Insert(r->RetHijoDer(), n);
        }
    }
    int Altura(Nodo<T> *r){
        if(r == NULL)
            return 0;
        else
            return 1 + max(Altura(r->RetHijoIzq()), Altura(r->RetHijoDer()));
    }

    int NumNodo(Nodo<T> *r){
        if(r == NULL)
            return 0;
        else
            return 1 + NumNodo(r->RetHijoIzq()) + NumNodo(r->RetHijoDer());
    }
    public:
    int NumNodo(){
        return NumNodo(raiz);
    }

    Nodo<T> *BuscarR(T valor){
        return Buscar(raiz, valor);
    }
    Nodo<T> *Buscar(Nodo<T> *r, T valor){
        if(r == NULL){
            return NULL;
        }
        if(r->RetDato() == valor){
            return r;
        }
        else if(r->RetDato() > valor){
            return Buscar(r->RetHijoIzq(), valor);
        }
        else{
            return Buscar(r->RetHijoDer(), valor);
        }
    }

    int Altura(){
        return Altura(raiz);
    }
    ArbolADAPTABLE(){
        raiz = NULL;
    }
    ArbolADAPTABLE(Nodo<T> *n){
        raiz = n;
    }
    void Insertar(T valor,T tipo){
        Nodo<T>* n = new Nodo<T>(valor,tipo);
        if (raiz == NULL)
            raiz = n;
        else
            Insert(raiz, n);
    }
    void Mostrar(){
        int c=0;
        Mos(raiz,c);
    }
    void Mos(Nodo<T> *r, int cont){
        if(r!=NULL){
            Mos(r->RetHijoDer(),cont+1);
            for(int i=0;i<cont;i++){
                cout<<"     ";
            }
            cout<<r->RetDato()<<" "<<r->RetTipo()<<endl;
            Mos(r->RetHijoIzq(),cont+1);
        }
    }
};
///ARBOL ADAPTABLE

///SINTAXIS
class MIS_DATOS{
        public:
        ArbolADAPTABLE<string> *SINTAXIS;
        int INTRO_SINTAXIS(){
            SINTAXIS = new ArbolADAPTABLE<string>();
            SINTAXIS->Insertar("int","tipo_int");
            SINTAXIS->Insertar("float","tipo_float");
            SINTAXIS->Insertar("double","tipo_double");
            SINTAXIS->Insertar("long","tipo_long");
            SINTAXIS->Insertar("char","tipo_char");
            SINTAXIS->Insertar("string","tipo_string");
            SINTAXIS->Insertar("+","op_mas");
            SINTAXIS->Insertar("-","op_menos");
            SINTAXIS->Insertar("*","op_multiplica");
            SINTAXIS->Insertar("/","op_divicion");
            SINTAXIS->Insertar("=","op_asignacion");
            SINTAXIS->Insertar("||","op_O");
            SINTAXIS->Insertar("&&","op_Y");
            SINTAXIS->Insertar("==","comp_igual");
            SINTAXIS->Insertar("<=","comp_menor_igual");
            SINTAXIS->Insertar(">=","comp_mayor_igual");
            SINTAXIS->Insertar("<<","doble_menor");
            SINTAXIS->Insertar(">>","doble_mayor");
            SINTAXIS->Insertar("<","comp_menor");
            SINTAXIS->Insertar(">","comp_mayor");
            SINTAXIS->Insertar("{","llave_abre");
            SINTAXIS->Insertar("}","llave_cierra");
            SINTAXIS->Insertar("(","parentesis_abre");
            SINTAXIS->Insertar(")","parentesis_cierra");
            SINTAXIS->Insertar(";","cierra_sentencia");
            SINTAXIS->Insertar("return","retorna_dato");
            SINTAXIS->Insertar("cout","mostrar");
            SINTAXIS->Insertar("cin","entrada_dato");
            SINTAXIS->Insertar("endl","mostrar_salto_de_linea");
            SINTAXIS->Insertar("for","bucle_for");
            SINTAXIS->Insertar("while","bucle_while");
            SINTAXIS->Insertar("if","Condicion_if");
            SINTAXIS->Insertar(".","OP_punto");
            SINTAXIS->Insertar(",","OP_coma");
            SINTAXIS->Insertar("'","Comilla_Simple");
            SINTAXIS->Insertar("++","Doble_Incremento");
            SINTAXIS->Insertar("--","Doble_Decremento");
            SINTAXIS->Insertar("#","hastack");
            SINTAXIS->Insertar("include","incluir_lib");
            SINTAXIS->Insertar("using","usar_lib");
            SINTAXIS->Insertar("namespace","maespace_lib");
            SINTAXIS->Insertar("std","estandar_lib");
            return 0;
        }
        bool validaNUM(char N){
            for(char i='0';i<='9';i++){
                if(i==N){
                    return true;
                }
            }return false;
        }
        bool NUMEROS(char *NUM){
            int Limite=0,Corte=0;
            for(;*(NUM+Limite);Limite++){
                if(validaNUM(*(NUM+Limite))==true){
                    Corte++;
                }
            }
            if(Limite==Corte){
                return true;
            }return false;
        }

        string busqueda(char *dato){
            if(SINTAXIS->BuscarR(dato)!=NULL){
                return SINTAXIS->BuscarR(dato)->TIPO;
            }
            else if(NUMEROS(dato)==1){
                return "Numero";
            }
            else if((int)dato[0]==34){
                return "Comilla_Doble";
            }
            else{
                return "Variable";
            }
        }

        void mostrar(){

            printf("\n\n");
            SINTAXIS->Mostrar();
            printf("\n\n");

        }
};

MIS_DATOS SINTAXXI;
///SINTAXIS


///SELECCIONA Y SEPARA
void Separar(char *CadINI,int Num_FILA){

    int i,j,ESPACIO=0;
    char *cad;

    for(i=0;*(CadINI+i);i++);
    cad=new char[i+1000];
    cout<<"-CAD_ENTRADA:"<<CadINI<<endl;
    for(i=0,j=0;*(CadINI+i);i++){
        if(*(CadINI+i)!=' '&&i==0){
            *(cad+0)=' ';j++;
        }
        if(*(CadINI+i)=='#'||*(CadINI+i)=='('||*(CadINI+i)==')'||*(CadINI+i)=='{'||*(CadINI+i)=='}'||*(CadINI+i)==';'||*(CadINI+i)==','||*(CadINI+i)=='.'||*(CadINI+i)=='"'||*(CadINI+i)=='+'||*(CadINI+i)=='-'||*(CadINI+i)=='*'||*(CadINI+i)=='/'||*(CadINI+i)=='<'||*(CadINI+i)=='>'||*(CadINI+i)=='='||*(CadINI+i)=='|'||*(CadINI+i)=='&'||*(CadINI+i)=='?'||*(CadINI+i)==':'||(int)*(CadINI+i)==39){
            if(*(cad+j-1)!=' '){
                *(cad+j)=' ';j++;
            }
            if(*(CadINI+i)=='<'&&*(CadINI+i+1)=='='){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='>'&&*(CadINI+i+1)=='='){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='='&&*(CadINI+i+1)=='='){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='&'&&*(CadINI+i+1)=='&'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='|'&&*(CadINI+i+1)=='|'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='+'&&*(CadINI+i+1)=='+'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='-'&&*(CadINI+i+1)=='-'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='-'&&*(CadINI+i+1)=='>'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='<'&&*(CadINI+i+1)=='-'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='<'&&*(CadINI+i+1)=='<'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
            if(*(CadINI+i)=='>'&&*(CadINI+i+1)=='>'){
                *(cad+j)=*(CadINI+i);j++;
                *(cad+j)=*(CadINI+i+1);j++;i+=2;
            }
        }
        if(*(CadINI+i)==' '&&ESPACIO==0){
            if(*(cad+j-1)!=' '){
                *(cad+j)=' ';ESPACIO++,j++;
            }
        }
        if(*(CadINI+i)!=' '){
            if(*(cad+j-1)=='#'||*(cad+j-1)=='('||*(cad+j-1)==')'||*(cad+j-1)=='{'||*(cad+j-1)=='}'||*(cad+j-1)==';'||*(cad+j-1)==','||*(cad+j-1)=='.'||*(cad+j-1)=='"'||*(cad+j-1)=='+'||*(cad+j-1)=='-'||*(cad+j-1)=='*'||*(cad+j-1)=='/'||*(cad+j-1)=='<'||*(cad+j-1)=='>'||*(cad+j-1)=='='||*(cad+j-1)=='|'||*(cad+j-1)=='&'||*(cad+j-1)=='?'||*(cad+j-1)==':'||(int)*(cad+j-1)==39||(int)*(cad+j-1)=='\t'){
                *(cad+j)=' ';j++;
            }
            *(cad+j)=*(CadINI+i);j++;ESPACIO=0;
        }
    }*(cad+j)='\0';
    cout<<"-CAD_ORDEN  :"<<cad<<"\n";

    char **CAD_FINAL;
    int NC=0,NP=0,in=0,fin=0;
    for(i=0;*(cad+i);i++){
        if(*(cad+i)==' '){NP++;}
    }
    CAD_FINAL=new char*[NP+15];
    NP=0;

    for(i=0;*(cad+i);i++){
        if(*(cad+i)==' '&&*(cad+i+1)!=' '){
            int pl;in=i+1;
            for(fin=in;*(cad+fin)!=' '&&*(cad+fin);fin++){NC++;}

            CAD_FINAL[NP]=new char[NC+15];

            for(pl=0;in<fin;in++,pl++){
                *(*(CAD_FINAL+NP)+pl)=*(cad+in);
            }

            *(*(CAD_FINAL+NP)+pl)='\0';
            NP++;NC=0;
        }
    }

    ///DATOS SEPARADOS

    for(i=0;i<NP;i++){
        string TipoDAT;
        if((int)*(*(CAD_FINAL+i)+0)!=0){
            TipoDAT=SINTAXXI.busqueda(*(CAD_FINAL+i));
            for(j=0;TipoDAT[j];j++);
            cout<<TipoDAT;
            for(;j<20;j++){cout<<" ";}
            //PALABRAS.InsertarLIST(*(CAD_FINAL+i));
            PALABRAS.InsertarLIST(TipoDAT,*(CAD_FINAL+i),Num_FILA);
            cout<<": "<<*(CAD_FINAL+i)<<"\n";
        }
    }

    ///DATOS SEPARADOS
/*
    delete []cad;
    delete []CadINI;
    delete []CAD_FINAL;
*/
}

int main(){

    SINTAXXI.INTRO_SINTAXIS();

    fstream ficheroEntrada;
    string frase;

    int Num_FILA=1;
    char CAD[1000];


    ficheroEntrada.open ("CODIGO.cpp",ios::in);
    if (ficheroEntrada.is_open()) {
        //bool COMENTARIO_D=0,CONT_COMENT=0;

        while (! ficheroEntrada.eof() ) {

            cout<<"\n NUMERO DE FILA: "<<Num_FILA<<endl;

            getline(ficheroEntrada,frase);
            strcpy(CAD,frase.c_str());

            char CAD_RES[1000];
            int k;
            for(k=0;*(CAD+k);k++){
                if(*(CAD+k)=='/'&&*(CAD+k+1)=='/'){
                    break;
                }
                else{
                    *(CAD_RES+k)=*(CAD+k);
                }
            }*(CAD_RES+k)='\0';

        /*
        bool COMENTARIO_IN=COMENTARIO_D;
        for(int nm=0,mm=0;*(CAD+nm)&&CONT_COMENT==0;nm++){
            if(*(CAD+nm)=='/'&&*(CAD+nm+1)=='*'&&COMENTARIO_D==0){
                COMENTARIO_D=1;nm+=2;
            }
            if(*(CAD+nm)=='*'&&*(CAD+nm+1)=='/'&&COMENTARIO_D){
                COMENTARIO_D=0;nm+=2;
            }
            if(COMENTARIO_D!=1){
                *(CAD_RES+mm)=*(CAD+nm);mm++;
            }
            if(*(CAD+nm+1)==NULL){
                *(CAD_RES+mm)='\0';
            }
        }
        if(COMENTARIO_D==COMENTARIO_IN&&COMENTARIO_IN==1){
            *(CAD_RES+0)='\0';
        }


        cout<<CAD_RES<<endl<<endl;

*/

           Separar(CAD_RES,Num_FILA);
           Num_FILA++;
        }
        ficheroEntrada.close();
    }
    else{
        cout << "Fichero inexistente o faltan permisos para abrirlo" << endl;
    }
    ///SINTAXXI.mostrar();
    PALABRAS.MostrarLIST();
    cout<<"\n\n\n";

    FUNCIONES.InsertarARBOLFUN("GLOBAL_FUNCIONª","TIPO_GLOBAL");

    PALABRAS.AUTOMATA_LIST();

    cout<<"\n\n";

    FUNCIONES.MostrarARBOL_FUN();
    cout<<"\n\n\n";


    ///EJECUCION

    FUNCIONES.EJECUTAR_FUNCIONES("GLOBAL_FUNCIONª");
    FUNCIONES.EJECUTAR_FUNCIONES("main");

    ///EJECUCION

    ///TABLA DE SIMBOLOS

    cout<<"\n\n\t\tTABLA DE SIMBOLOS\n\n";

    GLOBALTABLA.MostrarTABLA();

    cout<<"\n\n\n\t\tINFORME DE ERRORES\n\n";

    LIST_ERROR_INFORME.MostrarLIST();

    cout<<"\n\n\n";

    system("pause");

    return 0;
}
