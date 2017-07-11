#include <bits/stdc++.h>
#define MAX 10000 						// 100 * ( (100 - 1) / 2 ) = 4.950
using namespace std;

vector<int> grafo[MAX];					// Array aonde cada posição será uma lista de adjacência
bool visited[MAX];						// Array aonde cada posição dirá se aquele vértice já foi visitado ou não, para não termos ciclos
int k;

void inic(){
	k = 0;								// Reseta a contagem de componentes conexos
	
	for (int i = 0; i < MAX; i++){
		grafo[i].clear();				// Limpa a lista de adjacência de cada vértice
		visited[i] = false;				// Ninguém foi visitado
	}
}

void dfs(int v, int k){
	visited[v] = true;
	
	for (auto &w : grafo[v]){			// Iterando pela lista de adjacência desse vértice
		if(!visited[w]){				// Se esse vizinho ainda não foi visitado:
			dfs(w,k);
		}
	}
}

int main(){
	int T;
	int N, M;
	int v, w;
	
	// Recebendo quantidade de testes:
	cin >> T;
	
	for (int i = 1; i <= T; i++){		// Caso 1, Caso 2, ..., Caso T
		// Reseta variáveis globais:
		inic();
		
		// Recebendo dados:
		cin >> N;						// Quantidade de vértices que existem nesse grafo
		cin >> M;						// Quantidade de arestas  que existem nesse grafo
		
		// Populando Grafo:
		for (int j = 1; j <= M; j++){
			cin >> v >> w;				// Vértice 1 <--------> Vértice 2
			grafo[v].push_back(w);
			grafo[w].push_back(v);		// Pois é um grafo bidirecional
		}
		
		// DFS:
		for (v = 1; v <= N; v++){
			if (!visited[v]){
				dfs(v,k);
				k++;
			}
		}
				
		// Resultado:
		k == 1 ? printf("Caso #%i: a promessa foi cumprida\n", i) : printf("Caso #%i: ainda falta(m) %i estrada(s)\n", i, k - 1);
		
		// Se k igual a 1, significa que só temos 1 componente conexo, ou seja, todas os vértices estão conectados
		// Se k igual a 2, significa que temos 2 componentes conexos, o que significa que precisamos no mínimo 1 aresta para ligar os componentes conexos
		// Se k igual a 3, significa que temos 3 componentes conexos, o que significa que precisamos no mínimo 2 arestas para ligas os componentes conexos
		
	}
	
	return 0;
}
