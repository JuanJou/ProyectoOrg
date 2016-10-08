#include "pila.h"
#include <stdlib.h>
#include <string.h>


pila_t pila_crear(){
    pila_t pila=0;
    return pila;
}

char* tope(pila_t pila){
    if(pila!=0)
        return pila->elemento;
    else
        exit(PILA_VACIA);
}

char* desapilar(pila_t* pila){


   if((*pila)!=NULL){
        char* elem=(*pila)->elemento;
            if(((*pila)->proximo_elemento)!=NULL){
                 pila_t aux=(*pila)->proximo_elemento;
                (*pila)=aux;
            }
            else{
                (*pila)=NULL;
            }
       // free(elem);
        return elem;
    }
    else
        exit(PILA_VACIA);
}

int apilar(pila_t* pila, char* str){

    if (pila==0){
        exit(PILA_NO_INI);
    }

    pila_t pilaNueva=(pila_t) malloc(sizeof(pila_t));

    char* cadena=(char*) malloc(10*sizeof(char));
    int i=0;

    for (;i<strlen(str);i++)
        *(cadena+i)=*(str+i);

    if ((*pila)!=0){
        pilaNueva->elemento= (*pila)->elemento;
        pilaNueva->proximo_elemento= (*pila)->proximo_elemento;
        (*pila)->elemento= cadena;
        (*pila)->proximo_elemento= pilaNueva;
   }
   else {
        (*pila)=(pila_t) malloc(sizeof(pila_t));
        (*pila)->elemento=cadena;
        (*pila)->proximo_elemento=0;
   }
   return 0;
}

int pila_vacia(pila_t pila){
    if(pila==NULL)
        return 1;
    else
        return 0;
}

