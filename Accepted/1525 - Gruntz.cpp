#include <bits/stdc++.h>
#define MAX 110
#define INFINITO 0x3F3F3F3F

using namespace std;
using ii = pair<int,int>;
using iii = tuple<int,int,int>;
ii movimentos[4] = {{0,1},{0,-1},{1,0},{-1,0}};

int inversos[300];
char grid[MAX][MAX];
int dist[MAX][MAX];

int N, M, K;

bool dijkstra(int source_row, int source_col){
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push(iii(0,source_row, source_col));
		dist[source_row][source_col] = 0;
		
		while(not pq.empty()){
			int v_row, v_col, v_dist;
			tie(v_dist, v_row, v_col) = pq.top(); pq.pop();
			char atual = grid[v_row][v_col];
			
			if (v_dist <= dist[v_row][v_col]) {
				
				if ( (v_row == 1 || v_row == N || v_col == 1 || v_col == M) && (dist[v_row][v_col] <= K) ) {
					return true;
				}
				
				for (auto &mov : movimentos){
					
					int w_row, w_col, custo_w;
					w_row = v_row + mov.first;
					w_col = v_col + mov.second;
					
					if( ( mov.first  != 0 && (grid[w_row][w_col] == '^' || grid[w_row][w_col] == 'v') ) ||  
						( mov.second != 0 && (grid[w_row][w_col] == '<' || grid[w_row][w_col] == '>') ) )
					{
										
						if (grid[w_row][w_col] != '#'){
							custo_w = (mov.first == 1 && grid[w_row][w_col] == '^') || (mov.first == -1 && grid[w_row][w_col] == 'v') ||
									(mov.second == 1 && grid[w_row][w_col] == '<') || (mov.second == -1 && grid[w_row][w_col] == '>');
							
							if (dist[w_row][w_col] > v_dist + custo_w){
								pq.push(iii(v_dist + custo_w, w_row, w_col));
								dist[w_row][w_col] = v_dist + custo_w;
							}
						}

					}	
				}
			}
		}
		
		return false;
}

void inic(){
	for (int i = 0; i < MAX; i++){
		for(int j = 0; j < MAX; j++){
			grid[i][j] = '#';
			dist[i][j] = INFINITO;
		}
	}
}

int main (){

	int ini_row, ini_col;
	
	// Solução alternativa (gambiarra, isso mesmo!)
	inversos['<'] = '>';
	inversos['>'] = '<';
	inversos['v'] = '^';
	inversos['^'] = 'v';
	
	while (true){
		inic();
		
		cin >> N >> M >> K;
		if (N == 0 && M == 0 && K == 0) break;
		
		// Populando Grid:
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= M; j++){
				cin >> grid[i][j];
				if (grid[i][j] == '>'){grid[i][j] = '<';}
				else if (grid[i][j] == '<'){grid[i][j] = '>';}
				else if (grid[i][j] == 'v'){grid[i][j] = '^';}
				else if (grid[i][j] == '^'){grid[i][j] = 'v';}
				else if (grid[i][j] == 'x'){
					ini_row = i;
					ini_col = j;
				}
			}
		}
		
		// Dijkstra
		//printf("%s\n", dijkstra(ini_row, ini_col, K) ? "Sim" : "Nao");
		
		(dijkstra(ini_row, ini_col)) ? printf("Sim\n") : printf("Nao\n");
				
	}
	
	return 0;
}
