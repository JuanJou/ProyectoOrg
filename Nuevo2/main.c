#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"

int main()
{
    //Probando Pila, ANDA
   pila_t p=pila_crear();
    apilar(&p,"f");
    apilar(&p,"s");

    printf("%s\n",desapilar(&p));
    printf("%s\n",desapilar(&p));

    //Probando Lista, ANDA

    lista_t l=lista_crear();
    int i;
    for (i=0;i<4;i++)
        lista_insertar(l,i,i);
    for (i=0;i<4;i++)
        printf("%i\n",lista_obtener(l,i));

}
