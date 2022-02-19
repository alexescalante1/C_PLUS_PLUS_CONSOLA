#include <iostream>
using namespace std;
string ANIMALES[3] = {"NULL","LOBO","OVEJA"};
class NODO{
    public:
        int X,Y,ANIMAL;

        NODO *TOP,*BOT,*LEFT,*RIGHT;
        NODO *LEFT_TOP,*RIGHT_TOP,*LEFT_BOT,*RIGHT_BOT;

        NODO(int XX,int YY,int O){

            ANIMAL = O;
            X       = XX;
            Y       = YY;

            TOP   = NULL;
            BOT   = NULL;
            LEFT  = NULL;
            RIGHT = NULL;

            LEFT_TOP  = NULL;
            RIGHT_TOP = NULL;
            LEFT_BOT  = NULL;
            RIGHT_BOT = NULL;
        }
};

class MAPA{
    public:
    NODO *RAIZ;
    MAPA(){
        RAIZ=NULL;
    }
    void INSERTAR(int X,int Y,int V,int DIR){
        INS(RAIZ,X,Y,V,DIR);
    }
    void INS(NODO *&R,int X,int Y,int V,int DIR){
        if(R){
            switch(DIR){
                case 1:
                    INS(R->TOP,X,Y,V,DIR);
                    break;
                case 2:
                    INS(R->BOT,X,Y,V,DIR);
                    break;
                case 3:
                    INS(R->LEFT,X,Y,V,DIR);
                    break;
                case 4:
                    INS(R->RIGHT,X,Y,V,DIR);
                    break;
                case 5:
                    INS(R->LEFT_TOP,X,Y,V,DIR);
                    break;
                case 6:
                    INS(R->RIGHT_TOP,X,Y,V,DIR);
                    break;
                case 7:
                    INS(R->LEFT_BOT,X,Y,V,DIR);
                    break;
                case 8:
                    INS(R->RIGHT_BOT,X,Y,V,DIR);
                    break;
                default:
                    cout<<"ERROR!";
                    return;
            }
        }else{
            R = new NODO(X,Y,V);
        }
    }
    void MOSTRAR(){
        MOS(RAIZ);
    }
    void MOS(NODO *R){
        while(R){
            cout<<ANIMALES[R->ANIMAL]<<" ";
            R=R->TOP;
        }
    }
}A;

int main()
{
    int NX = 1, NY = 1;

    A.INSERTAR(NX,NY,1,1);
    //ROJO
//    A.INSERTAR(NX-1,NY-1,2,5);
//    A.INSERTAR(NX+1,NY+1,2,8);
//    A.INSERTAR(NX-1,NY+1,2,7);
//    A.INSERTAR(NX+1,NY-1,2,6);
//    //ROSADO
//    A.INSERTAR(NX-1,NY,2,3);
//    A.INSERTAR(NX+1,NY,2,4);
//    A.INSERTAR(NX,NY+1,2,2);
//    A.INSERTAR(NX,NY-1,2,1);

    A.MOSTRAR();

    return 0;
}
