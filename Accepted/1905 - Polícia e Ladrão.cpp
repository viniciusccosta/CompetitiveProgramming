#include <bits/stdc++.h>
#define MAX 10

using namespace std;
int grid[MAX][MAX];
bool visited[MAX][MAX];
vector< pair<int, int> > movimentos = {{0,1},{0,-1},{1,0},{-1,0}};


void dfs(int x, int y){
	visited[x][y] = true;
	
	for (auto &mov : movimentos){
		int dx = mov.first, dy = mov.second;
		if (!visited[dx + x][dy + y] && grid[dx + x][dy + y] == 0){
			dfs(dx + x, dy + y);
		}
	}
}

void inic(){
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++){
			grid[i][j] = 1;
	}
	
	memset(visited, 0, sizeof(visited));
}

int main (){
	
	int T;
	cin >> T;
	
	inic();
	
	// Casos de teste:
	while (T--){
		memset(visited, 0, sizeof(visited));
		
		// Populando grafo:
		for (int i = 1; i <= 5; i++){
			for (int j = 1; j <= 5; j++){
					cin >> grid[i][j];
			}
		}
		
		// DFS:
		dfs(1,1);
		
		// RESULTADO:
		visited[5][5] ? printf("COPS\n") : printf("ROBBERS\n");
	}
	
	return 0;
}
