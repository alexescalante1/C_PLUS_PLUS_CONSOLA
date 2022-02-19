#include <iostream>
#include <cstdlib>

using namespace std;

int TM=5;

class VECTOR{
    public:
    int *VECT;
    VECTOR(){
        VECT = new int[TM];
    }
    void INSERT(int *M) {
        for (int i = 0; i < TM; i++) {
            *(VECT + i) = *(M + i);
        }return;
    }
    void INSERT_RAND(){
        for (int i = 0; i < TM; i++){
            *(VECT + i) = rand() % 100 + 1;
        }return;
    }
    void MOSTRAR(){
        for(int i = 0; i < TM; i++ ){
            cout<<VECT[i]<<" ";
        }return;
    }
};

void QUICKSORT(int *V,int IZQ, int DER){
    int IZQUIERDA,DERECHA,TMEDIO ,AUXILIAR;
    TMEDIO = V[(IZQ + DER)/2];
    IZQUIERDA = IZQ;DERECHA = DER;
    do{
        while((V[IZQUIERDA] < TMEDIO) && (DERECHA <= DER)){
            IZQUIERDA++;
        }
        while((TMEDIO < V[DERECHA]) && (DERECHA > IZQ)){
            DERECHA--;
        }
        if( IZQUIERDA <= DERECHA ){
            AUXILIAR = V[IZQUIERDA]; V[IZQUIERDA] = V[DERECHA]; V[DERECHA] = AUXILIAR;
            IZQUIERDA++;  DERECHA--;
        }

    }while( IZQUIERDA <= DERECHA );


    if( IZQ < DERECHA ){
        QUICKSORT( V, IZQ, DERECHA );
    }
    if( IZQUIERDA < DER ){
        QUICKSORT( V, IZQUIERDA, DER );
    }
}

int main()
{
    cout<<" INGRESAR CANTIDAD DE DATOS: ";cin>>TM;
    VECTOR V;
    V.INSERT_RAND();

    QUICKSORT(V.VECT,0,TM-1);

    V.MOSTRAR();
    return 0;
}
