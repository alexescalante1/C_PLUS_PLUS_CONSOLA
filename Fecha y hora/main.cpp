#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

int main()
{
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

    time_t now = time(0);
    tm * time= localtime(&now);
    int ANIO = 1900+time->tm_year;
    cout<<"Hoy es "<<Dias[time->tm_wday]<<" "<<time->tm_mday
        <<" de "<<Mes[time->tm_mon]
        <<" del "<<ANIO<<endl;
    cout<<time->tm_hour<<":"<<time->tm_min<<":"<<time->tm_sec;

    return 0;
}
