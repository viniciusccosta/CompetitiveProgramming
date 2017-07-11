#include <bits/stdc++.h>
#define MAX 10010												// 10^4 = 10.000, um pouco a mais = 10.010
using namespace std;

vector<int> grafo[MAX];
bool visited[MAX];
int qtdCaminhos;

void dfs(int v, int T){
	if (v == T){							
		qtdCaminhos++;	 										// Chegamos no T? Ent�o temos um caminho at� ele e s� incrementaremos o contador!
	}															// e desta forma nunca percorreremos os adjacentes do pr�prio T
	else if (qtdCaminhos < 2){									// Se maior ou igual a 2 nem precisa mais continuar!													
		visited[v] = true;
		
		for (auto &w : grafo[v]){			
			if (!visited[w]){									// Como T nunca estar� marcado como visitado,sempre chamar� DFS e incrementaremos o contador!
				dfs(w, T);
			}
		}			
	}
}

int main(){
	int R, C, Q;												// N�mero de v�rtices (de 1 at� R), n�mero de arestas e quantidade de consultas
	int A, B;													// A � o nosso primeiro v�rtice e B o nosso segundo v�rtice
	int S, T;
	
	while (true){
		// Recebendo informa��e sobre grafo:
		scanf("%i %i %i", &R, &C, &Q); 							// cin >> R >> C >> Q;
		
		// Receberemos dados enquanto R,C e Q forem diferentes 0
		if (R == 0 && C == 0 && Q == 0){
			break;
		}
		
		// Inicializando arrays:
		for (int i = 0; i < MAX; i ++){
			grafo[i].clear();									// Limpa lista de adjac�ncia de cada v�rtice
		}
		
		// Populando Grafo:
		while (C--){											// J� que n�o iremos imprimir (nem usar) o valor de C, podemos fazer isso :D
			scanf("%i %i", &A, &B); 							//cin >> A >> B;		// V�rtice 1 <------------> V�rtice 2
			
			grafo[A].push_back(B);
			grafo[B].push_back(A);								// Pois � bidirecional
		}
		
		// Recebendo Consultas:
		while (Q--){											// J� que n�o iremos imprimir (nem usar) o valor de Q, podemos fazer isso :D
			qtdCaminhos = 0;
			for (int i = 0; i < MAX; i++) visited[i] = false; 	// Como iremos realizar um novo DFS, precisamos dizer que ningu�m foi visitado ainda
			
			scanf("%i %i", &S, &T);								// cin >> S >> T;
			dfs(S, T);											// Saindo de S e indo at� T
			
			// Resposta:
			qtdCaminhos == 1 ? printf("Y\n") : printf("N\n"); 	// S� existe 1 caminho entre S e T?
		}
		
		printf("-\n");											// Divis�ria entre cada grafo
	}
	
	return 0;
}
