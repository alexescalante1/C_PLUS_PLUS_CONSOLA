#include <iostream>

using namespace std;

class NODOBASE
{
    public:
    double MPOS_X;
    NODOBASE *IZQ,*DER,*PADRE;
    NODOBASE(double D,NODOBASE *P){
         MPOS_X=D;
         PADRE=P;
         IZQ=NULL;
         DER=NULL;
    }
};

class MUNDO{
    public:
    NODOBASE *RAIZ,*PDRE;
    MUNDO(){
        RAIZ=NULL;
        PDRE=NULL;
    }
    void INSERTAR_PUNTO(double D){
         INSP(D,RAIZ,PDRE);
    }
    void INSP(double D,NODOBASE *&R,NODOBASE *PDRE){
         if(R==NULL)
            R=new NODOBASE(D,PDRE);
         else if(D>R->MPOS_X)
            INSP(D,R->DER,R);
         else
            INSP(D,R->IZQ,R);
    }
    void DESTRUIR(NODOBASE *Ds){
         Ds->IZQ=NULL;
         Ds->DER=NULL;
         delete Ds;
    }
    NODOBASE *MINIMO(NODOBASE *M){
         if(M==NULL){
            return NULL;
         }
         if(M->IZQ){
            return MINIMO(M->IZQ);
         }
         else{
            return M;
         }
    }
    void MODIFICAR(NODOBASE *R,NODOBASE *NewN){
         if(R->PADRE){
            if(R->MPOS_X == R->PADRE->IZQ->MPOS_X){
                R->PADRE->IZQ = NewN;
            }
            else if(R->MPOS_X == R->PADRE->DER->MPOS_X){
                R->PADRE->DER = NewN;
            }
         }
         if(NewN){
            NewN->PADRE = R->PADRE;
         }
    }
    void DELETENODO(NODOBASE *ELIMINARN){
         if(ELIMINARN->IZQ&&ELIMINARN->DER){
            NODOBASE *MENOR=MINIMO(ELIMINARN->DER);
            ELIMINARN->MPOS_X=MENOR->MPOS_X;
            DELETENODO(MENOR);
         }
         else if(ELIMINARN->IZQ){
            MODIFICAR(ELIMINARN,ELIMINARN->IZQ);
            DESTRUIR(ELIMINARN);
         }
         else if(ELIMINARN->DER){
            MODIFICAR(ELIMINARN,ELIMINARN->DER);
            DESTRUIR(ELIMINARN);
         }
         else{
            MODIFICAR(ELIMINARN,NULL);
            DESTRUIR(ELIMINARN);
         }
    }
    void ELIMINARNODO(int N){
         ELIM(N,RAIZ);
    }
    void ELIM(int N,NODOBASE *R){
         if(R==NULL){
            return;
         }
         else if(N<R->MPOS_X){
            ELIM(N,R->IZQ);
         }
         else if(N>R->MPOS_X){
            ELIM(N,R->DER);
         }
         else{
            DELETENODO(R);
         }
    }
    void VISTACAMARA(double PUNTOINICIAL,double DISTANCIA){NODOBASE *S = NULL;
        BUSCAR(int(PUNTOINICIAL+1),S);
        if(S){
            for(int i = 0; i < 5 ; i++ ){//RETOCESO
                if(S->PADRE){
                    S=S->PADRE;
                }else{break;}
            }
            MOSTRAR(S,PUNTOINICIAL+DISTANCIA);
        }
    }
    void BUSCAR(double V,NODOBASE *&S){
        BUS(RAIZ,V,S);
    }
    void BUS(NODOBASE *R,double V,NODOBASE *&S){
        if(R!=NULL){
            BUS(R->DER,V,S);
            if(R->MPOS_X==V){
                S = R;
            }
            BUS(R->IZQ,V,S);
        }
        return;
    }
    void MOSTRAR(NODOBASE *R,int N){
         if(R!=NULL){
            if(R->MPOS_X<=N){
                MOSTRAR(R->IZQ,N);
                cout<<R->MPOS_X<<", ";
                MOSTRAR(R->DER,N);
            }
         }
    }
}MUNDO;

void GENERARCAMPO(double PUNTOINICIAL,double PUNTOFINAL){
    for(double i=PUNTOINICIAL;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.5;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.1;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.3;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.2;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.4;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.7;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.6;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.8;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
    for(double i=PUNTOINICIAL+0.9;i<PUNTOINICIAL+PUNTOFINAL;i++){
        MUNDO.INSERTAR_PUNTO(i);
    }
}

int main()
{


    GENERARCAMPO(0,200); //LINA DE COORDENADAS

    MUNDO.VISTACAMARA(10,30);

//    MUNDO.ELIMINARNODO(100);


    return 0;

}
