#include <bits/stdc++.h>
#define MAX 10010										// 10000 + 10
#define INFINITO MAX*MAX*2								// 10000 * 10000 = 100.000.000 * 2 = 200.000.000

using namespace std;									//
using ii = pair <int, int>;								// Usado na fila
using iib = tuple<int, int, bool>;						// Usado no grafo

vector<iib> grafo[MAX];									// Cada nó da lista de adjacência de cada vértice possuirá: (custoAresta, vizinho, arestaSecreta)
int dist[MAX];
vector<int> locaisCriminosos;

void dijkstra(int source, bool grafoSecreto){
	
	priority_queue <ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, source));
	dist[source] = 0;
	
	while(not pq.empty()){
		int dist_v, v;
		tie(dist_v, v) = pq.top(); pq.pop();
		
		if (dist_v <= dist[v]){
			for (auto &vizinho : grafo[v]){
				int custo_aresta, w;
				bool arestaSecreta;
				tie(custo_aresta, w, arestaSecreta) = vizinho;
				
				// Se o grafo é secreto, vai todas as arestas, tanto as secretas quanto as que não são:
				int dist_w;
				if (grafoSecreto){
					dist_w = dist_v + custo_aresta;
				
					if (dist_w < dist[w]){
						pq.push(ii(dist_w, w));
						dist[w] = dist_w;
					}
				}
				// Se o grafo não é secreto, então só podemos ir pelas arestas que não são secretas:
				else if (not arestaSecreta){
					dist_w = dist_v + custo_aresta;
				
					if (dist_w < dist[w]){
						pq.push(ii(dist_w, w));
						dist[w] = dist_w;
					}
				}
			}
		}
	}
}

void inic(){
	for (int i = 0; i < MAX; i++){
		grafo[i].clear();
		dist[i] = INFINITO;
	}
	
	locaisCriminosos.clear();
}

int main (){
	inic();
	
	int N, B, S, C;
	int v, w, custo;
	int Bino, Destino;
	
	// -------------------------------------------
	// Populando Grafo:
	cin >> N >> C >> S >> B;						// Quantidade de Vértices, Arestas Normais, Arestas Secretas, Quantidade de Criminosos
	
	// Arestas Normais:
	for (int i = 1; i <= C; i++){
		cin >> v >> w >> custo;
		grafo[v].push_back(iib(custo,w, false));	// Essa aresta é secreta? Falso!
		grafo[w].push_back(iib(custo,v, false));	// Essa aresta é secreta? Falso!
	}	
	
	// Arestas Secretas
	for (int i = 1; i <= S; i++){
		cin >> v >> w >> custo;	
		grafo[v].push_back(iib(custo,w, true));		// Essa aresta é secreta? Verdadeiro!
		grafo[w].push_back(iib(custo,v, true));		// Essa aresta é secreta? Verdadeiro!
	}
	
	// Local dos Criminosos:
	for (int i = 1; i <= B; i++){
		int local;
		cin >> local;
		locaisCriminosos.push_back(local);			// Armazenando o local de cada criminoso (número do vértice de cada criminoso)
	}

	// Início e Destino:
	cin >> Bino >> Destino;
	
	// -------------------------------------------
	// Dijkstra: 
	int distBino, criminososMortos;
	
	dijkstra(Bino, false);								// Dijkstra no grafo 'Normal'
	distBino = dist[Destino];							// Só precisamos saber do menor custo do Bino até o Destino
	
	for (int i = 0; i <= MAX; i++) dist[i] = INFINITO;	// ... até porque, o array "dist" será resetado!
	dijkstra(Destino, true);			 				// Dijkstra no grafo 'Secreto'		

	criminososMortos = 0;
	for (auto &criminoso : locaisCriminosos){
		if (dist[criminoso] <= distBino){				// Se os criminosos conseguiram chegar antes ou ao mesmo tempo que o Bino no destino, significa que o Bino irá matá-los
			criminososMortos++;
		}
	}
	
	// Resultado:
	cout << criminososMortos << endl;
	return 0;
}