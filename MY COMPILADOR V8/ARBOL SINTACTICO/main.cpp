#include <iostream>
using namespace std;
class NODO_ARBOL_SINTACTICO{
    public:
    string DATO_CAD;
    float DATO_D_OPERACION;
    NODO_ARBOL_SINTACTICO *izq,*der,*PaDr;
    NODO_ARBOL_SINTACTICO(string D_CAD="\0",float D_FLOAT=0,NODO_ARBOL_SINTACTICO *Padr=NULL,NODO_ARBOL_SINTACTICO *iz=NULL,NODO_ARBOL_SINTACTICO *de=NULL){
         DATO_CAD=D_CAD;
         DATO_D_OPERACION=D_FLOAT;
         izq=iz;
         der=de;
         PaDr=Padr;
    }
};

class ARBOL_SINTACTICO{
    public:
    NODO_ARBOL_SINTACTICO *raiz,*padr;
    ARBOL_SINTACTICO(){
        raiz=NULL;
        padr=NULL;
    }
    void INSERTAR_ARB_SNTXS(string D_CAD,float D_FLOAT){
         INS_SNTXS(D_CAD,D_FLOAT,raiz,padr);
    }
    void INS_SNTXS(string D_CAD,float D_FLOAT,NODO_ARBOL_SINTACTICO *&R,NODO_ARBOL_SINTACTICO *padr){
         if(R==NULL)
            R=new NODO_ARBOL_SINTACTICO(D_CAD,D_FLOAT,padr);
         else if(D_FLOAT<R->DATO_D_OPERACION)
            INS_SNTXS(D_CAD,D_FLOAT,R->izq,R);
         else
            INS_SNTXS(D_CAD,D_FLOAT,R->der,R);
    }

    void MOSTRAR_ARB_SINTAXS(){
         MOS_SINTXS(raiz,0);
    }
    void MOS_SINTXS(NODO_ARBOL_SINTACTICO *R,int C){
         if(R!=NULL){
            MOS_SINTXS(R->der,C+1);
            for(int i=0;i<C;i++){
                cout<<"   ";
            }
            cout<<R->DATO_CAD<<"\n\n";
            MOS_SINTXS(R->izq,C+1);
         }
    }

    int BUSCAR_ARB_SINTAXIS(int VAL){
         BUS_SINTXS(raiz,VAL);
    }
    int BUS_SINTXS(NODO_ARBOL_SINTACTICO *R,int val){
         if(R!=NULL){
            if(R->DATO_D_OPERACION==val){
                cout<<val;
                return 1;
            }
            if(R->DATO_D_OPERACION>val){
                BUS_SINTXS(R->izq,val);
            }else{
                BUS_SINTXS(R->der,val);
            }
         }
    }

}ARBOL_DE_OPERACION;

void INSERT_SECUENCIA(string,float);

///lista almacena
class NODOLIST{
    public:
    string DAT_AUT;
    float DATO_D_OPERACION;
    NODOLIST *der,*PaDr;
    NODOLIST(string D_CAD,float D_FLOAT,NODOLIST *Padr=NULL,NODOLIST *de=NULL){
         DAT_AUT=D_CAD;
         DATO_D_OPERACION=D_FLOAT;
         der=de;
         PaDr=Padr;
    }
};
class LISTA{
    public:
    NODOLIST *raiz,*padr;
    LISTA(){
        raiz=NULL;
        padr=NULL;
    }
    void InsertarLIST(string D_CAD,float D_FLOAT){
         ins(D_CAD,D_FLOAT,raiz,padr);
    }
    void ins(string D_CAD,float D_FLOAT,NODOLIST *&R,NODOLIST *padr){
         if(R==NULL)
            R=new NODOLIST(D_CAD,D_FLOAT,R);
         else
            ins(D_CAD,D_FLOAT,R->der,R);
    }
    void MostrarLIST(){
         Mos(raiz);
    }
    void Mos(NODOLIST *R){
         if(R!=NULL){
            cout<<R->DAT_AUT<<" ";
            Mos(R->der);
         }
    }
    void ORDENAR_LIST(){
         ORD(raiz);
    }
    int ORDEN_TREE(NODOLIST *R){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            int CONTADOR_SALTOS=0;
            bool FIN_AUTOMATA=0;
            bool ERROR_AUTOMATA=0;
            float izq_D;
            string DT_AUT;
            for(int PP=1;PP;){
                if(R->DAT_AUT=="*"||R->DAT_AUT=="/"){cout<<R->DAT_AUT<<"\n"; R=R->der;

                    if(R->DAT_AUT=="Variable"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                        if(R->DAT_AUT=="Variable"){cout<<R->DAT_AUT<<"\n"; R=R->der;

                        }
                        if(R->DAT_AUT=="+"||R->DAT_AUT=="-"){cout<<R->DAT_AUT<<"\n"; R=R->der;
                            return 0;
                        }

                    }else{R=R->der;}

                }else{R=R->der;}
			}


            if(ERROR_AUTOMATA){
                cout<<"ERROR!!!\n\n\n";
                return 0;
            }
        }return 0;
    }
    void ORD(NODOLIST *R){
         if(R!=NULL){
            int SALTOS,i;

            SALTOS=ORDEN_TREE(R);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;

            if(R!=NULL){

                cout<<R->DAT_AUT<<" ";ORD(R->der);
            }
         }
    }
    bool TIPO_DE_DATO(string TPDAT){
        if(TPDAT=="tipo_int"||TPDAT=="tipo_float"||TPDAT=="tipo_double"||TPDAT=="tipo_long"||TPDAT=="tipo_char"||TPDAT=="tipo_string"){
            return true;
        }else{
            return false;
        }
    }
    void AUTOMATA_LIST(){
        EJECUTAR(raiz);
    }
    int IZQ_TREE(NODOLIST *R){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            int CONTADOR_SALTOS=0;
            bool FIN_AUTOMATA=0;
            bool ERROR_AUTOMATA=0;
            float izq_D;
            string DT_AUT;
            if(R->DAT_AUT=="Variable"||R->DAT_AUT=="Numero"||R->DAT_AUT=="parentesis_abre"){
				if(R->DAT_AUT=="Variable"){izq_D=R->DATO_D_OPERACION;DT_AUT=R->DAT_AUT;

                    R=R->der;
                    if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            INSERT_SECUENCIA(R->DAT_AUT,R->DATO_D_OPERACION);
                            cout<<endl<<R->DAT_AUT<<"--------> OPE\n\n";
                        }
                    }
                    INSERT_SECUENCIA(DT_AUT,izq_D);
                    cout<<izq_D<<".......IZQ\n";
                    return 1;
				}

				if(R->DAT_AUT=="Numero"){izq_D=R->DATO_D_OPERACION;DT_AUT=R->DAT_AUT;
                    R=R->der;
                    if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            INSERT_SECUENCIA(R->DAT_AUT,R->DATO_D_OPERACION);
                            cout<<endl<<R->DAT_AUT<<"--------> OPE\n\n";
                        }
                    }
                    INSERT_SECUENCIA(DT_AUT,izq_D);
                    cout<<izq_D<<".......IZQ\n";
                    return 1;
				}

				if(R->DAT_AUT=="parentesis_abre"){//cout<<"(\n";
                    R=R->der;

					for(int PP=1;PP;){
						if(R->DAT_AUT=="parentesis_abre"||R->DAT_AUT=="parentesis_cierra"){
							if(R->DAT_AUT=="parentesis_abre"){//cout<<"(\n";
                                R=R->der;
                                PP++;
							}

							if(R->DAT_AUT=="parentesis_cierra"){//cout<<")\n";
                                R=R->der;
                                PP--;
							}
						}else{
                            //cout<<R->DAT_AUT<<"\n";
                            R=R->der;
						}
					}
					if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            INSERT_SECUENCIA(R->DAT_AUT,R->DATO_D_OPERACION);
                            cout<<endl<<R->DAT_AUT<<"--------> OPE\n\n";
                        }
                    }

					return 0;
				}

			}

            if(ERROR_AUTOMATA){
                cout<<"ERROR!!!\n\n\n";
                return 0;
            }
        }return 0;
    }
    int DER_TREE(NODOLIST *R){
        cout<<endl;
        ///AUTOMATA MOSTRAR CMD
        if(R!=NULL){
            int CONTADOR_SALTOS=0;
            bool FIN_AUTOMATA=0;
            bool ERROR_AUTOMATA=0;
            int izq_D;
            if(R->DAT_AUT=="Variable"||R->DAT_AUT=="Numero"||R->DAT_AUT=="parentesis_abre"){
				if(R->DAT_AUT=="Variable"){izq_D=R->DATO_D_OPERACION;

                    R=R->der;
                    if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            cout<<endl<<R->DAT_AUT<<"--------> OPE\n\n";
                        }
                    }
                    cout<<izq_D<<".......IZQ\n";
                    return 1;
				}

				if(R->DAT_AUT=="Numero"){izq_D=R->DATO_D_OPERACION;
                    R=R->der;
                    if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            cout<<endl<<R->DAT_AUT<<"--------> OPE\n\n";
                        }
                    }
                    cout<<izq_D<<".....IZQ\n";
                    return 1;
				}

				if(R->DAT_AUT=="parentesis_abre"){cout<<"(\n"; R=R->der;

					for(int PP=1;PP;){
						if(R->DAT_AUT=="parentesis_abre"||R->DAT_AUT=="parentesis_cierra"){
							if(R->DAT_AUT=="parentesis_abre"){cout<<"(\n"; R=R->der;
                                PP++;
							}

							if(R->DAT_AUT=="parentesis_cierra"){cout<<")\n"; R=R->der;
                                PP--;
							}
						}else{
                            cout<<R->DAT_AUT<<"\n";
                            R=R->der;
						}
					}
					if(R){
                        if(R->DAT_AUT=="*"||R->DAT_AUT=="/"||R->DAT_AUT=="+"||R->DAT_AUT=="-"){
                            cout<<endl<<R->DAT_AUT<<"----------------> OPE\n\n";
                        }
                    }

					return 0;
				}

			}

            if(ERROR_AUTOMATA){
                cout<<"ERROR!!!\n\n\n";
                return 0;
            }
        }return 0;
    }

    int EJECUTAR(NODOLIST *R){ ///EJECUTAR FUNCIONES
        if(R!=NULL){
            int SALTOS,i;

            SALTOS=IZQ_TREE(R);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;
/*
            SALTOS=DER_TREE(R);
            for(i=0;i<SALTOS;i++){R=R->der;}SALTOS=0;
*/
            if(R!=NULL){
                //cout<<R->DAT_AUT<<" NULL_AUTOMATA_FUNCION <===>\n";
                EJECUTAR(R->der);
            }
        }

    }
    void IN_LIST(NODOLIST *R){
        bool INICIO_AUTOMATA=0;
        bool FIN_AUTOMATA=0;
        bool ERROR_AUTOMATA=0;
        if(R!=NULL){



            if(R!=NULL){
                if(FIN_AUTOMATA){
                    cout<<"FIN\n\n";
                    IN_LIST(R->der);
                }else{
                    if(ERROR_AUTOMATA){
                        cout<<"error";
                    }else{
                        cout<<"--"<<R->DAT_AUT<<"\n";
                        IN_LIST(R->der);
                    }
                }
            }
            ///automata funciones
        }
    }

    int BuscarLIST(string dat){
         Bus(raiz,dat);
    }
    int Bus(NODOLIST *R,string val){
         if(R!=NULL){
            Bus(R->der,val);
            if(R->DAT_AUT==val){
                 cout<<R->DAT_AUT<<"\n\n";
            }
         }
    }

};
///LISTA DE PALABRAS
LISTA PALABRAS;
LISTA SECUENCIA_ARB_SINTXS;
///LISTA DE PALABRAS

void INSERT_SECUENCIA(string DAT_AUT,float DAT_FLO){
    SECUENCIA_ARB_SINTXS.InsertarLIST(DAT_AUT,DAT_FLO);
}

void insrtt(){
    PALABRAS.InsertarLIST("Numero",1);
    PALABRAS.InsertarLIST("/",1);
    PALABRAS.InsertarLIST("Numero",2);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",3);
    PALABRAS.InsertarLIST("+",1);
    PALABRAS.InsertarLIST("Variable",4);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",5);
    PALABRAS.InsertarLIST("+",1);
    PALABRAS.InsertarLIST("Variable",6);
    PALABRAS.InsertarLIST("+",1);
    PALABRAS.InsertarLIST("Variable",7);
    PALABRAS.InsertarLIST("+",1);
    PALABRAS.InsertarLIST("Variable",8);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",9);
    PALABRAS.InsertarLIST("/",1);
    PALABRAS.InsertarLIST("Variable",10);
    /*
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",1);
    PALABRAS.InsertarLIST("+",1);
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",2);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",3);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Numero",3);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",4);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",5);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",6);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
    PALABRAS.InsertarLIST("/",1);
    PALABRAS.InsertarLIST("Variable",7);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",8);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("parentesis_abre",1);
    PALABRAS.InsertarLIST("Variable",9);
    PALABRAS.InsertarLIST("*",1);
    PALABRAS.InsertarLIST("Variable",10);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
    PALABRAS.InsertarLIST("parentesis_cierra",1);
*/
}

int main(){

    insrtt();
    ARBOL_DE_OPERACION.MOSTRAR_ARB_SINTAXS();

    PALABRAS.AUTOMATA_LIST();

    SECUENCIA_ARB_SINTXS.MostrarLIST();
    //SECUENCIA_ARB_SINTXS.ORDENAR_LIST();
    return 0;
}
