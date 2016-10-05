#include "pila.h"

pila_t pila_crear(){
    pila_t pila=NULL;
    return pila;
}

char* tope(pila_t pila){
    if(pila!=NULL)
        return pila->elemento;
}

char* desapilar(pila_t* pila){
    if((*pila)->elemento!=NULL){
        char* elem=(*pila)->elemento;
        if((*pila)->proximo_elemento!=NULL)
            (*pila)=(*pila)->proximo_elemento;
        return elem;
    }
}

int apilar(pila_t* pila, char* str){
   try{ if (pila_vacia(pila)==0){
        pila_t* pilaNueva=(*pila_t) malloc(pila_t);
        pilaNueva->elemento= (*pila)->elemento;
        pilaNueva->proximo_elemento= (*pila)->proximo_elemento;
        (*pila)->elemento=str;
        (*pila)->proximo_elemento= pilaNueva;
        }
        else{
            exit(1);
        }
   } except(EXIT_ON_STATUS){

    }
}

int pila_vacia(pila_t pila){
    if(pila==NULL)
        return 0;
    else
        return 1;
}
