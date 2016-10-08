#include "evaluar.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include <string.h>

int esOperador(char* x){
    if (((*x)=='+') || ((*x)=='*') || ((*x)=='-') || ((*x)=='/'))
        return 1;
    else
        return 0;
}


double suma(lista_t operandos){
    double suma=0;
    int i=0;
    for (;i<operandos->cantidad_elementos;i++)
        suma+=lista_obtener(operandos,i);
    return suma;
}

double mult(lista_t operandos){
    double mult=0;
    int i=0;
    for (;i<operandos->cantidad_elementos;i++)
        mult=mult*lista_obtener(operandos,i);
    return mult;

}

double division(lista_t operandos){
    if (operandos->cantidad_elementos>2)
        exit(OPND_DEMAS);


    return (lista_obtener(operandos,1)/lista_obtener(operandos,0));

}

double resta(lista_t operandos){
    if (operandos->cantidad_elementos!=2)
        exit(OPND_DEMAS);

    return (lista_obtener(operandos,1)-lista_obtener(operandos,0));

}


int calcularPila(pila_t* pila){
	int i;
	lista_t lista=lista_crear();
	for (i=0;esOperador(tope(*pila))==0;i++){
		lista_adjuntar(lista,atoi(desapilar(pila)));
	}
	char* op=desapilar(pila);
	desapilar(pila);

    if (lista->cantidad_elementos<2)
        exit(OPND_INSUF);

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



int insertarEnPila(pila_t* pila,char cad[],int l){
    int i=0;
    char* s=cad;
	while(i<l){
		if (*(s)!=' '){
			if ((*(s))==')'){
                calcularPila(pila);
				/*char a[1];
				a[0]=*s;
				apilar(pila,a);*/
				s++;
				i++;
				}
			else
			{
				//for (;*s==' ';s++)

				if ((*(s)=='(') || (esOperador((s))==1)){
                    char ax[1];
                    ax[0]=*s;
					apilar(pila,ax);
					s++;
					i++;
					}
				else{
					char* aux;
					aux=(char*) malloc(10*sizeof(char));
					char* x=aux;
					for (;(*(s)!=' ') && (*(s)!='\0') && (*(s)!=')') ;s++,x++,i++){
                        *x=*s;
                    }

					apilar(pila,aux);
					//free(aux);
					//aux=NULL;
				 }
			}
		}
	if (*s==' ')
    {s++;
     i++;
     }
  }
}

/*int calcularPila(pila_t* p,char* exp){
    int i=0;
    while (*(exp+i)!='\0'){
        apilar(p,*(exp+i));
        i++;
        }


}*/





