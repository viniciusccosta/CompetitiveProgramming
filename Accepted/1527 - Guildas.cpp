#include <bits/stdc++.h>
using namespace std;
#define MAX 100010

int ptos[MAX];
class union_find {
	public :
	vector<int> parents, rank;
	
	union_find(int n): parents(n+1), rank(n+1, 0){
		for(int u = 1; u <= n; u++)
			parents[u] = u;
	}
	
	int find_set(int u){
		return u == parents[u] ? u : (parents[u] = find_set(parents[u]));
	}
	
	bool same_set(int u, int v){
		return find_set(u) == find_set(v);
	}
	
	void union_sets(int u, int v){
		if(same_set(u, v))
			return;
		
		int set_u = find_set(u), set_v = find_set(v);
		if(rank[set_u] >= rank[set_v]){
			parents[set_v] = set_u;
			ptos[set_u] += ptos[set_v];
		}else{
			parents[set_u] = set_v;
			ptos[set_v] += ptos[set_u];
		}
		if(rank[set_u] == rank[set_v]) rank[set_u]++;
	}
};


int main(){
	int N, M, Q, A, B, V;
	while(scanf("%d %d", &N, &M), N){
		V = 0;
		memset(ptos, 0, sizeof(ptos));
		union_find uf(MAX);
		for(int i = 1; i <= N; i++)
			scanf("%d", &ptos[i]);

		for(int i = 1; i <= M; i++){
			scanf("%d %d %d", &Q, &A, &B);
			if(Q == 1)
				uf.union_sets(A, B);
			else{
				if(uf.same_set(1, A) and ptos[uf.find_set(A)] > ptos[uf.find_set(B)])
					V++;
				else if(uf.same_set(1, B) and ptos[uf.find_set(B)] > ptos[uf.find_set(A)])
					V++;
			}
		}
		printf("%d\n", V);
	}
	return 0;
}
