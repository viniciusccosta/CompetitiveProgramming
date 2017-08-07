#include <bits/stdc++.h>
#define MAX 100000								// maior é 9.999 pois invertido é 9.999! Logo MAX = 100.000 pra garantir

using namespace std;

int dist[MAX];

int inv(int v){
	int w = 0;
	
	// Exemplo: 432
	while(v){									// Enquanto v não é 0:
		w *= 10;								// 000 * 10 = 00  ----> 02 * 10 = 20  ----> 023 * 10 = 230
		w += (v % 10);							// 000 + 02 = 00  ----> 20 + 03 = 23  ----> 230 + 04 = 234
		v /= 10;								// 432 / 10 = 43  ----> 43 / 10 = 04  ----> 004 / 10 = 000
	}
	
	return w;
}

void bfs(int source, int destino){
	queue <int> q;								// Criamos uma fila
	q.push(source);								// Colocamos na fila
	dist[source] = 0;							// e setamos a distância
	
	while (!q.empty() && dist[destino] == -1){ // Enquanto tem gente na fila ou enquanto não encontramos o destino (pra reduzir o custo, porque se quiser deixar até a fila estar vazia funcionará numa boa)
		int v, w; 
		v = q.front();
		q.pop();
		
		// Percorrendo vizinhos do v:
		w = v + 1;								// Primeiro vizinho é o "v + 1"
		if (dist[w] == -1){						// Se ainda não haviamos "encontrado" esse vizinho
			q.push(w);							// Colocamos ele na fila
			dist[w] = dist[v] + 1;				// e setamos a sua distância
		}
		
		w = inv(v);								// Segundo vizinho é o "inverso do v"
		if (dist[w] == -1){						// Se ainda não haviamos "encontrado" esse vizinho
			q.push(w);							// Colocamos ele na fila
			dist[w] = dist[v] + 1;				// e setamos a sua distância
		}
	}
}


int main(){
	int T;
	cin >> T;
	
	while (T--){
		memset(dist, -1, sizeof(dist));
		
		int source, destino;
		// Recebendo dados:
		cin >> source >> destino;
		
		// BSF:
		bfs(source, destino);
		
		// Resultado:
		cout << dist[destino] << endl;
	}
}
