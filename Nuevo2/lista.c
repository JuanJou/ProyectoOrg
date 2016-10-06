#include "lista.h"
#include <stdlib.h>

lista_t lista_crear(){
    lista_t lista=(lista_t) malloc(sizeof(lista));
    lista->cantidad_elementos=0;
    lista->primera_celda=(celda_t*) malloc(sizeof(celda_t));
    lista->primera_celda->proxima_celda=0;
    return lista;
}

int lista_insertar(lista_t lista, unsigned int pos, int elem){
    celda_t* c=lista->primera_celda;
    int i;
    if (pos==lista->cantidad_elementos){
        lista_adjuntar(lista,elem);
    }
    else{
    for (i=0;i<pos/4;i++){
        c=c->proxima_celda;
    }
        c->elementos[pos%4]=elem;
        lista->cantidad_elementos++;
    }
}

int lista_eliminar(lista_t lista, unsigned int pos){
    int i=0;
    celda_t* c=lista->primera_celda;
    for (i=0;i<(int)pos/4;i++){
        c=c->proxima_celda;
    }
    int correr=pos%4+i*4;

    for (;correr<(lista->cantidad_elementos);correr++){
        if (correr%4==0){
            c=c->proxima_celda;
        }
        c->elementos[correr%4]=siguiente_elemento(correr,c);
   }
}

int lista_cantidad(lista_t lista){
    return lista->cantidad_elementos;
}

int lista_obtener(lista_t lista, unsigned pos){
    int i=0;
    celda_t* c=lista->primera_celda;
    for (i=0;i<(int)pos/4;i++){
        c=c->proxima_celda;
    }
    return c->elementos[pos%4];
}

int lista_adjuntar(lista_t lista, int elem){
    celda_t* c=lista->primera_celda;
    int i;
    for (i=0;i<lista->cantidad_elementos/4;i++){
        c=c->proxima_celda;
    }
    c->elementos[(lista->cantidad_elementos)%4]=elem;
    c->proxima_celda= (celda_t*)malloc(sizeof(celda_t));
    (lista->cantidad_elementos)++;
}

int lista_destruir(lista_t* lista){
    free(lista);
    lista=0;
}

int siguiente_elemento(int i,celda_t* c){
    if (i<3)
        return c->elementos[i+1];
    else
        return c->proxima_celda->elementos[0];
}

