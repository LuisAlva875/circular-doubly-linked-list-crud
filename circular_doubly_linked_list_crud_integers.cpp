#include <stdio.h>
#include <stdlib.h>

struct nodo{
	int dato;
	struct nodo *sig;
	struct nodo *ant;
};

nodo *primero=NULL;
nodo *ultimo=NULL;

void insertar ();
void buscar ();
void eliminar ();
void modificar ();
void mostrar ();

int main (){
	
	int op;
	
	do{
		printf("Que operacion realizaras\n");
		printf("1) Insertar\n");
		printf("2) Buscar\n");
		printf("3) Eliminar\n");
		printf("4) Modificar\n");
		printf("5) Mostrar\n");
		printf("6) Salir\n");
		scanf("%d", &op);
		
		switch(op){
			
			case 1:
				insertar();
				break;
				
				case 2:
				buscar();
				break;
				
				case 3:
				eliminar();
				break;
				
				case 4:
				modificar();
				break;
				
				case 5:
				mostrar();
				break;
				
				default:
				printf("\nADIOS");
				break;
		}
	}while(op<6);
}

void insertar(){
	
	nodo *nuevo=(nodo*)malloc(sizeof(nodo));
	
	printf("Ingresa el dato");
	scanf("%d", &nuevo->dato);
	
	if(primero==NULL){
		primero=nuevo;
		primero->sig=primero;
		ultimo=primero;
		primero->ant=ultimo;	
	}
	else
		ultimo->sig=nuevo;
		nuevo->sig=primero;
		nuevo->ant=ultimo;
		ultimo=nuevo;
		primero->ant=ultimo;
}

void buscar(){

	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	int nodoBuscado;
	int encontrado=0;
	
	printf("\nDato a buscar\n");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		do{
			if(actual->dato==nodoBuscado){
				printf("\nSe a encontardo el dato %d\n", actual->dato);
				encontrado=1;			
			}
			actual=actual->sig;
		}while(actual!=primero&&encontrado!=1);

		if(encontrado==0){
			printf("\nNo existe el dato");
			}
		}
	else
		printf("\nLa lista esta vacia");
	}

void modificar(){
	
	struct nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	
	int nodoBuscado;
	int encontrado=0;
	
	printf("\nDato a buscar\n");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		do{
			if(actual->dato==nodoBuscado){
				printf("\nSe a encontardo el dato\n");
				printf("\nIngresa el nuevo dato\n");
				scanf("%d", &actual->dato);
				encontrado=1;
			}
			actual=actual->sig;
		}while(actual!=primero&&encontrado!=1);
		
		if(encontrado==0){
		printf("\nNo existe el dato");
	}
}
	else{
		printf("\nLa lista esta vacia");
	}
}

void eliminar(){
	
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	nodo *ant2=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	ant2=NULL;
	
	int nodoBuscado;
	int encontrado=0;
	
	if(primero!=NULL){
	
		printf("\nIngresa el dato a buscar para eliminarlo\n");
		scanf("%d", &nodoBuscado);
	
		do{
			if(nodoBuscado==actual->dato){
				printf("\nDato encontrado");
				if(actual==primero){	
				primero=primero->sig;
				primero->ant=ultimo;
				ultimo->sig=primero;
			}
			else if(actual==ultimo){
				ultimo=ant2;
				ultimo->sig=primero;
				primero->ant=ultimo;
			}else{
				ant2->sig=actual;
				actual->sig->ant=ant2;
			}
			printf("\nNodo eliminado con exito");
			encontrado=1;
	}
		ant2=actual;
		actual=actual->sig;
}while(actual!=primero&&encontrado!=1);

	if(encontrado==0){
			printf("Nodo no enconrado");
	}
		else
			free(ant2);
	}
	else{
		printf("\nLa lista esta vacia");
	}
}

void mostrar(){
	nodo *actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		do{
			printf("\n%d",actual->dato);
			actual=actual->sig;
		}while (actual!=primero);
		
	}
	else{
		printf("\nLa lista esta vacia");
	}
}
