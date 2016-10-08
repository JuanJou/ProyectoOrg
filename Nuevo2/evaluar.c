#include "evaluar.h"
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pila.h"
#include <string.h>

int esOperador(char x){
    if ((x=='+') || (x=='*') || (x=='-') || (x=='/'))
        return 1;
    else
        return 0;
}



int insertarEnPila(pila_t* pila,char* s){
    int i=0;
	while(*(s+i)!='\0'){
		if (*(s+i)!=' '){
			if ((*(s+i))==')')
				apilar(pila,*(s+i));
			else
			{
				//for (;*s==' ';s++)

				if ((*(s+i)=='(')|| (esOperador(*(s+i))==1)){
					apilar(pila,*(s+i));
					}
				else{
					char* aux;
					aux=(char*) malloc(10*sizeof(char));
					for (;*(s+i)!=' ';i++){
                        aux+=i;
						aux=(*(s+i));
                    }

					apilar(pila,aux);
					free(aux);
					aux=NULL;
				}
			}
		}
	i+=1;
  }
}

int calcularPila(pila_t* p,char* exp){
    int i=0;
    while (*(exp+i)!='\0'){
        apilar(p,*(exp+i));
        i++;
        }


}


/*int calcularPila(pila_t* pila){
	int i;
	lista_t lista=lista_crear();
	for (i=0;esOperador(tope(*pila));i++){
		lista_adjuntar(atof(pila_desapilar(pila));
	}
	char* op=pila_desapilar(pila);
	pila_desapilar(pila);

	double res=0;
	switch(op){
		case '+':
			res=suma(lista);
		case '*':
			res=mult(lista);
		case '-':
			res=resta(lista);
		case '/':
			res=division(lista);
	}
	apilar(pila,res);

}*/

