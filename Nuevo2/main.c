#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include "evaluar.h"




int main(int argc,char const *argv[])
{
    //Probando Pila, ANDA
    //if (argc>1)
    //    exit(5);




   pila_t p=pila_crear();

    /*apilar(&p,"carlos");
    apilar(&p,"pepe");
    apilar(&p,"hola");

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
    int longitud=strlen(exp);

    int x=insertarEnPila(&p,exp,longitud);

   while(pila_vacia(p)==0){
        char* d=desapilar(&p);
        printf("%s\n",d);
   }
  // while (pila_vacia(p)!=0){
    // printf("%s\n",desapilar(&p));
  //}

}
