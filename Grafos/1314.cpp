#include <bits/stdc++.h>
#define MAX 10010							// 10^4 = 10.000, um pouco a mais = 10.010
using namespace std;

vector<int> grafo[MAX];
bool visited[MAX];
int k;

void dfs(int v, int k){
	visited[v] = true;
	
	for (auto &w : grafo[v]){
		if (!visited[w]){
			dfs(w, k);
		}
	}
}

void inic(){
	for (int i = 0; i < MAX; i ++){
		visited[i] = false;					// Ninguém foi visitado
		grafo[i].clear();					// Limpa lista de adjacência de cada vértice
	}
}

int main(){
	int R, C, Q;							// Número de vértices (de 1 até R), número de arestas e quantidade de consultas
	int A, B;								// A é o nosso primeiro vértice e B o nosso segundo vértice
	
	cin >> R >> C >> Q;
	
	// Receberemos dados enquanto R,C e Q forem diferentes 0
	while (R != 0 && C != 0 && Q != 0){
		
		// Populando Grafo:
		while (C--){						// Já que não iremos imprimir (nem usar) o valor de C, podemos fazer isso :D
			int A, B;
			cin >> A >> B;					// Vértice 1 < ------------ > Vértice 2
			
			grafo[A].push_back(B);
			grafo[B].push_back(A);			// Pois é bidirecional
		}
		
		// Pré-processamento: DFS
		for (int v = 1; v <= R; v++){
			if (!visited[v]){
				dfs(v, k);
				k++;
			}
		}
		
		// Recebendo Consultas:
		while (Q--){
			int S, T;
			cin >> S >> T;
			
			// Resposta:
			printf("Y\n"); // ou printf("N\n");
		}
		
		// Divisória entre cada grafo:
		printf("-\n");
	}
	
	return 0;
}
