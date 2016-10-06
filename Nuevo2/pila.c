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
        return "hola";
}

char* desapilar(pila_t* pila){

   if((*pila)!=0){
        char* elem=(*pila)->elemento;
            if(((*pila)->proximo_elemento)!=0){
                (*pila)=(*pila)->proximo_elemento;
            }
            else{
                (*pila)=0;
            }
        free(elem);
        return elem;
    }
    return "kj";
}

int apilar(pila_t* pila, char* str){
    pila_t pilaNueva=(pila_t) malloc(sizeof(pila_t));

    char* cadena=(char*) malloc(10*sizeof(char));
    cadena=str;

    if ((*pila)!=0){
        pilaNueva->elemento= (*pila)->elemento;
        pilaNueva->proximo_elemento= (*pila)->proximo_elemento;
        (*pila)->elemento= cadena;
        (*pila)->proximo_elemento= pilaNueva;
   }
   else {
        (*pila)=(pila_t) malloc(sizeof(pila_t));
        strcpy((*pila)->elemento,cadena);
        (*pila)->proximo_elemento=0;
   }
   return 0;
}

int pila_vacia(pila_t pila){
    if(pila==0)
        return 1;
    else
        return 0;
}

