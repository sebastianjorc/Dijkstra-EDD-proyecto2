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
//Aquí sirve para la interacción, osea estatico.

//---------------------------------------------------------------------------------------------------
// PROTOTIPOS	
//void inicializar_matriz(int matriz[tam][tam]);
void inicializar_nodos(Grafo *G);
void inicializar_grafo(Grafo *G);
void imprimir_grafo(Grafo G);
void drijkstra(Grafo G, int S, Nodo nodoActual);
//---------------------------------------------------------------------------------------------------
//void inicializar_matriz(int matriz[tam][tam]){
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
//				 a.b.c.d.e.f.g.h.i
//				 0.1.2.3.4.5.6.7.8
	int matriz[tam][tam]={	{0,3,4,5,5,0,0,0,0},//0a
		     		{3,0,4,0,0,0,0,0,0},//1b
 		    		{4,4,0,0,1,0,0,0,0},//2c
		 		{5,0,0,0,1,5,0,0,0},//3d
				{0,0,1,3,0,1,0,0,0},//4e
				{0,0,0,1,4,0,0,0,4},//5f
				{0,0,0,0,0,0,0,4,8},//6g
				{0,0,0,0,0,0,3,0,1},//7h
				{0,0,0,0,0,5,1,2,0} //8i
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

	printf("\t\ta  b  c  d  e  f  g  h  i\n");
	printf("\t\t0  1  2  3  4  5  6  7  8\n");
	for (int i=0; i<tam; i++){
		printf("\t\t");
		for (int j=0; j<tam; j++){
			printf("%i  ", (G.pesos[i][j]) );
		}
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------
void imprimir_nodos(Grafo G){

	for (int i=0; i<tam; i++){
		imprimir_nodo(G.nodos[i]);
		printf("\n");
	}
}
//---------------------------------------------------------------------------------------------------
void imprimir_grafo(Grafo G){
	imprimir_matriz(G);
	imprimir_nodos(G);
}
//---------------------------------------------------------------------------------------------------
Nodo sacar_de_cola(Nodo cola[tam+1]){
	
}
//---------------------------------------------------------------------------------------------------
void agregar_a_la_cola(Nodo Cola[tam+1], Nodo i, int peso){

}
//---------------------------------------------------------------------------------------------------
int peso (Grafo G, Nodo u, Nodo v){
	int aux=G.pesos[u.pos][v.pos];
	return (aux);
}
//---------------------------------------------------------------------------------------------------
void drijkstra(Grafo G, int S, Nodo nodoActual){
	Nodo u, cola[tam+1];
	inicializar_cola(cola);
	G.nodos[nodoActual.pos].peso=nodoActual.peso=0;	
	agregar_a_la_cola(cola,G.nodos[i],G.nodos[i].peso);
		while (cola[0].pos!=-1){
		u=sacar_de_ cola(cola);
		G.nodos[u.pos].color=2;
		for (int i=0; i<tam; i++){
			if ( ( ( G.pesos[u.pos][i]) > 0 ) && ( ( G.nodos[i].color ) !=2 ) ){
				if (G.nodos[i].peso > ( G.nodos[u.pos].peso + peso ( G,u,( G.nodos[i]) ) ) ){
					G.nodos[i].peso=( G.nodos[u.pos].peso + peso ( G,u, ( G.nodos[i] ) ) );
//					G.nodos[i].padre=u;
					agregar_a_la_cola(&cola,G.nodos[i],G.nodos[i].peso)				;
				}
			}
		}
	}
}
//---------------------------------------------------------------------------------------------------
