#include <bits/stdc++.h>
#define MAX 100000								// maior é 9.999 pois invertido é 9.999! Logo MAX = 100.000 pra garantir
#define BLUE 0
#define RED 1
#define WHITE -1

using namespace std;

int color[MAX];
vector <int> graph[MAX];

bool is_bipartite(int source){
	queue <int> q;								// Criamos uma fila
	q.push(source);								// Colocamos na fila
	color[source] = BLUE;						// e setamos a colorância
	
	while (!q.empty()){ 						// Enquanto tem gente na fila ou enquanto não encontramos o destino (pra reduzir o custo, porque se quiser deixar até a fila estar vazia funcionará numa boa)
		int v; 
		v = q.front();							// Pega o primeiro da fila
		q.pop();								// Remove ele da fila (cadê o dequeue? kkkk)
		
		for(auto &w: graph[v]){
			if(color[w] == WHITE){
				color[w] = !color[v];
				q.push(w);
			}else if(color[w] == color[v]){
				return false;
			
			}
		}
	}
	return true;
}


int main(){
	int N, v;
	cin >> N;
	
	memset(color, WHITE, sizeof(color));
	
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= N; j++){
			scanf("%d", &v);
			if(v == 0 and i != j)
				graph[i].push_back(j);
		}
	
	
	for(int v = 1; v <= N; v++)
		if(color[v] == WHITE)
			if(not is_bipartite(v)){
				printf("Fail!\n"); 
				return 0;
			}

	printf("Bazinga!\n"); 
	return 0;
}
