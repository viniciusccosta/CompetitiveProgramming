#include <bits/stdc++.h>
#define MAX 1030
using namespace std;

char grid [MAX][MAX];
bool visited[MAX][MAX];
vector < pair<int,int> > movimentos = {{0,1},{0,-1},{1,0},{-1,0}};
int qtdCmpCnx;

void dfs(int x, int y){
	visited[x][y] = true;
	
	for (auto &mov : movimentos){
		int dx = mov.first, dy = mov.second;
		
		if (!visited[dx + x][dy + y] && grid[dx + x][dy + y] != 'o')
			dfs(dx + x, dy + y);
	}	
}

void inic(){
	for(int i = 0; i < MAX;i++)
		for (int j = 0; j < MAX; j++)
			grid[i][j] = 'o';
}

int main (){
	inic();
	
	int N, M;
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
			if (!visited[i][j] && grid[i][j] != 'o'){
				dfs(i, j);
				qtdCmpCnx++;
			}
		}
	}
	
	// Resultado:
	cout << qtdCmpCnx << endl;


	return 0;
}