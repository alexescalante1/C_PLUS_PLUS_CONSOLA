#include <iostream>

using namespace std;

int CONVERTIR_STRING_A_CHAR(string H,char **CAD){int TAM=0,i=0;
    for(;H[TAM];TAM++);TAM+=1;
    *CAD = new char [TAM];
    for(;H[i];i++){
        *(*(CAD)+i) = H[i];
    }*(*(CAD)+i) = '\0';
    return i;
}

int CONCATENAR(string A,string B,char **R){int TAM=0,i=0;
    for(;A[TAM];TAM++);
    for(;B[i];i++,TAM++);TAM+=1;
    *R = new char [TAM];TAM=0;
    for(i=0;A[i];i++,TAM++){
        *(*(R)+TAM)=A[i];
    }
    for(i=0;B[i];i++,TAM++){
        *(*(R)+TAM)=B[i];
    }*(*(R)+TAM) = '\0';
    return TAM;
}

int CONVERTIR_INT_A_CAD(char **R,long long NUM){int TAM=0,i=0;
    for(long long AUX=NUM;AUX!=0;i++,AUX/=10);
    *R = new char [i];TAM=i;*(*(R)+i)='\0';i-=1;
    for(;i>=0;i--,NUM/=10){
        *(*(R)+i)=(char)(NUM%10+48);
    }
    return TAM;
}

int CONVERTIR_DOUBLE_A_CAD(char **R,double DOBL,int PFLOAT){int NINT=0,DECI=0,i=0,TAM=0,DFLOAT=1;
    NINT=DOBL;for(;PFLOAT;PFLOAT--){DFLOAT*=10;}
    DECI=(DOBL-NINT)*DFLOAT;
    for(int AUX=NINT;AUX!=0;i++,AUX/=10);
    for(int AUX=DECI;AUX!=0;i++,AUX/=10);i+=1;
    *R = new char [i];TAM=i;*(*(R)+i)='\0';i-=1;
    for(;DECI;i--,DECI/=10){
        *(*(R)+i)=(char)(DECI%10+48);
    }*(*(R)+i)='.';i-=1;
    for(;NINT;i--,NINT/=10){
        *(*(R)+i)=(char)(NINT%10+48);
    }
    return TAM;
}

int main()
{
    char *CAD;
    CONVERTIR_STRING_A_CHAR("HELLO",&CAD);
    cout<<CAD<<"\n";

    char *CAD2;
    CONCATENAR("HOLA MUNDO COMO ESTAS"," XD MI NOMBRE ES ALEX xd xd i dont know",&CAD2);
    cout<<CAD2<<"\n";

    char *CAD3;
    CONVERTIR_INT_A_CAD(&CAD3,987654321123456789);
    cout<<CAD3<<"\n";

    char *CAD4;
    CONVERTIR_DOUBLE_A_CAD(&CAD4,4.452,1);
    cout<<"\n"<<CAD4<<"\n";
    return 0;
}
