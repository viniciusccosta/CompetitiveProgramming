#include <bits/stdc++.h>

#define  MAXLINHAS 1030						// SEMPRE um pouco maior que o valor indicado no enunciado
#define MAXCOLUNAS 1030						// SEMPRE um pouco maior que o valor indicado no enunciado

using namespace std;						// Básico de C++
using ii = pair<int,int>;					// Apenas para não termos que ficar escrevendo "pair <int,int>" um monte de vezes no código

char    grid[MAXLINHAS][MAXCOLUNAS];		// GRID = Grafo Implícito, não iremos "criar" um grafo, utilizaremos já a própria matriz que a questão nos passar!
bool visited[MAXLINHAS][MAXCOLUNAS];		// Básico de Grafos

vector <ii> movimentos = { 	{0, 1}, 		// BAIXO		(mantém a linha, aumenta uma coluna que dizer que andaremos para baixo)
							{1, 0}, 		// DIREITA
							{0, -1}, 		// CIMA
							{-1, 0} 		// ESQUERDA
						};

int qtdCmpCx;								// Quantidade de ilhas

void dfs(int linha, int coluna, int qtdCmpCx){
	visited[linha][coluna] = true;
	
	for (auto &movimento : movimentos){
		int dLinha = movimento.first, dColuna = movimento.second;
		
		if (!visited[linha + dLinha][coluna + dColuna] && grid[linha + dLinha][coluna + dColuna] != 'o'){ 	// Vizinho ainda não foi visitado e não é parede?
			dfs(linha + dLinha, coluna + dColuna, qtdCmpCx);												// DFS no vizinho
		}	
	}
}

void inic(){
	
	for (int i = 0; i < MAXLINHAS; i++){
		for (int j = 0; j < MAXCOLUNAS; j++){
			   grid[i][j] =   'o';				// Todo GRID iniciado com o caracter que representa a parede/borda
			visited[i][j] = false;				// Ninguém foi visitado ainda
		}
	}
	
}

int main(){
	int N, M;									// N = quantidade de linhas
	cin >> N >> M;								// M = quantidade de colunas
	
	// Zerando GRID e visited:
	inic();
	
	// Populando GRID:
	for (int i = 1; i <= N; i++){									// Sempre começaremos no 1, para que sempre tenhamos bordas envolta do nosso grafo implícito
		for (int j = 1; j <= M; j++){								// Sempre começaremos no 1, para que sempre tenhamos bordas envolta do nosso grafo implícito
			cin >> grid[i][j];
		}
	}
	
	// DFS:
	for (int linha = 1; linha <= N; linha++){
		for (int coluna = 1; coluna <= M; coluna++){
			if (!visited[linha][coluna] && grid[linha][coluna] != 'o'){		// Não iremos olhar quem já foi visitado e nem quem é borda
				dfs(linha,coluna,qtdCmpCx);
				qtdCmpCx++;
			}
		}
	}
	
	cout << qtdCmpCx << endl;
}
