#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include "evaluar.h"




int main(int argc,char const *argv[])
{
    //Probando Pila, ANDA

   pila_t p=pila_crear();

    /*apilar(&p," ");
    apilar(&p," ");
    apilar(&p," ");

    printf("%s\n",desapilar(&p));
    printf("%s\n",desapilar(&p));
    printf("%s",desapilar(&p));


   /* //Probando Lista, ANDA
    int x=1;
    char* g;

    printf("%s",g);


    lista_t l=NULL;


    int i;
   // for (i=0;i<4;i++)
     //   lista_adjuntar(l,i);

   for (i=0;i<lista_cantidad(l);i++)
        printf("%i\n",lista_obtener(l,i));*/


   char* exp=(char*)malloc(100*sizeof(char));
   //char exp[10];
    printf("Ingrese una expresion: ");
    scanf("%[^\n]",exp);
    //printf("%s",exp);
    //printf("%c",*(exp+1));

    //printf("hola");

  int x=insertarEnPila(&p,exp);

   while(pila_vacia(p)==0){
        printf("%c\n",desapilar(&p));
   }
  // while (pila_vacia(p)!=0){
    // printf("%s\n",desapilar(&p));
  //}

}
