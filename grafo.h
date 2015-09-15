//---------------------------------------------------------------------------------------------------
#ifndef stdio_h
#include <stdio.h>
#define stdio_h
#endif
//---------------------------------------------------------------------------------------------------
#ifndef stdlib_h
#include <stdlib.h>
#define stdlib_h
#endif
//---------------------------------------------------------------------------------------------------
#ifndef nodo_h
#include "nodo.h"
#define nodo_h
#endif
//---------------------------------------------------------------------------------------------------
# define tam 9
//---------------------------------------------------------------------------------------------------
typedef struct tipo_grafo{	int pesos [tam][tam];	Nodo nodos[tam];}Grafo;
//---------------------------------------------------------------------------------------------------
// PROTOTIPOS	
//void inicializar_matriz(int matriz[tam][tam]);
void inicializar_nodos(Grafo *G);
void inicializar_grafo(Grafo *G);
void inicializar_cola(Nodo Cola[tam+1]);
int peso (Grafo G, Nodo u, Nodo v);
Nodo sacar_de_cola(Nodo cola[tam+1]);
void agregar_a_la_cola(Nodo cola[tam+1], Nodo i);
int cola_es_vacia(Nodo cola[tam+1]);
void imprimir_grafo(Grafo G);
void imprimir_nodos(Grafo G);
void imprimir_matriz(Grafo G);
void drijkstra(Grafo G, int S, int inicio);
//---------------------------------------------------------------------------------------------------
void inicializar_nodos(Grafo *G){

	(*G).nodos[0].letra='a';	(*G).nodos[1].letra='b';	(*G).nodos[2].letra='c';	
	(*G).nodos[3].letra='d';	(*G).nodos[4].letra='e';	(*G).nodos[5].letra='f';
	(*G).nodos[6].letra='g';	(*G).nodos[7].letra='h';	(*G).nodos[8].letra='i';

	for (int i=0; i<tam; i++){
		(*G).nodos[i].pos=i;
		(*G).nodos[i].peso=999;
		(*G).nodos[i].color=0;
	}
}
//---------------------------------------------------------------------------------------------------
void inicializar_grafo(Grafo *G){
//				  a. b. c. d. e. f. g. h. i
//				  0. 1. 2. 3. 4. 5. 6. 7. 8
	int matriz[tam][tam]={	{ 0, 4, 0, 0, 0, 0, 0, 8, 0},//0a
		     		{ 4, 0, 8, 0, 0, 0, 0,11, 0},//1b
 		    		{ 0, 8, 0, 7, 0, 4, 0, 0, 2},//2c
		 		{ 0, 0, 7, 0, 9, 0,14, 0, 0},//3d
				{ 0, 0, 0, 9, 0,10, 0, 0, 0},//4e
				{ 0, 0, 4, 0,10, 0, 2, 0, 4},//5f
				{ 0, 0, 0,14, 0, 2, 0, 1, 6},//6g
				{ 8,11, 0, 0, 0, 0, 1, 0, 7},//7h
				{ 0, 0, 2, 0, 0, 5, 6, 7, 0} //8i
				};
	inicializar_nodos(G);
	for (int i=0; i<tam; i++){
		for (int j=0; j<tam; j++){
			(*G).pesos[i][j]=matriz[i][j];
		}
	}
}
//---------------------------------------------------------------------------------------------------
void inicializar_cola (Nodo cola[tam+1]){
	for (int i=0; i<tam+1; i++){
		cola[i].pos=-1;
	}
}
//---------------------------------------------------------------------------------------------------
void imprimir_matriz(Grafo G){

	printf("\nA continuación se moestrará la matriz de adyacencia del Grafo:\n");getchar();
	printf("Nombres:\t a   b   c   d   e   f   g   h   i\n");
	printf("Posiciones:\t 0   1   2   3   4   5   6   7   8\n");
	for (int i=0; i<tam; i++){
		printf("\t\t");
		for (int j=0; j<tam; j++){
			if (G.pesos[i][j]<10){
				printf(" %i  ", (G.pesos[i][j]) );
			}
			else{
				printf("%i  ", (G.pesos[i][j]) );
			}
		}
		printf("\n");
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------
void imprimir_nodos(Grafo G){

	printf("\nA continuación se moestrarán los nodos del Grafo:\n");getchar();
	for (int i=0; i<tam; i++){
		imprimir_nodo(G.nodos[i]);
	}
	printf("\n");
}
//---------------------------------------------------------------------------------------------------
void imprimir_grafo(Grafo G){
	imprimir_matriz(G);
	imprimir_nodos(G);
}
//---------------------------------------------------------------------------------------------------
int cola_es_vacia(Nodo cola[tam+1]){
	if (cola[0].pos==-1){
		return 1;
	}
	return 0;	
}
//---------------------------------------------------------------------------------------------------
void agregar_a_la_cola(Nodo cola[tam+1], Nodo i){
	Nodo aux;
	int loong=0;
	while (cola[loong].pos!=-1){
		loong++;
	}
	if (cola_es_vacia(cola)==1){
		cola[0]=i;
	}
	while (loong>0){
		cola[loong+1]=i;
		
		if (cola[loong+1].peso < cola[loong].peso){
			aux=cola[loong];
			cola[loong]=cola[loong+1];
			cola[loong+1]=aux;
		}
		loong--;
	}	
}
//---------------------------------------------------------------------------------------------------
Nodo sacar_de_cola(Nodo cola[tam+1]){
	Nodo aux=cola[0];
	for (int i=0; i<tam; i++){
		cola[i]=cola[i+1];
	}
	return (aux);
}
//---------------------------------------------------------------------------------------------------
int peso (Grafo G, Nodo u, Nodo v){
	int aux=G.pesos[u.pos][v.pos];
	return (aux);
}
//---------------------------------------------------------------------------------------------------
void drijkstra(Grafo G, int S, int inicio){
	Nodo u, cola[tam+1];
	inicializar_cola(cola);
	G.nodos[inicio].peso=0;	
	agregar_a_la_cola(cola,G.nodos[inicio]);

	while (cola[0].pos!=-1){
		u=sacar_de_cola(cola);
		G.nodos[u.pos].color=2;

		for (int i=0; i<tam; i++){
			if ( ( ( G.pesos[u.pos][i]) > 0 ) && ( ( G.nodos[i].color ) !=2 ) ){
				Nodo v=G.nodos[i];
				if (v.peso > ( G.nodos[u.pos].peso + peso(G,u,v) ) ){
					G.nodos[i].peso=( G.nodos[u.pos].peso + peso(G,u,v) );
					agregar_a_la_cola(cola,G.nodos[i]);
				}
			}
		}
	}
	printf("\nEl resultado seria:\n");
	imprimir_nodos(G);
}
//---------------------------------------------------------------------------------------------------
