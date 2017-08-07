#include <bits/stdc++.h>
#define MAX 510
using namespace std;

using ii = pair<int,int>;

char grid[MAX][MAX];
int  dist[MAX][MAX];
ii movimentos[4] = {{0,1},{0,-1},{1,0},{-1,0}};
int row_maior, col_maior;

void bfs(int row_source, int col_source){
	queue <ii> q;
	q.push(ii(row_source, col_source));
	dist[row_source][col_source] = 0;
	
	while(not q.empty()){
		int row_v, col_v;
		tie(row_v, col_v) = q.front();q.pop();
		
		for (auto &mov : movimentos){
			int row_w, col_w;
			row_w = mov.first + row_v;
			col_w = mov.second + col_v;
			
			if (dist[row_w][col_w] == -1 && grid[row_w][col_w] != '#'){
				q.push(ii(row_w,col_w));
				dist[row_w][col_w] = dist[row_v][col_v] + 1;
				
				// Descobrindo o extremo da árvore:
				if (dist[row_w][col_w] > dist[row_maior][col_maior]){
					row_maior = row_w;
					col_maior = col_w;
				}
			}
		}
	}
	
}

void inic(){
	
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			grid[i][j] = '#';
			dist[i][j] = -1;
		}
	}
}

int main(){
	
	while (true){
		inic();
		int row_inicio, col_inicio;
		
		int N, M;
		cin >> N >> M;
		if(N == 0 && M == 0) break;
		
		int inicio_row = 1, inicio_col = 1;
		// Populando GRID:
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j ++){
				cin >> grid[i][j];
				
				if(grid[i][j] != '#'){
					row_inicio = i;
					col_inicio = j;
				}
			}
		}
		
		row_maior = 1; 
		col_maior = 1;
		// BFS 1:
		bfs(row_inicio,col_inicio);
		
		// BFS 2:
		memset(dist, -1, sizeof(dist));
		bfs(row_maior, col_maior);
		
		// Resultado:
		cout << dist[row_maior][col_maior] << endl;
	}
	 
	return 0;
}
