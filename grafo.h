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
void drijkstra(Grafo G, int S, Nodo nodoActual){
	//inicializo el grafo -> Viene inicializado. ✓
	nodoActual.peso=0;	nodoActual.color=2;
//	Nodo D[tam]=G.nodos; 
//	1.- 	Inicializar todas las distancias en D con un valor infinito relativo ya que son desconocidas al principio, exceptuando la de x que se debe colocar en 0 debido a que la distancia de x a x sería 0.

	int a=G.nodos[3].pos;

//2.- Sea a = x (tomamos a como nodo actual).
	for (int i=0; i<tam; i++){
		if ( ( ( G.pesos[ (G.nodos[a].pos) ][i]) > 0 ) && ( ( G.nodos[i].color ) !=2 ) ){
			G.nodos[i].peso = (G.pesos[(G.nodos[a].pos)][i]);
			if ()
		}
	}
//3.- Recorremos todos los nodos adyacentes de a, excepto los nodos marcados, llamaremos a estos nodos no marcados vi.

//	nodoActual

//4.- Para el nodo actual, calculamos la distancia tentativa desde dicho nodo a sus vecinos con la siguiente fórmula: dt(vi) = Da + d(a,vi). Es decir, la distancia tentativa del nodo ‘vi’ es la distancia que actualmente tiene el nodo en el vector D más la distancia desde dicho el nodo ‘a’ (el actual) al nodo vi. Si la distancia tentativa es menor que la distancia almacenada en el vector, actualizamos el vector con esta distancia tentativa. Es decir: Si dt(vi) < Dvi → Dvi = dt(vi)

//5.-Marcamos como completo el nodo a.

//6.-Tomamos como próximo nodo actual el de menor valor en D (puede hacerse almacenando los valores en una cola de prioridad) y volvemos al paso 3 mientras existan nodos no marcados.
	
	
}
//---------------------------------------------------------------------------------------------------
