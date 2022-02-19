#include <iostream>
#include "AMBIENTE.h"
using namespace std;

AMBIENTE::AMBIENTE()
{
    raiz=NULL;
    padr=NULL;
}

AMBIENTE::~AMBIENTE()
{
    //dtor
}

void AMBIENTE::insertar(int D){
     ins(D,raiz,padr);
}
void AMBIENTE::ins(int D,nodo *&R,nodo *padr){
     if(R==NULL)
        R=new nodo(D,padr);
     else if(D<R->dato)
        ins(D,R->izq,R);
     else
        ins(D,R->der,R);
}
void AMBIENTE::destruir(nodo *Ds){
     Ds->izq=NULL;
     Ds->der=NULL;
     delete Ds;
}
nodo AMBIENTE::*Min(nodo *m){
     if(m==NULL){
        return NULL;
     }
     if(m->izq){
        return Min(m->izq);
     }
     else{
        return m;
     }
}
void AMBIENTE::modificar(nodo *Re,nodo *NewN){
     if(Re->PaDr){
        if(Re->dato == Re->PaDr->izq->dato){
            Re->PaDr->izq = NewN;
        }
        else if(Re->dato == Re->PaDr->der->dato){
            Re->PaDr->der = NewN;
        }
     }
     if(NewN){
        NewN->PaDr = Re->PaDr;
     }
}
void AMBIENTE::eliminarN(nodo *elim){
     if(elim->izq&&elim->der){
        nodo *menor=Min(elim->der);
        elim->dato=menor->dato;
        eliminarN(menor);
     }
     else if(elim->izq){
        modificar(elim,elim->izq);
        destruir(elim);
     }
     else if(elim->der){
        modificar(elim,elim->der);
        destruir(elim);
     }
     else{
        modificar(elim,NULL);
        destruir(elim);
     }
}
void AMBIENTE::elimnarNodo(int n){
     eliminar(n,raiz);
}
void AMBIENTE::eliminar(int n,nodo *E){
     if(E==NULL){
        return;
     }
     else if(n<E->dato){
        eliminar(n,E->izq);
     }
     else if(n>E->dato){
        eliminar(n,E->der);
     }
     else{
        eliminarN(E);
     }
}
void AMBIENTE::mostrar(){
     mos(raiz,0);
}
void AMBIENTE::mos(nodo *R,int C){
     if(R!=NULL){
        mos(R->der,C+1);
        for(int i=0;i<C;i++){
            cout<<"   ";
        }
        cout<<R->dato<<"\n\n";
        mos(R->izq,C+1);
     }
}
