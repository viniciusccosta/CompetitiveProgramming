#include <bits/stdc++.h>
#define MAX 10010
#define INFINITO 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector <ii> grafo[MAX];									// Cada nó da lista de adjacência de cada vértice possuirá dois valores: (custo_aresta, vizinho)
int dist[MAX][2];

void inic(){
     for (int i = 0; i < MAX; i++){
         grafo[i].clear();								// Todos os vértices começam sem nenhum vizinho
         dist[i][PAR] = INFINITO;							// Peso/distância de todos começa com infinito
         dist[i][IMPAR] = INFINITO;
     }     
}

void dijkstra(int source){
     priority_queue < iii, vector<iii>, greater<iii> > pq;	// Criando fila de prioridades, aonde cada nó será (dist, vértice) e será ordenado pelo menor valor de distâncias
     dist[source][PAR] = 0;									// Setando a distância
     pq.push(iii(0,source, PAR));							// Inserindo na fila de prioridades
     
	while(!pq.empty()){									// Enquanto tiver gente na fila
		int dist_v, v, estado;
		tie(dist_v, v, estado) = pq.top();pq.pop();				// Recebendo o primeiro da fila
		if (dist_v <= dist[v][estado]){									// Se o valor que já achamos pra esse vértice é menor que o valor que desenfileiramos, simplesmente não faça nada
			for (auto &vizinho : grafo[v]){				// Percorrendo vizinhos do v
				int w, custo_aresta;
				tie(custo_aresta, w) = vizinho;
				int dist_w = custo_aresta + dist[v][estado]; 		// Calculando dist do vizinho que é igual ao dist do pai + custo da aresta entre pai e filho
				
				if (dist_w < dist[w][!estado]){					// Se dist_w é menor que dist[w] de duas uma: ou ainda não haviamos visitado esse vértice (e o dist dele seria infinito) ou é porque era um falso menor caminho
					dist[w][!estado] = dist_w;					// Seta o novo dist
					pq.push(iii(dist_w, w, !estado));				// Adiciona na fila
				}
			}      
		}
	}    
}

int main (){
    inic();
	
	int N, M;
	cin >> N >> M;										// Quantidade de vértice e quantidade de arestas que serão informadas
	
	// Populando Grafo:
	for (int i = 1; i <= M; i++){
		int v,w,custo;
		cin >> v >> w >> custo;
		grafo[v].push_back(ii(custo, w));				// A cada nó da lista de adjacência possui 2 valores: o vizinho e o custo da aresta entre v e w
		grafo[w].push_back(ii(custo, v));				// Só porque é bidirecional
	}	
	
	// Dijkstra:
	dijkstra(1);
	
	if(dist[N][PAR] == INFINITO)
		printf("-1\n");
	else
		printf("%d\n", dist[N][PAR]);
    
    return 0;    
}
