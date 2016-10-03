#include "pila.h"

pila_t pila_crear(){
    pila_t pila=(pila_t*) malloc(sizeof(pila));;
    pila->elemento=NULL;
    pila->proximo_elemento=NULL;
    return pila;
}

char* tope(pila_t pila){
    if(pila->elemento!=NULL)
        return pila->elemento;
}

char* desapilar(pila_t* pila){
    if((*pila)->elemento!=NULL){
        char* elem=(*pila)->elemento;
        if((*pila)->proximo_elemento!=NULL)
            (*pila)=(*pila)->proximo_elemento;
        return *elem;
    }
}

int apilar(pila_t* pila, char* str){
    pila_t pilaNueva;
    pilaNueva->elemento= (*pila)->elemento;
    pilaNueva->proximo_elemento= (*pila)->proximo_elemento;
    (*pila)->elemento= *str;
    (*pila)->proximo_elemento= pilaNueva;
}

int pila_vacia(pila_t pila){
    if(pila->elemento!=NULL)
        return 0;
    else
        return 1;
}
