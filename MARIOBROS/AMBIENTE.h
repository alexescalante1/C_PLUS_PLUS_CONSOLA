#ifndef AMBIENTE_H
#define AMBIENTE_H
#include <iostream>

class nodo
{
    public:
    int dato;
    nodo *izq,*der,*PaDr;
    nodo(int D=0,nodo *Padr=NULL,nodo *iz=NULL,nodo *de=NULL){
         dato=D;
         izq=iz;
         der=de;
         PaDr=Padr;
    }
};

class AMBIENTE
{
    public:
        nodo *raiz,*padr;
        AMBIENTE();
        virtual ~AMBIENTE();
        void insertar(int);
        void ins(int,nodo *&,nodo *);
        void destruir(nodo *);
        nodo *Min(nodo *);
        void modificar(nodo *,nodo *);
        void eliminarN(nodo *);
        void elimnarNodo(int);
        void eliminar(int,nodo *);
        void mostrar();
        void mos(nodo *,int);

    protected:

    private:
};

#endif // AMBIENTE_H
