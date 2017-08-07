#include <bits/stdc++.h>
#define MAX 100000
 
using namespace std;

vector<int> grafo[MAX];
bool visited[MAX];
int qtdFamilias;

void dfs(int v){
	visited[v] = true;
	
	for (auto &w : grafo[v]){
		if (!visited[w]){
			dfs(w);
		}
	}
}

int main(){
	int N, M;
	
	cin >> N >> M;
	
	while (M--){
		int v, w;
		cin >> v >> w;
		grafo[v].push_back(w);
		grafo[w].push_back(v);
	}
	
	for (int i = 1; i <= N; i++){
		if (!visited[i]){
			dfs(i);
			qtdFamilias++;
		}
	}
	
	cout << qtdFamilias << endl;
}
