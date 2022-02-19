#include <iostream>
#include <cmath>
using namespace std;
class NODO;
class ENLACES;
class NODO_ENLACE;
class HEURISTCA;
//
//class NODO_ENLACE{
//    public:
//    NODO_ENLACE *SIG;
//    string D;
//    NODO_ENLACE(string Dr){
//        D = Dr;
//        SIG = NULL;
//    }
//};
//
//class ENLACES{
//    public:
//    NODO_ENLACE *NE;
//    ENLACES(){
//        NE=NULL;
//    }
//    void INSERT_ENLACE(string D){
//        INSEN(NE,D);
//    }
//    void INSEN(NODO_ENLACE *&N,string D){
//        if(N){
//            INSEN(N->SIG,D);
//        }else{
//            N = new NODO_ENLACE(D);
//        }
//    }
//    void MOSTRAR_ENLACES(){
//        MOS(NE);
//    }
//    void MOS(NODO_ENLACE *N){
//        while(N){
//            cout<<"Enlace: "<<N->D<<"\n";
//            N=N->SIG;
//        }
//    }
//};

double DISTANCIA_PUNTOS(double x1,double y1,double x2,double y2){
    return sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
}

class NODO{
    public:
//  ENLACES EN;
    string LNODO;
    double PX,PY;//POSISION EN EL ESPACIO
    double VALOR_HEURISTICO;

    NODO *SIG;
    NODO *DR[20];//ENLACES
    double DISTANCIA[20];
    NODO(string N="",double x=0,double y=0){
        LNODO = N;
        PX = x;
        PY = y;
        SIG = NULL;
        VALOR_HEURISTICO = 0;
    }
};

class HEURISTCA{
    public:
    NODO *R1;
    HEURISTCA(){
        R1=NULL;
    }
    void INSERTAR_NODO(string N,double x,double y){
        INS(N,x,y,R1);
    }
    void INS(string N,double x,double y,NODO *&R){
        if(R){
            INS(N,x,y,R->SIG);
        }else{
            R = new NODO(N,x,y);
        }
    }
    void ENLACE(string a,string b){
        E(R1,a,b);
    }
    void E(NODO *R,string a,string b){
        while(R){
            if(R->LNODO==a){
                F(R1,b,R);
                break;
            }
            R=R->SIG;
        }
    }
    void F(NODO *R,string b,NODO *S){
        while(R){
            if(R->LNODO==b){
                for(int i=0;i<10;i++){
                    if(!S->DR[i]){
                        S->DR[i]=R;
//                        cout<<"en null";cout<<i;
                        break;
                    }
                }//cout<<"\n";
//                S->EN.INSERT_ENLACE(R->LNODO);
                break;
            }
            R=R->SIG;
        }
    }
    void ASIGNAR_DISTANCIA(){
        ASGD(R1);
    }
    void ASGD(NODO *R){
        while(R){
            cout<<R->LNODO<<" "<<R->PX<<","<<R->PY<<"     \t";
            for(int i=0;R->DR[i];i++){
                R->DISTANCIA[i]=DISTANCIA_PUNTOS(R->PX,R->PY,R->DR[i]->PX,R->DR[i]->PY);
                cout<<"--"<<R->DR[i]->LNODO<<"( "<<R->DR[i]->PX<<", "<<R->DR[i]->PY <<" ) ";
            }
            cout<<"\n";
//            R->EN.MOSTRAR_ENLACES();
            R=R->SIG;
        }
    }

    void ASIGNAR_HEURISTICA(string I,string F){
        ASGH(R1,I,F);
    }
    void ASGH(NODO *R,string I,string F){ double Xi,Yi;NODO *B=R;
        while(R){
            if(I==R->LNODO){
                Xi=R->PX;
                Yi=R->PY;
                cout<<"NODO INICIAL: "<<I<<" "<<Xi<<","<<Yi<<"\n";
                break;
            }
            R=R->SIG;
        }
        while(B){
            B->VALOR_HEURISTICO=DISTANCIA_PUNTOS(Xi,Yi,B->PX,B->PY);
            cout<<B->LNODO<<" "<<B->VALOR_HEURISTICO<<"\n";
//            B->EN.MOSTRAR_ENLACES();
            B=B->SIG;
        }
    }

    void MOSTRAR(){
        M(R1);
    }
    void M(NODO *R){
        while(R){
            cout<<R->LNODO<<" "<<R->PX<<","<<R->PY<<"     \t";
            for(int i=0;R->DR[i];i++){
                cout<<"--"<<R->DR[i]->LNODO<<"("<<R->DISTANCIA[i]<<") ";
            }
            cout<<"\n";
//            R->EN.MOSTRAR_ENLACES();
            R=R->SIG;
        }
    }
};

int main()
{
    HEURISTCA A;
    A.INSERTAR_NODO("A",4.5,11);
    A.INSERTAR_NODO("B",1,8);
    A.INSERTAR_NODO("C",3,4);
    A.INSERTAR_NODO("D",7,6);
    A.INSERTAR_NODO("E",6,1);
    A.INSERTAR_NODO("F",14,9);
    A.INSERTAR_NODO("G",10,7);
    A.INSERTAR_NODO("H",17,6);
    A.INSERTAR_NODO("I",12,3);
    A.INSERTAR_NODO("J",10,0.5);

    A.ENLACE("A","B");
    A.ENLACE("A","F");

    A.ENLACE("B","A");
    A.ENLACE("B","C");
    A.ENLACE("B","D");

    A.ENLACE("C","B");
    A.ENLACE("C","D");
    A.ENLACE("C","E");

    A.ENLACE("D","B");
    A.ENLACE("D","C");
    A.ENLACE("D","E");

    A.ENLACE("E","I");
    A.ENLACE("E","J");
    A.ENLACE("E","D");
    A.ENLACE("E","C");

    A.ENLACE("F","A");
    A.ENLACE("F","G");
    A.ENLACE("F","H");

    A.ENLACE("G","F");
    A.ENLACE("G","I");

    A.ENLACE("H","F");
    A.ENLACE("H","I");

    A.ENLACE("I","G");
    A.ENLACE("I","H");
    A.ENLACE("I","E");
    A.ENLACE("I","J");

    A.ENLACE("J","E");
    A.ENLACE("J","I");

    A.ASIGNAR_DISTANCIA();

    cout<<"\n\n";

    A.ASIGNAR_HEURISTICA("J","A");

    cout<<"\n\n";

    A.MOSTRAR();

    return 0;
}
