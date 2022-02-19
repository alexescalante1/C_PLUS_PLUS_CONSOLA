#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    int edad;
    cout << "Ingrese la edad:" << endl;
    cin>>edad;

    if(edad>=18){
        char SOUNFILE[] = "MUSICA1.wav";
        PlaySound((LPCSTR)SOUNFILE, NULL,SND_ASYNC);
    }else{
        PlaySound(TEXT("MUSICA2.wav"), NULL,SND_ASYNC );
    }
    system("pause");
    return 0;
}
