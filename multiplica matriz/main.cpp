#include <iostream>
#include <cstdlib>
using namespace std;

int TM[2]={2000,2000};

void MULTIPLICAR(int **,int **,int **);

class N_MATRIZ{
    public:
    int **MATRIZ;
    N_MATRIZ(){
        MATRIZ = new int *[*(TM+0)];
        for(int i=0;i<*(TM+0);i++){
            *(MATRIZ+i) = new int [*(TM+1)];
        }
    }
    void INSERT(int **M){
        for(int i=0;i<*(TM+0);i++){
            for(int j=0;j<*(TM+1);j++){
                *(*(MATRIZ+i)+j) = *(*(M+i)+j);
            }
        }
    }
    void INSERT_RAND(){
        for(int i=0;i<*(TM+0);i++){
            for(int j=0;j<*(TM+1);j++){
                *(*(MATRIZ+i)+j) = rand() % 100 +1;
            }
        }
    }
    void MOSTRAR(){
        for(int i=0;i<*(TM+0);i++){
            for(int j=0;j<*(TM+1);j++){
                cout<<*(*(MATRIZ+i)+j)<<" ";
            }cout<<endl;
        }cout<<endl;
    }
};

void MULTIPLICAR(int **M1,int **M2,int **M3){
    for(int i=0;i<*(TM+0);i++){
        for(int j=0;j<*(TM+1);j++){int RES=0;
            for(int k=0;k<*(TM+0);k++){
                RES+=*(*(M1+i)+k)**(*(M2+k)+j);
            }*(*(M3+i)+j)=RES;
        }
    }return;
}

int main()
{
    N_MATRIZ A,B,R;
    A.INSERT_RAND();
    B.INSERT_RAND();

//  A.MOSTRAR();
//  B.MOSTRAR();
    MULTIPLICAR(A.MATRIZ,B.MATRIZ,R.MATRIZ);
    R.MOSTRAR();
    cout<<"Fin";
    return 0;
}
