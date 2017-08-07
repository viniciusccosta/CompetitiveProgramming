#include <bits/stdc++.h>
#define MAX 210

using namespace std;

int grid[MAX][MAX];
bool visited[MAX][MAX];
vector < pair <int,int> > movimentos = {{0,1},{0,-1},{1,0},{-1,0}};

int menorCmpCnx = MAX*MAX;												// A menor área começa sendo a maior possível
int tamanhoCmpCnx;														// Quantidade de vértices em cada componente conexo
int qtdCmpCnx;															// Quantidade de componentes conexos (desnecessário)

void dfs(int x, int y, int cor){
	tamanhoCmpCnx ++;
	
	visited[x][y] = true;
	
	for (auto &mov : movimentos){
		int dx = mov.first, dy = mov.second;
		
		if (!visited[dx + x][dy + y] && grid[dx + x][dy + y] == cor){	// Se ainda não foi visitado e são da mesma cor
			dfs(dx + x, dy + y, cor);									// são do mesmo componente conexo
		}
	}
}

void inic(){
	for(int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			grid[i][j] = -1;											// Nossas paredes/bordas serão representadas pelo -1
			visited[i][j] = 0;
		}
	}
}


int main (){
	int N, M;
	
	inic();
	
	cin >> N >> M;
	
	// Populando GRID:
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			cin >> grid[i][j];
		}
	}
	
	// DFS:
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			if (!visited[i][j] && grid[i][j] != -1){ 					// Se ainda não visitamos e se não é uma parede/borda
				tamanhoCmpCnx = 0;
				dfs(i, j, grid[i][j]);
				qtdCmpCnx++; // Desnecessário
				
				menorCmpCnx = min(tamanhoCmpCnx, menorCmpCnx); 			// O menor é o mínimo entre area atual e menor atual
			}
		}
	}
	
	printf("%i\n", menorCmpCnx);

	return 0;
}
