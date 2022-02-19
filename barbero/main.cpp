#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>
typedef enum {LLENO, CORTADO} respuesta;

#define NUM_CLIENTES 6 // Numero de clientes
#define N 3 // Numero max de clientes en la barberia

int clientes = 0; // Numero de clientes en la barberia
int quien = -1; // Cliente que esta siendo atendido

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER; //para excl mutua ops monitor
pthread_cond_t silla, sillon, sube_sillon, dormir;

void pcliente(int i, char *s) {printf("Cliente: %d -> %s\n", i,s);}
void pbarbero (char *s) {printf("Barbero: -> %s\n", s);}

//———————————– inicio monitor
int entra_barberia(int i) {
pcliente(i,"ENTRO en la barberia");
pthread_mutex_lock( &m );
if (clientes >= N) {pthread_mutex_unlock(&m ); return LLENO;} // No cabe
else {
clientes++;
if (clientes==1) {
pcliente(i,"DESPIERTO al barbero");
pthread_cond_signal(&dormir);
}
else {
pcliente(i,"ESPERO mi turno");
pthread_cond_wait(&silla, &m );
pthread_cond_signal(&sube_sillon);
}
quien = i;
pthread_cond_wait (&sillon, &m ); /* Esperar a que acabe el corte.*/
pcliente(i,"MI PELO TAN LINDAMENTE CORTADO!!!! ADIEU! \n");
pthread_mutex_unlock(&m );
return CORTADO;
}
}

void espera_cliente() {
pthread_mutex_lock( &m );
if (!clientes) {
pbarbero("ME VOY A DORMIR");
pthread_cond_wait(&dormir,&m);
pbarbero("YA VOYYYY!!!");
}
else {
pbarbero("QUE PASE EL SIGUIENTE!!!!");
pthread_cond_signal(&silla );
pthread_cond_wait(&sube_sillon,&m);
}
pthread_mutex_unlock( &m);
}

void fin_corte() {
pthread_mutex_lock(&m);
pthread_cond_signal(&sillon);
clientes-=1;
pbarbero("FIN CORTE");
pthread_mutex_unlock(&m);
}

void corta_pelo() {
int r=rand()%10000;
//usleep(10); (con sube_sillon, ya no es necesario)
pthread_mutex_lock(&m ); // Protege el acceso a la variable “quien”
pbarbero("CORTANDO EL PELO (Chis, Chas, Chis, Chas)");
printf("A %d (%d useg.)\n",quien,r);
pthread_mutex_unlock(&m );
usleep(r);
}

void da_una_vuelta(int i, int t) {
pcliente(i,"VOY a dar una vuelta"); printf(" durante (%d useg.)\n",t);
usleep(t);
pcliente(i,"VENGO de dar una vuelta");
}
// ——————————- fin monitor

void *cliente(void *arg) {
long int i=(long int) arg;
do {da_una_vuelta(i,rand()%10000);} while (entra_barberia(i)==LLENO);
}

void *barbero(void *arg) {
while (1) {espera_cliente(); corta_pelo(); fin_corte();}
}

int main(void) {
long int i;
pthread_t id_clientes[NUM_CLIENTES], id_barbero;
srand( (unsigned)time( NULL ) );

pthread_cond_init(&silla, 0);
pthread_cond_init(&sillon, 0);
pthread_cond_init(&sube_sillon, 0);
pthread_cond_init(&dormir, 0);

pthread_create(&id_barbero, NULL, barbero, NULL); sleep(1);
for (i=0; i<NUM_CLIENTES; i++) pthread_create(&id_clientes[i], NULL, cliente, (void *) i);
for (i=0; i<NUM_CLIENTES; i++) pthread_join(id_clientes[i], NULL);


}
