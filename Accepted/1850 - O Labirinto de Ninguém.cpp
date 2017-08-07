#include <bits/stdc++.h>
#define MAX 110
#define oo 0x3F3F3F3F																// 1.061.109.567
#define qtdStatus (1 << 7)

using namespace std;
using ii = pair<int, int>;
using iiii = tuple <int, int, int, int>;

char grid[MAX][MAX];
int dist[MAX][MAX][qtdStatus];
ii movimentos[4] = {{0,1},{0,-1},{1,0},{-1,0}};

void dijkstra(int source_row, int source_col){
	
	priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
	pq.push(iiii(0, source_row, source_col, 0));									// dist, row, col, status
	dist[source_row][source_col][0] = 0;
	
	
	while (not pq.empty()){
		int v_row, v_col, v_dist, v_status;
		tie(v_dist, v_row, v_col, v_status) = pq.top(); pq.pop();
		
		if(v_dist > dist[v_row][v_col][v_status]) continue;
		
		for (auto &mov : movimentos){
			int w_row    = v_row + mov.first;
			int w_col    = v_col + mov.second;
			int w_dist   = oo;
			int w_status = v_status;
			
			if (grid[w_row][w_col] != '#'){											// Se é um movimento válido:
				
				// ------------------------------------------------------
				if (grid[w_row][w_col] >= 'A' && grid[w_row][w_col] <= 'G'){
					// PORTA:
					int verificacao = w_status; 
					verificacao &= 1 << grid[w_row][w_col] - 'A';					// verificacao &= 1 << portaEncontrada - 'A';
					if (verificacao){
						// Temos a chave dessa porta
						w_dist = v_dist + 1;
					}
				}else if (grid[w_row][w_col] >= 'a' && grid[w_row][w_col] <= 'g'){
					// CHAVE:
					w_status |= 1 << grid[w_row][w_col] - 'a';						// 	registrador |= 1 << chaveEncntrda - 'a';
					w_dist    = v_dist + 1;
				}else if (grid[w_row][w_col] == '*'){
					// Saída
					w_dist = v_dist + 1;
				}else{
					// Espaço disponível
					w_dist = v_dist + 1;
				}
				
				// ------------------------------------------------------
				// Novo menor caminho:
				if (w_dist < dist[w_row][w_col][w_status]){
					pq.push(iiii(w_dist, w_row, w_col, w_status));
					dist[w_row][w_col][w_status] = w_dist;
				}
			}
		}
	}
}

void inic(){
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			grid[i][j] = '#';
			for (int k = 0; k < qtdStatus; k++){
				dist[i][j][k] = oo;
			}
		}
	}	
}

int main (){
	inic();

	int inic_row = 1, inic_col = 1;
	int  end_row = 1,  end_col = 1;
	int i = 1;
	int j = 1;
	char entrada;
	while(scanf("%c", &entrada) != EOF){
		if (entrada == '\n'){
			j = 1;
			i++;
		}
		else if(entrada != '\r'){
			grid[i][j] = entrada;
				
			if (entrada == '@'){
				inic_row = i;
				inic_col = j;
			}else if (entrada == '*'){
				end_row = i;
				end_col = j;
			}
			
			j++;
		}
	}
	j--;
	
	/*
	// PRINTA GRID:
	for (int a = 0; a <= i+1; a++){
		cout << '|';
		for (int b = 0; b <= j+1; b++){
			printf("%c|",grid[a][b]);
		}
		cout << endl;
	}*/
		
	dijkstra(inic_row, inic_col);
	int menor = oo;
	for (auto &status : dist[end_row][end_col]){
		if (status < menor){
			menor  = status;
		}
	}
	
	if (menor == oo) cout << "--" << endl;
	else cout << menor << endl;
	
	return 0;
}

/*
	7 posições
	cada posição pode assumir 2 valores
	2^7 = 128 combinações possíveis
	sendo 2^7 = 1 << 7
	
	|g|f|e|d|c|b|a|
	|0|0|1|0|0|1|0|

	Chave encontrada:
		 chaveEncntrda	= 'd'
		 index 	 		= chaveEncntrda - 'a' = 3
		 mascara  	 	= 1 << index ----> 00000001 << 3 ----> 00001000
		 registrador 	= registrador | mascara
		 registrador 	= |X|0|0|1|1|0|1|0|
		 
		ou simplesmente:
		registrador |= 1 << chaveEncntrda - 'a';
		
	Porta encontrada:
		portaEncontrada = 'D'
		index 			= portaEncontrada - 'A' = 3
		mascara  	 	= 1 << index ----> 00000001 << 3 ----> 00001000
		verificacao 	= registrador & mascara
		
		se verificacao != 0:
			temos a chave
		senao:
			nao temos a chave
			
		ou simplesmente:
		verificacao &= 1 << portaEncontrada - 'A';
*/