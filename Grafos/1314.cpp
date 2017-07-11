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
		visited[i] = false;					// Ningu�m foi visitado
		grafo[i].clear();					// Limpa lista de adjac�ncia de cada v�rtice
	}
}

int main(){
	int R, C, Q;							// N�mero de v�rtices (de 1 at� R), n�mero de arestas e quantidade de consultas
	int A, B;								// A � o nosso primeiro v�rtice e B o nosso segundo v�rtice
	
	cin >> R >> C >> Q;
	
	// Receberemos dados enquanto R,C e Q forem diferentes 0
	while (R != 0 && C != 0 && Q != 0){
		
		// Populando Grafo:
		while (C--){						// J� que n�o iremos imprimir (nem usar) o valor de C, podemos fazer isso :D
			int A, B;
			cin >> A >> B;					// V�rtice 1 < ------------ > V�rtice 2
			
			grafo[A].push_back(B);
			grafo[B].push_back(A);			// Pois � bidirecional
		}
		
		// Pr�-processamento: DFS
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
		
		// Divis�ria entre cada grafo:
		printf("-\n");
	}
	
	return 0;
}
