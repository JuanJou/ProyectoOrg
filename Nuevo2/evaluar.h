#ifndef EVALUAR_H_INCLUDED
#define EVALUAR_H_INCLUDED

#define OPRD_INV   8
#define OPND_INSUF 6
#define OPND_DEMAS 5
#define EXP_MALF   2
#define EXITO EXIT_SUCCESS
#define OPND_INV   7

#include "pila.h"
#include "lista.h"

int calcularPila(pila_t* pila);
int insertarEnPila(pila_t* pila,char s[],int l);
//float suma(lista_t l);
//float mult(lista_t l);
//float d(lista_t l);
//float sub(lista_t l);


#endif // EVALUAR_H_INCLUDED

