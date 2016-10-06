#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"

int main()
{
   pila_t p=pila_crear();

   apilar(&p,"1");
   apilar(&p,"5");

   printf("%s",desapilar(&p));
   printf("%s",desapilar(&p));
}
