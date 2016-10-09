#include "pila.h"
#include <stdlib.h>
#include <string.h>

/*
Crea una pila vacia
*/
pila_t pila_crear(){
    pila_t pila=NULL;
    return pila;
}


/*
Devuelve el elemento almacenado en el tope de la pila

*/
char* tope(pila_t pila){
    if(pila!=0)
        return pila->elemento;
    else
        exit(PILA_VACIA);
}
/*
Devuelve el elemento almacenado en el tope de la pila y lo elimina, siendo el siguiente el nuevo tope
*/
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

/*
Almacena un elemento en el tope de la pila
*/
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
/*
Chequea si la pila pasada por parametro esta vacia
*/
int pila_vacia(pila_t pila){
    if(pila==NULL)
        return 1;
    else
        return 0;
}

