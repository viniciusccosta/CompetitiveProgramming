#include <bits/stdc++.h>
#define MAX 10010					//10^4 = 10000
using namespace std;

vector<int> grafo[MAX];
int dist[MAX];
int indMaiorDist;

void bfs(int source){
	queue <int> q;
	q.push(source);
	dist[source] = 0;
	
	while(not q.empty()){
		int v = q.front();q.pop();
		
		for (auto &w : grafo[v]){
			if (dist[w] == -1){
				q.push(w);
				dist[w] = dist[v] + 1;
				
				// Descobrindo um dos extremos da árvore:
				if(dist[w] > dist[indMaiorDist]){
					indMaiorDist = w;
				}
			}
		}
	}
}

void inic(){

	for(int i = 0; i < MAX; i++){
		grafo[i].clear();
		dist[i] = -1;
		indMaiorDist = 1;									// Como 1 é sempre a raíz, podemos partir dele
	}
}

int main (){
	while (true){
		inic();
		
		int N;
		cin  >> N;
		if (N == -1) break;
		
		// Populando GRAFO:
		for (int v = 2; v <= N; v++){
			int w;
			cin >> w;
			grafo[v].push_back(w);
			grafo[w].push_back(v);
		}
		
		//BFS 1:
		bfs(1);												// Como 1 é sempre a raíz, podemos partir dele
		
		// BFS 2:
		memset(dist, -1, sizeof(dist));
		bfs(indMaiorDist);
		
		// Resultado:
		cout << (dist[indMaiorDist] + 1) / (2) << endl;     // Poderia ser apenas um ceil(), mas como dividir por inteiro trunca, dá nada! =D
		
	}
	
	return 0;
}