#include <bits/stdc++.h>
#define MAX 5000														// 100 * (100 - 1) / 2 = 4950

using namespace std;

vector<int> grafo[MAX];
bool visited[MAX];
int qtdCmpCnx;


void dfs(int v){
	visited[v] = true;
	
	for (auto &w : grafo[v]){
		if (!visited[w]){
			dfs(w);
		}	
	}
}

void inic(){
	for (int v = 0; v < MAX; v++){
		grafo[v].clear();
		visited[v] = false;
	}
	
	qtdCmpCnx = 0;
}

int main (){	
	int T;
	int N, M;
	int v, w;
	
	cin >> T;
	 
	for (int n = 1; n <= T; n++){
		inic();
		
		// Recebendo dados:
		cin >> N >> M;
		
		// Populando Grafo:
		for (int i = 1; i <= M; i++){
			cin >> v >> w;
			grafo[v].push_back(w);
			grafo[w].push_back(v);
		}
				
		// DFS:
		for (int v = 1; v <= N; v++){
			if (!visited[v]){
				dfs(v);
				qtdCmpCnx++;
			}
		}
		
		qtdCmpCnx == 1 ? printf("Caso #%i: a promessa foi cumprida\n", n) : printf("Caso #%i: ainda falta(m) %i estrada(s)\n", n, qtdCmpCnx - 1);
		
		/*
		 Se existem 2 componentes conexos, falta  no mínimo 1 aresta  para conecta-las
		 Se existem 3 componentes conexos, faltam no mínimo 2 arestas para conecta-las
		 ...
		*/
	}
	
	return 0;
}
