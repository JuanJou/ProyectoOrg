#include "pila.h"

pila_t pila_crear(){
    pila_t pila=0;
    return pila;
}

char* tope(pila_t pila){
    if(pila!=0)
        return pila->elemento;
}

char* desapilar(pila_t* pila){
    if((*pila)!=0){
        char* elem=(*pila)->elemento;
        if((*pila)->proximo_elemento!=0)
            (*pila)=(*pila)->proximo_elemento;
        return elem;
    }
}

int apilar(pila_t* pila, char* str){
    pila_t* pilaNueva=0;
   if (pila_vacia(*pila)==0){
         pilaNueva=(pila_t*)malloc(sizeof(pila_t));
        (*pilaNueva)->elemento= (*pila)->elemento;
        (*pilaNueva)->proximo_elemento= (*pila)->proximo_elemento;
        (*pila)->elemento=str;
        (*pila)->proximo_elemento=(*pilaNueva);
        }
        else{
            (*pila)->elemento=str;
            (*pila)->proximo_elemento=0;
        }
}

int pila_vacia(pila_t pila){
    if(pila==0)
        return 1;
    else
        return 0;
}
