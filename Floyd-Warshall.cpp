#include <stdio.h>

#define INF 99999
#define MAX 10
int origem, destino;

void ImprimirGrafo(int Grafo[MAX][MAX]);
void ImprimirDistancia(int Distancia[MAX][MAX]);
void ImprimirSequencia(int Sequencia[MAX][MAX]);
void ImprimirCaminho(int Sequencia[MAX][MAX]);
void FloydWarshall(int Grafo[MAX][MAX], int Sequencia[MAX][MAX]);

int main() {
	
	printf("\n\t Algoritimo Floyd-Warshall \n\n");
	
	int Grafo[MAX][MAX] = {
		{INF, 5, INF, INF, INF, 8, INF, INF, INF, 2}, 
		{5, INF, 1, INF, INF, 3, INF, INF, INF, 3}, 
		{INF, 1, INF, 1, INF, 3, 3, 2, 3, 3}, 
		{INF, INF, 1, INF, 8, 1, 7, 4, 1, 6}, 
		{INF, INF, INF, 8, INF, INF, 9, INF, 4, INF}, 
		{8, 3, 3, 1, INF, INF, 4, 1, INF, INF}, 
		{INF, INF, 3, 7, 9, 4, INF, 4, 6, INF}, 
		{INF, INF, 2, 4, INF, 1, 4, INF, INF, INF},
		{INF, INF, 3, 1, 4, INF, 6, INF, INF, 7}, 
		{2, 3, 3, 6, INF, INF, INF, INF, 7, INF}  
	};
	
	int Sequencia[MAX][MAX] = {
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
		{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    	{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	};
	
	printf("\n\n\t Grafo Original: \n\n");
	ImprimirGrafo(Grafo);
	
	FloydWarshall(Grafo, Sequencia);
	
	return 0;
}

void FloydWarshall(int Grafo[MAX][MAX], int Sequencia[MAX][MAX]) {

	int AuxDestino[MAX][MAX], AuxSequencia[MAX][MAX];
	
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(i == j) {
				AuxDestino[i][j] = INF;
				AuxSequencia[i][j] = INF;
			} else {
				AuxDestino[i][j] = 0;
				AuxSequencia[i][j] = 0;
			}
		}
	}

	for(int k = 0; k < MAX; k++) {

		for(int l = 0; l < MAX; l++) {

			AuxDestino[k][l] = Grafo[k][l];
			AuxSequencia[k][l] = Sequencia[k][l];

			AuxDestino[l][k] = Grafo[l][k];
			AuxSequencia[l][k] = Sequencia[l][k];
		}

		for(int i = 0; i < MAX; i++) {

			if(i == k) {
				continue;
			}
				
			for(int j = 0; j < MAX; j++) {

				if(j == k) {
					continue;
				}
				if(i == j) {
					continue;
				}

				if((Grafo[i][k] * Grafo[k][j] != 0) && (i != j)){
					if(Grafo[i][j] > (Grafo[i][k] + Grafo[k][j])) {
						AuxDestino[i][j] = Grafo[i][k] + Grafo[k][j];
						AuxSequencia[i][j] = (k+1);	
					} 
					else {
						AuxDestino[i][j] = Grafo[i][j];
						AuxSequencia[i][j] = Sequencia[i][j];
					}
				}
				
			}
		}

		for(int i = 0; i < MAX; i++) {
			for(int j = 0; j < MAX; j++) {
				Grafo[i][j] = AuxDestino[i][j];
				Sequencia[i][j] = AuxSequencia[i][j];
			}
		}
	}

	printf("\n\n\t Distancia: \n\n");
	ImprimirDistancia(Grafo);
	printf("\n\n\t Sequencia: \n\n");
	ImprimirSequencia(Sequencia);
	printf("\n\n\t Caminho Percorrido de 1 a 5: \n\n");
	origem = 0;
	destino = 4;
	ImprimirCaminho(Sequencia); //1 a 5

}

void ImprimirGrafo(int Grafo[MAX][MAX]){
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(Grafo[i][j] == INF) {
				printf("%4s ", "INF");
			} else {
				printf("%4d ", Grafo[i][j]);
			}
		}
		printf("\n");
	}
}

void ImprimirDistancia(int Distancia[MAX][MAX]) {

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(Distancia[i][j] == INF) {
				printf("%4s ", "0");
			} else {
				printf("%4d ", Distancia[i][j]);
			}
		}
		printf("\n");
	}
		printf("\n  Distancia minima entre 1 e 5: %d", Distancia[0][4]);
}

void ImprimirSequencia(int Sequencia[MAX][MAX]) {

	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(Sequencia[i][j] == INF) {
				printf("%4d ", i);
			} else {
				printf("%4d ", Sequencia[i][j]);
			}
		}
		printf("\n");
	}
}

void ImprimirCaminho(int Sequencia[MAX][MAX]){
	
	int caminho = 0;
	int i = 0;
	printf("%d ", origem+1);
	for(int parada = 0; parada != -1;){
		if(Sequencia[origem][destino] != (destino+1)){
			printf("- %d ", Sequencia[origem][destino]);
			origem = (Sequencia[origem][destino] - 1);
		}
		else{
		    printf("- %d ", destino+1);
			parada = -1;
		}
	}	
}
