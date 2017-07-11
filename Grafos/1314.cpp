#include <bits/stdc++.h>
#define MAX 10010												// 10^4 = 10.000, um pouco a mais = 10.010
using namespace std;

vector<int> grafo[MAX];
bool visited[MAX];
int qtdCaminhos;

void dfs(int v, int T){
	if (v == T){							
		qtdCaminhos++;	 										// Chegamos no T? Então temos um caminho até ele e só incrementaremos o contador!
	}															// e desta forma nunca percorreremos os adjacentes do próprio T
	else if (qtdCaminhos < 2){									// Se maior ou igual a 2 nem precisa mais continuar!													
		visited[v] = true;
		
		for (auto &w : grafo[v]){			
			if (!visited[w]){									// Como T nunca estará marcado como visitado,sempre chamará DFS e incrementaremos o contador!
				dfs(w, T);
			}
		}			
	}
}

int main(){
	int R, C, Q;												// Número de vértices (de 1 até R), número de arestas e quantidade de consultas
	int A, B;													// A é o nosso primeiro vértice e B o nosso segundo vértice
	int S, T;
	
	while (true){
		// Recebendo informaçõe sobre grafo:
		scanf("%i %i %i", &R, &C, &Q); 							// cin >> R >> C >> Q;
		
		// Receberemos dados enquanto R,C e Q forem diferentes 0
		if (R == 0 && C == 0 && Q == 0){
			break;
		}
		
		// Inicializando arrays:
		for (int i = 0; i < MAX; i ++){
			grafo[i].clear();									// Limpa lista de adjacência de cada vértice
		}
		
		// Populando Grafo:
		while (C--){											// Já que não iremos imprimir (nem usar) o valor de C, podemos fazer isso :D
			scanf("%i %i", &A, &B); 							//cin >> A >> B;		// Vértice 1 <------------> Vértice 2
			
			grafo[A].push_back(B);
			grafo[B].push_back(A);								// Pois é bidirecional
		}
		
		// Recebendo Consultas:
		while (Q--){											// Já que não iremos imprimir (nem usar) o valor de Q, podemos fazer isso :D
			qtdCaminhos = 0;
			for (int i = 0; i < MAX; i++) visited[i] = false; 	// Como iremos realizar um novo DFS, precisamos dizer que ninguém foi visitado ainda
			
			scanf("%i %i", &S, &T);								// cin >> S >> T;
			dfs(S, T);											// Saindo de S e indo até T
			
			// Resposta:
			qtdCaminhos == 1 ? printf("Y\n") : printf("N\n"); 	// Só existe 1 caminho entre S e T?
		}
		
		printf("-\n");											// Divisória entre cada grafo
	}
	
	return 0;
}
