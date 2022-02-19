#include <iostream>
#include <imagen.h>
using namespace std;

int main()
{
    imagen i;

    i.lee("IMG.pgm");

    i.escribe("Salida.pgm");

    return 0;
}
