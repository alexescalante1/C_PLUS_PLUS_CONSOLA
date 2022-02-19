#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;
///ARBOL ADAPTABLE
template <class T>
class Nodo{
    public:
    T dato;
    T TIPO;
    Nodo<T> *izq;
    Nodo<T> *der;
    Nodo(T d,T tipo){
        this->dato = d;
        this->TIPO = tipo;
        izq = der = NULL;
    }
    Nodo<T> *RetHijoIzq(){
        return izq;
    }
    Nodo<T> *RetHijoDer(){
        return der;
    }
    void AsigHijoIzq(Nodo<T> *i){
        izq = i;
    }
    void AsigHijoDer(Nodo<T> *d){
        der = d;
    }
    void AsigDato(T d){
        dato = d;
    }
    void AsigTipo(T tipo){
        TIPO = tipo;
    }
    T RetDato(){
        return dato;
    }
    T RetTipo(){
        return TIPO;
    }
};
template <class T>
class ArbolADAPTABLE{
    private:
    Nodo<T> *raiz;
    void Insert(Nodo<T> *r, Nodo<T> *n){
        if(n->RetDato() < r->RetDato()){
            if(r->RetHijoIzq() == NULL)
                r->AsigHijoIzq(n);
            else
                Insert(r->RetHijoIzq(), n);
        }
        else{
            if(r->RetHijoDer() == NULL)
                r->AsigHijoDer(n);
            else
                Insert(r->RetHijoDer(), n);
        }
    }
    int Altura(Nodo<T> *r){
        if(r == NULL)
            return 0;
        else
            return 1 + max(Altura(r->RetHijoIzq()), Altura(r->RetHijoDer()));
    }

    int NumNodo(Nodo<T> *r){
        if(r == NULL)
            return 0;
        else
            return 1 + NumNodo(r->RetHijoIzq()) + NumNodo(r->RetHijoDer());
    }
    public:
    int NumNodo(){
        return NumNodo(raiz);
    }

    Nodo<T> *BuscarR(T valor){
        return Buscar(raiz, valor);
    }
    Nodo<T> *Buscar(Nodo<T> *r, T valor){
        if(r == NULL){
            return NULL;
        }
        if(r->RetDato() == valor){
            return r;
        }
        else if(r->RetDato() > valor){
            return Buscar(r->RetHijoIzq(), valor);
        }
        else{
            return Buscar(r->RetHijoDer(), valor);
        }
    }

    int Altura(){
        return Altura(raiz);
    }
    ArbolADAPTABLE(){
        raiz = NULL;
    }
    ArbolADAPTABLE(Nodo<T> *n){
        raiz = n;
    }
    void Insertar(T valor,T tipo){
        Nodo<T>* n = new Nodo<T>(valor,tipo);
        if (raiz == NULL)
            raiz = n;
        else
            Insert(raiz, n);
    }
    void Mostrar(){
        int c=0;
        Mos(raiz,c);
    }
    void Mos(Nodo<T> *r, int cont){
        if(r!=NULL){
            Mos(r->RetHijoDer(),cont+1);
            for(int i=0;i<cont;i++){
                cout<<"     ";
            }
            cout<<r->RetDato()<<" "<<r->RetTipo()<<endl;
            Mos(r->RetHijoIzq(),cont+1);
        }
    }
};
///ARBOL ADAPTABLE
class MIS_DATOS{
        public:
        ArbolADAPTABLE<string> *SINTAXIS;
        int INTRO_SINTAXIS(){
            SINTAXIS = new ArbolADAPTABLE<string>();
            SINTAXIS->Insertar("int","tipo_int");
            SINTAXIS->Insertar("float","tipo_float");
            SINTAXIS->Insertar("double","tipo_double");
            SINTAXIS->Insertar("long","tipo_long");
            SINTAXIS->Insertar("char","tipo_char");
            SINTAXIS->Insertar("string","tipo_string");
            SINTAXIS->Insertar("+","op_mas");
            SINTAXIS->Insertar("-","op_menos");
            SINTAXIS->Insertar("*","op_multiplica");
            SINTAXIS->Insertar("/","op_divicion");
            SINTAXIS->Insertar("=","op_asignacion");
            SINTAXIS->Insertar("||","op_O");
            SINTAXIS->Insertar("&&","op_Y");
            SINTAXIS->Insertar("==","comp_igual");
            SINTAXIS->Insertar("<=","comp_menor_igual");
            SINTAXIS->Insertar(">=","comp_mayor_igual");
            SINTAXIS->Insertar("<<","doble_menor");
            SINTAXIS->Insertar(">>","doble_mayor");
            SINTAXIS->Insertar("<","comp_menor");
            SINTAXIS->Insertar(">","comp_mayor");
            SINTAXIS->Insertar("{","llave_abre");
            SINTAXIS->Insertar("}","llave_cierra");
            SINTAXIS->Insertar("(","parentesis_abre");
            SINTAXIS->Insertar(")","parentesis_cierra");
            SINTAXIS->Insertar(";","cierra_sentencia");
            SINTAXIS->Insertar("return","retorna_dato");
            SINTAXIS->Insertar("cout","mostrar");
            SINTAXIS->Insertar("cin","entrada_dato");
            SINTAXIS->Insertar("endl","mostrar_salto_de_linea");
            SINTAXIS->Insertar("for","bucle_for");
            SINTAXIS->Insertar("while","bucle_while");
            SINTAXIS->Insertar("if","Condicion_if");
            SINTAXIS->Insertar(".","OP_punto");
            SINTAXIS->Insertar(",","OP_coma");
            SINTAXIS->Insertar("'","Comilla_Simple");
            SINTAXIS->Insertar("++","Doble_Incremento");
            SINTAXIS->Insertar("--","Doble_Decremento");
            SINTAXIS->Insertar("#","hastack");
            SINTAXIS->Insertar("include","incluir_lib");
            SINTAXIS->Insertar("using","usar_lib");
            SINTAXIS->Insertar("namespace","maespace_lib");
            SINTAXIS->Insertar("std","estandar_lib");
            return 0;
        }
        bool validaNUM(char N){
            for(char i='0';i<='9';i++){
                if(i==N){
                    return true;
                }
            }return false;
        }
        bool NUMEROS(char *NUM){
            int Limite=0,Corte=0;
            for(;*(NUM+Limite);Limite++){
                if(validaNUM(*(NUM+Limite))==true){
                    Corte++;
                }
            }
            if(Limite==Corte){
                return true;
            }return false;
        }

        string busqueda(char *dato){
            if(SINTAXIS->BuscarR(dato)!=NULL){
                return SINTAXIS->BuscarR(dato)->TIPO;
            }
            else if(NUMEROS(dato)==1){
                return "Numero";
            }
            else if((int)dato[0]==34){
                return "Comilla_Doble";
            }
            else{
                return "Variable";
            }
        }

        void mostrar(){

            printf("\n\n");
            SINTAXIS->Mostrar();
            printf("\n\n");

        }
};

MIS_DATOS SINTAXXI;
///SINTAXIS

bool validaNUM(char N){
            for(char i='0';i<='9';i++){
                if(i==N){
                    return true;
                }
            }return false;
}
bool NUMEROS(char *NUM){
            int Limite=0,Corte=0;
            for(;*(NUM+Limite);Limite++){
                if(validaNUM(*(NUM+Limite))==true){
                    Corte++;
                }
            }
            if(Limite==Corte){
                return true;
            }return false;
}
class GENERADOR_AUTOMATA{
    public:
    ofstream archivo;

    bool ejecutar(){
        archivo.open("SALIDA.txt");
        ARMAR_AUTOMATA(0,0,1,0);
        archivo.close();
    }

    bool ARMAR_AUTOMATA(bool continuar,int BARRA_T,bool MOS_Else,bool FOR_ADD){ ///FUNCION RECURSIVA

    int SSS=3;

    ///ENTRADA
    int cant;
    int N;
    bool ANULAR_CONDICION=0;
    string cantt;
    string Vali;
    string NAME[20];
    char CAD[1000];
    char CANT[10];

    bool ValNUM=0;
    for(bool P=1;P;){
        cout<<"CANTIDAD: ";
        cin>>cantt;
        strcpy(CANT,cantt.c_str());
        ValNUM=NUMEROS(CANT);
        if(ValNUM){
            P=0;
        }
    }
    cant = atoi (CANT);
    for(int i=0;i<cant;i++){
        cout<<"PALABRA "<<i+1<<" : ";
        cin>>NAME[i];
    }
    ///ENTRADA


    /// crear variacion || || ||
    if(cant>1){

        for(SSS=0;SSS<3;SSS++){
                cout<<"\t";
                archivo<<"\t";
        }

        for(N=0;N<BARRA_T;N++){
            cout<<"\t";
            archivo<<"\t";
        }
        cout << "if(";
        archivo<< "if(";
        for(int i=0;i<cant;i++){
            strcpy(CAD,NAME[i].c_str());
            cout <<"R->DAT_AUT=="<<(char)34<<SINTAXXI.busqueda(CAD)<<(char)34;
            archivo<<"R->DAT_AUT=="<<(char)34<<SINTAXXI.busqueda(CAD)<<(char)34;
            if(i+1<cant){
                cout<<"||";
                archivo<<"||";
            }
        }
        cout<<"){\n";
        archivo<<"){\n";
        BARRA_T++;
        MOS_Else=0;
    }
    /// crear variacion || || ||

    /// crear condicion normal


    for(int j=0;j<cant;j++){

        int N;
        for(SSS=0;SSS<3;SSS++){
                cout<<"\t";
                archivo<<"\t";
        }
        for(N=0;N<BARRA_T;N++){cout<<"\t";archivo<<"\t";}

        if(cant==1&&NAME[0]=="#ADD_BUCLE"){ ///TETODOS ADICIONALES
            cout<<"for(int PP=1;PP;){";
            archivo<<"for(int PP=1;PP;){\n";

            cout<<"\n";
            for(bool P=1;P;){
                cout<<"\nCONTINUAR: ";
                cin>>Vali;
                if(Vali=="si"){
                    Vali="si";P=0;
                }
                if(Vali=="no"){
                    Vali="no";P=0;
                }
            }
            cout<<"\n\n";

            if(Vali=="si"){
                ARMAR_AUTOMATA(1,N+1,1,1);
            }else{
                Vali="no";
            }
            ANULAR_CONDICION=1;
        }
        if(cant==1&&NAME[0]=="#ADD_PARAMETROS"){   ///TETODOS ADICIONALES
            cout<<"hola esto creara un aUtomata para parametros\n";
            archivo<<"hola esto creara un aUtomata para parametros\n";


            cout<<"\n";
            for(bool P=1;P;){
                cout<<"\nCONTINUAR: ";
                cin>>Vali;
                if(Vali=="si"){
                    Vali="si";P=0;
                }
                if(Vali=="no"){
                    Vali="no";P=0;
                }
            }
            cout<<"\n\n";

            if(Vali=="si"){
                ARMAR_AUTOMATA(1,N,1,0);
            }else{
                Vali="no";
            }
            ANULAR_CONDICION=1;
        }


        if(ANULAR_CONDICION==0){

        strcpy(CAD,NAME[j].c_str());

        cout << "if(R->DAT_AUT=="<<(char)34<<SINTAXXI.busqueda(CAD)<<(char)34<<"){cout<<R->DAT_AUT<<"
             <<(char)34<<(char)92<<"n"<<(char)34<<";";
        archivo<< "if(R->DAT_AUT=="<<(char)34<<SINTAXXI.busqueda(CAD)<<(char)34<<"){cout<<R->DAT_AUT<<"
             <<(char)34<<(char)92<<"n"<<(char)34<<";";
        if(SINTAXXI.busqueda(CAD)!="cierra_sentencia"){
            cout<<" R=R->der;"<< endl;
            archivo<<" R=R->der;"<< endl;
        }else{
            cout<< endl<< endl;
            archivo<< endl<< endl;
        }

        cout<<"\n";
        for(bool P=1;P;){
            cout<<"\nCONTINUAR: ";
            cin>>Vali;
            if(Vali=="si"){
                Vali="si";P=0;
            }
            if(Vali=="no"){
                Vali="no";P=0;
            }
        }
        cout<<"\n\n";

        if(Vali=="si"){
            ARMAR_AUTOMATA(1,N+1,1,FOR_ADD);
        }else{
            Vali="no";
        }

        cout<<"\n";

        for(SSS=0;SSS<3;SSS++){
                cout<<"\t";
                archivo<<"\t";
        }

        for(N=0;N<BARRA_T;N++){
                cout<<"\t";
                archivo<<"\t";
        }
        cout<<"}";
        archivo<<"}";
        if(BARRA_T){
            if(MOS_Else){

                if(FOR_ADD){
                   cout<<"else{ERROR_AUTOMATA=1;PP=0;}\n" << endl;
                    archivo<<"else{ERROR_AUTOMATA=1;PP=0;}\n" << endl;
                }else{
                    cout<<"else{ERROR_AUTOMATA=1;}\n" << endl;
                    archivo<<"else{ERROR_AUTOMATA=1;}\n" << endl;
                }

            }else{
                cout<<"\n" << endl;
                archivo<<"\n" << endl;
            }
        }
        }ANULAR_CONDICION=0;


    }

    /// crear condicion normal

    /// crear variacion || || ||


    if(cant>1){
        for(SSS=0;SSS<3;SSS++){
            cout<<"\t";
            archivo<<"\t";
        }
        for(N=1;N<BARRA_T;N++){
            cout<<"\t";
            archivo<<"\t";
        }
        if(FOR_ADD){
            cout<<"}else{ERROR_AUTOMATA=1;PP=0;}\n" << endl;
            archivo<<"}else{ERROR_AUTOMATA=1;PP=0;}\n" << endl;
        }else{
            cout<<"}else{ERROR_AUTOMATA=1;}\n" << endl;
            archivo<<"}else{ERROR_AUTOMATA=1;}\n" << endl;
        }
    }


    /// crear variacion || || ||

        if(NAME[0]=="#ADD_BUCLE"){
            for(SSS=0;SSS<3;SSS++){
                cout<<"\t";
                archivo<<"\t";
            }
            for(N=0;N<BARRA_T;N++){
                cout<<"\t";
                archivo<<"\t";
            }
            cout<<"}\n";
            archivo<<"}\n";
        }

        if(Vali=="no"){
            return 0;
        }

    }

};

int main()
{
    SINTAXXI.INTRO_SINTAXIS();

    GENERADOR_AUTOMATA A;

    A.ejecutar();

    return 0;
}
