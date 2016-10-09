#include "evaluar.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include <string.h>

/** \brief Descripcion del metodo
    Chequea si el puntero a caracter esta apuntando a un operador(+, -, *, /)
*/
int esOperador(char* x){
    if (((*x)=='+') || ((*x)=='*') || ((*x)=='-') || ((*x)=='/'))
        return 1;
    else
        return 0;
}

/*
    Recibe una lista como parametro y calcula la suma de todos los elementos que se encuentra en la misma
*/
double suma(lista_t operandos){
    double suma=0;
    int i=0;
    for (;i<operandos->cantidad_elementos;i++)
        suma+=lista_obtener(operandos,i);
    return suma;
}
/*
    Recibe una lista como parametro y calcula la multiplicacion de todos los elementos que se encuentran en la misma
*/
double mult(lista_t operandos){
    double mult=1;
    int i=0;
    for (;i<operandos->cantidad_elementos;i++)
        mult=mult*lista_obtener(operandos,i);
    return mult;

}
/*
    Recibe una lista como parametro y calcula la division de los dos elementos que se encuentran en la misma
*/
double division(lista_t operandos){
    if (operandos->cantidad_elementos>2){
        printf("DEMASIADOS OPERANDOS");
        exit(OPND_DEMAS);}


    return (lista_obtener(operandos,1)/lista_obtener(operandos,0));

}
/*
    Recibe una lista como parametro y calcula la resta de los dos elementos que se encuentra en la misma
*/
double resta(lista_t operandos){
    if (operandos->cantidad_elementos!=2){
        printf("DEMASIADOS OPERANDOS");
        exit(OPND_DEMAS);
        }


    return (lista_obtener(operandos,1)-lista_obtener(operandos,0));

}

/*
Recibe una pila como parametro y calcula la primer operacion simple que se encuentra almacenada en la misma,
simple se refiere a que tiene dos operadores concretos (+5 6) y no (*(+4 6) 3)
*/
int calcularPila(pila_t* pila){
	int i;
	lista_t lista=lista_crear();
	for (i=0;esOperador(tope(*pila))==0 && tope(*pila)!='(';i++){
		lista_adjuntar(lista,atoi(desapilar(pila)));
	}
	char* op=desapilar(pila);
	desapilar(pila);

    if (lista->cantidad_elementos<2){
        printf("OPERANDOS INSUFICIENTES");
        exit(OPND_INSUF);
        }


	int res=0;

	if (*op=='+')
        res=suma(lista);
    else
        if (*op=='-')
            res=resta(lista);
        else
            if (*op=='*')
                res=mult(lista);
            else
                if (*op=='/')
                    res=division(lista);
                else
                    exit(OPRD_INV);


	char* aux=(char*) malloc(sizeof(char)*10);
    aux=itoa(res,aux,10);
	apilar(pila,aux);


}


/*
    Recibe una cadena por parametro y calcula el resultado de la operacion representada
*/
int insertarEnPila(pila_t* pila,char cad[],int l){
    int i=0;
    char* s=cad;
	while(i<l){
		if (*(s)!=' '){
			if ((*(s))==')'){
                calcularPila(pila);
				s++;
				i++;
				}
			else
			{
				if ((*(s)=='(') || (esOperador((s))==1)){
                    char ax[1];
                    (ax)[0]=*s;
					apilar(pila,ax);
					s++;
					i++;
					}
				else{
					char* aux;
					aux=(char*) malloc(10*sizeof(char));
					char* x=aux;
					for (;(*(s)!=' ') && (*(s)!='\0') && (*(s)!=')') && (*(s)!='(')  ;s++,x++,i++){
                        *x=*s;
                    }

					apilar(pila,aux);
					free(aux);
					aux=NULL;
				 }
			}
		}
	if (*s==' ')
    {s++;
     i++;
     }
  }
}


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
    char aux[strlen(d)];
    int j=0;
    while (j<strlen(aux)){
        aux[j]=*(d++);
        j++;
    }
    int i=0;
    printf("Resultado: %s",aux);

}



