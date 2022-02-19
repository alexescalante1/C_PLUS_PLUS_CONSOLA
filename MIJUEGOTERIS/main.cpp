#include <iostream>
#include <windows.h>
using namespace std;

class Tetriz{
    private:
        int **MAPA;
        int LY,LX;
    public:
    Tetriz(int Lx, int Ly){
        LX = Lx,LY = Ly;
        MAPA = new int*[Ly];
        for(int i = 0; i<Ly;i++){
            MAPA[i] = new int[Lx];
            for(int j=0;j<Lx;j++){
                MAPA[i][j] = 0;
            }
        }
    }

    void MOSTAR(){
        for(int i=0; i< LY; i++){
            for(int j=0;j<LX;j++){
                cout<<MAPA[i][j];

            }cout<<endl;
        }
    }

};

int main()
{
    Tetriz A(20,30);
    A.MOSTAR();
    return 0;
}
