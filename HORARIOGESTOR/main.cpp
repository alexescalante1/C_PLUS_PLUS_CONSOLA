#include <iostream>
#include <ctime>
#include <vector>
using namespace std;
int NSEMANA=1;

class NODO_DIAS{
    public:
    int POS[6];
    NODO_DIAS *SIGUIENTE;
    NODO_DIAS(int *P = NULL,NODO_DIAS *SIG=NULL){
        POS[0]=P[0];
        POS[1]=P[1];
        POS[2]=P[2];
        POS[3]=P[3];
        POS[4]=P[4];
        POS[5]=P[5];
        SIGUIENTE=SIG;
    }
};

class INTERCALADO{
    public:
    NODO_DIAS *Raiz;
    INTERCALADO(){
        Raiz = NULL;
    }
    void INSERTAR(int *POS){
        INS(POS,Raiz);
    }
    void INS(int *POS, NODO_DIAS *&R){
        if(R){
            INS(POS,R->SIGUIENTE);
        }else{
            R = new NODO_DIAS(POS);
        }
    }
    int Mostrar(int DIA_ACT,int MES_ACT){
        return MOS(Raiz,DIA_ACT,MES_ACT);
    }
    int MOS(NODO_DIAS *R,int DIA_ACT,int MES_ACT){

        while(R){
            if(DIA_ACT>=R->POS[0]&&DIA_ACT<=R->POS[2]){
                if(MES_ACT>=R->POS[1]&&MES_ACT<=R->POS[3]){
                    cout<<"S-"<<R->POS[5]<<"\n";
                    return R->POS[4];
                }
            }
            R=R->SIGUIENTE;
        }
        return 3;
    }

}I;

void INSERTAR_HORARIO(int a,int b,int c,int d,int e){
    int DIAS_INTER[5];
    DIAS_INTER[0]=a;DIAS_INTER[1]=b;DIAS_INTER[2]=c;DIAS_INTER[3]=d;DIAS_INTER[4]=e;DIAS_INTER[5]=NSEMANA;NSEMANA++;
    I.INSERTAR(DIAS_INTER);
}


class NODO_HORARIO{
    public:
    int Xx,Yy;
    NODO_HORARIO *SIGUIENTE;
    NODO_HORARIO(int x=0,int y=0,NODO_HORARIO *SIG=NULL){
        Xx=x;
        Yy=y;
        SIGUIENTE=SIG;
    }
};

class HORARIO{
    public:
    NODO_HORARIO *Raiz;
    HORARIO(){
        Raiz = NULL;
    }
    void INSERTAR(int x,int y){
        INS(x,y,Raiz);
    }
    void INS(int x,int y, NODO_HORARIO *&R){
        if(R){
            INS(x,y,R->SIGUIENTE);
        }else{
            R = new NODO_HORARIO(x,y);
        }
    }
    void Mostrar(){
        MOS(Raiz);
    }
    void MOS(NODO_HORARIO *R){
        while(R){
            cout<<"\n         "<<R->Xx<<R->Yy<<"\n";
            R=R->SIGUIENTE;
        }
    }

};

class NODO{
    public:
    string CURSO;
    int id;
    NODO *SIGUIENTE;
    HORARIO HORAS;
    NODO(string CUR="",int i=0,NODO *SIG=NULL){
        CURSO=CUR;
        id=i;
        SIGUIENTE=SIG;
    }
};

class CURSOS{
    public:
    NODO *Raiz;
    CURSOS(){
        Raiz = NULL;
    }
    void INSERTAR(string CURSO,int id){
        INS(CURSO,id,Raiz);
    }
    void INS(string CURSO,int id, NODO *&R){
        if(R){
            INS(CURSO,id,R->SIGUIENTE);
        }else{
            R = new NODO(CURSO,id);
        }
    }
    void INSERTAR_HORA(string CURSO, int x, int y){
        INST_H(CURSO,x,y,Raiz);
    }
    void INST_H(string CURSO, int x, int y, NODO *R){
        while(R){
            if(R->CURSO==CURSO){
                R->HORAS.INSERTAR(x,y);
                break;
            }
            R=R->SIGUIENTE;
        }
    }
    bool Mostrar(int VAL){
        return MOS(Raiz,VAL);
    }
    bool MOS(NODO *R,int VAL){
        while(R){
            if(R->id==VAL){
                cout<<R->CURSO<<" Id: "<<R->id<<"\n";
                R->HORAS.Mostrar();
            }
            R=R->SIGUIENTE;
        }
        return 0;
    }

}C;

void INSERTAR_HORAS(string Curso,int x,int y){
    C.INSERTAR_HORA(Curso,x,y);
}

void SEMANA_ACT(){
    time_t now = time(0);
    tm *time = localtime(&now);
    int ANIO = 1900+time->tm_year;

    vector<string> Dias;
    Dias.push_back("Domingo");
    Dias.push_back("Lunes");
    Dias.push_back("Martes");
    Dias.push_back("Miercoles");
    Dias.push_back("Jueves");
    Dias.push_back("Viernes");
    Dias.push_back("Sabado");
    vector<string> Mes;
    Mes.push_back("Enero");
    Mes.push_back("Febrero");
    Mes.push_back("Marzo");
    Mes.push_back("Abril");
    Mes.push_back("Mayo");
    Mes.push_back("Junio");
    Mes.push_back("Julio");
    Mes.push_back("Agosto");
    Mes.push_back("Septiembre");
    Mes.push_back("Octubre");
    Mes.push_back("Novienbre");
    Mes.push_back("Diciembre");

    cout<<"Hoy es "<<Dias[time->tm_wday]<<" "<<time->tm_mday<<" de "<<Mes[time->tm_mon]<<" del "<<ANIO<<endl;

    C.Mostrar(I.Mostrar(time->tm_mday,time->tm_mon+1));
}

int main()
{
    ///INSERTAR SEMANAS
    INSERTAR_HORARIO(1,6,5,6,1);
    INSERTAR_HORARIO(8,6,12,6,0);
    INSERTAR_HORARIO(15,6,19,6,1);
    INSERTAR_HORARIO(22,6,26,6,0);

    INSERTAR_HORARIO(29,6,3,7,1);
    INSERTAR_HORARIO(6,7,10,7,0);
    INSERTAR_HORARIO(13,7,17,7,1);
    INSERTAR_HORARIO(20,7,24,7,0);
    INSERTAR_HORARIO(27,7,31,7,1);

    INSERTAR_HORARIO(3,8,7,8,0);
    INSERTAR_HORARIO(10,8,14,8,1);
    INSERTAR_HORARIO(17,8,21,8,0);
    INSERTAR_HORARIO(24,8,28,8,1);

    INSERTAR_HORARIO(31,8,4,9,0);
    INSERTAR_HORARIO(7,9,11,9,1);
    INSERTAR_HORARIO(14,9,18,9,0);
    INSERTAR_HORARIO(21,9,25,9,1);
    INSERTAR_HORARIO(28,9,2,10,0);
    ///INSERTAR SEMANAS



    ///INSERTAR CURSOS
    C.INSERTAR("PROGRAMACION",0);
    C.INSERTAR("SIMULACION",1);
    C.INSERTAR("PARALELISMO",1);
    C.INSERTAR("REDACCION",0);
    C.INSERTAR("iNTELIGENCIA",1);
    C.INSERTAR("ANALISIS",1);
    C.INSERTAR("AUDITORIA",0);
    ///INSERTAR CURSOS


    ///INSERTAR HORAS
    INSERTAR_HORAS("PARALELISMO",0,0);
    INSERTAR_HORAS("PARALELISMO",2,1);
    INSERTAR_HORAS("PARALELISMO",4,0);

    INSERTAR_HORAS("PROGRAMACION",0,1);
    INSERTAR_HORAS("PROGRAMACION",4,1);

    INSERTAR_HORAS("SIMULACION",0,2);
    INSERTAR_HORAS("SIMULACION",4,2);

    INSERTAR_HORAS("REDACCION",1,0);
    INSERTAR_HORAS("REDACCION",3,0);

    INSERTAR_HORAS("iNTELIGENCIA",1,1);
    INSERTAR_HORAS("iNTELIGENCIA",2,2);

    INSERTAR_HORAS("AUDITORIA",1,2);
    INSERTAR_HORAS("AUDITORIA",3,2);

    INSERTAR_HORAS("ANALISIS",2,0);
    INSERTAR_HORAS("ANALISIS",3,1);
    ///INSERTAR HORAS


    SEMANA_ACT();

    return 0;
}
