#include <bits/stdc++.h>
#define MAX 600															// 500
#define INFINITO MAX*MAX*10												// 500 * 500 * 9

using namespace std;
using  ii = pair<int, int>;											// Apenas pra reduzir a escrita
using iii = tuple<int, int, int>;										// Apenas para reduzir a escrita

int  dist[MAX][MAX];
char grid[MAX][MAX];
ii movimentos[4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};						// Baixo, Cima, Direita e Esquerda

void Dijkstra(int source_row, int source_col){
	priority_queue <iii, vector<iii>, greater<iii>> pq;					// Cria uma fila de prioridade aonde cada Nó será: (valor, vértice), aonde vértice é uma coordenada de pontos (linha,coluna) no caso de grafos implícitos e a prioridade será sempre do menor valor
	
	dist[source_row][source_col] = 0;									// Seta a distância	de "Source"					
	pq.push(iii(0, source_row, source_col));							// Insere nosso "Source" na lista
	
	while(!pq.empty()){													// Enquanto tiver gente na fila
		int v_peso, v_row, v_col;
		
		tie(v_peso, v_row, v_col) = pq.top();							// Recebe o primeiro da fila
		pq.pop();														// e tira ele da fila
		
		// Só iremos olhar os vizinhos de "v" se realmente valer a pena:
		if(v_peso <= dist[v_row][v_col]){								// Se o peso de v desenfileirado é menor do que o peso que temos armazenado em "dist", ou é porque ele ainda não foi visitado e está com valor INFINITO ou porque era um falso menor caminho.
			for (auto &mov : movimentos){								// Percorrendo os vizinhos do "v"
				
				int w_row  = mov.first  + v_row; 						// Posição do vizinho (linha)
				int w_col  = mov.second + v_col; 						// Posição do vizinho (coluna)
				int w_peso;												// Peso do vizinho
			
				if (grid[w_row][w_col] != '#'){										// Vamos ignorar as paredes
					if (grid[w_row][w_col] >= '0' && grid[w_row][w_col] <= '9'){ 	// Se é um número, é porque é um monstro, e esses números são os custos das arestas para ir de algum adjacente até esse vértice
						w_peso = v_peso + (grid[w_row][w_col] - '0');				// O peso calculado para "w" é o peso do "v" mais o peso da aresta entre "v" e o vizinho "w"
						
						/* 
						 * char '0' - '0' resulta no número 0 inteiro
						 * char '1' - '0' resulta no número 1 inteiro
						 * char '2' - '0' resulta no número 2 inteiro
						 * ...
						 * char '9' - '0' resulta no número 9 inteiro
						 * */
					}
					else{
						w_peso = v_peso;								// O peso calculado para "w" é o peso do próprio "v" para qualquer outra opção diferente de parede e de monstro
					}
						
					if (w_peso < dist[w_row][w_col]){					// Se o peso calculado para esse vizinho for menor do que o peso que temos armazenado em "dist", ou é porque ele ainda não foi visitado e está com valor INFINITO ou porque era um falso menor caminho
						pq.push(iii(w_peso, w_row, w_col));
						dist[w_row][w_col] = w_peso;
					}
						
				}
			}			
		}
	}	
}

void inic(){
	for (int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			grid[i][j] = '#';											// Todas as posições começam como parede/borda
			dist[i][j] = INFINITO;										// Todas as distâncias começam como infinito
		}
	}
}

int main(){
	inic();																// Inicializa as matrizes

	int N, M;
	cin >> N >> M;
	
	int H_row, H_col;													// Posição Inicial
	int E_row, E_col;													// Posição Final
	
	// Populando GRID:
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> grid[i][j];
			
			if (grid[i][j] == '.') {
				grid[i][j] = '0';										// Iremos alterar para 0 para facilitar nas somas que faremos no Dijkstra 
			}
			else if (grid[i][j] == 'H'){
				H_row = i;
				H_col = j;
			}
			else if (grid[i][j] == 'E'){
				E_row = i;
				E_col = j;
			}
		}
	}
	
	// Dijkstra:
	Dijkstra(H_row, H_col);
	
	// Resultado:
	dist[E_row][E_col] == INFINITO ? printf("ARTSKJID\n") : printf("%i\n", dist[E_row][E_col]);
	
	return 0;
}
