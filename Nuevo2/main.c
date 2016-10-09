#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include "evaluar.h"
#include <string.h>




int main(int argc,char const *argv[])
{
   pila_t p=pila_crear();


    char* exp=(char*)malloc(100*sizeof(char));
    printf("Ingrese una expresion: ");
    scanf("%[^\n]",exp);
    int longitud=strlen(exp);

    insertarEnPila(&p,exp,longitud);

    char* d;
    while(pila_vacia(p)==0){
        d=desapilar(&p);
    }
    char aux[2];
    int j=0;
    while (j<2){
        aux[j]=*(d++);
        j++;
    }
    int i=0;
    printf("Resultado: %s",aux);
    /*while (i<strlen(aux)){
        printf("%c",aux[i]);
        i++;
        }*/

}
