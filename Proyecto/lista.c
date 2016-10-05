#include "lista.h"

lista_t lista_crear(){
    lista_t lista=(lista_t*) malloc(sizeof(lista));
    lista->cantidad_elementos=0;
    lista->primera_celda=NULL;
    return lista;
}

int lista_insertar(lista_t lista, unsigned int pos, int elem){
    celda_t* c=lista->primera_celda;
    //if (pos==lista->cantidad_elementos){
    //    int j;
     //   for
    //}else{
    int i=0;
    for (i=0;i<(int)pos/4;i++){
        if (c->proxima_celda==null)
            exit(EXIT_ON_STATUS);
        else
            if ()
            c=c->proxima_celda;
    }
}

int lista_eliminar(lista_t lista, unsigned int pos){

}

int lista_cantidad(lista_t lista){
    return lista->cantidad_elementos;
}

int lista_obtener(lista_t lista, unsigned pos){

}

int lista_adjuntar(lista_t lista, int elem){

}

int lista_destruir(lista_t* lista){
    free(lista);
    lista=NULL;
}
