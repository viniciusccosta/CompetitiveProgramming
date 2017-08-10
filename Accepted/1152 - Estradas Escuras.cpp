#include <bits/stdc++.h>
#define MAX 200010
using namespace std;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;

vector<ii> graph[MAX];
vector<iii> edges;
vector<iii> tree;

void inic(){
	for (int i = 0; i < MAX; i++){
		graph[i].clear();
	}
	tree.clear();
	edges.clear();
}

class UnionFind{
	public:
		vector<int> parents;
		
		UnionFind(int M) : parents(M+1){
			for (int v = 1; v <= M; v++){
				parents[v] = v;
			}
		}
		
		int find_set(int v){
			return parents[v] == v ? v : parents[v] = find_set(parents[v]);
		}
		
		bool same_set(int v, int w){
			return find_set(v) == find_set(w);
		}
		
		void union_set(int v, int w){
			if (same_set(v,w)) return;
			
			int set_v = find_set(v);
			int set_w = find_set(w);
			
			parents[set_w] = set_v;
		}
	
};

int main (){
	while (true) {
		inic();
		
		int M, N;

		cin >> M >> N;								// In this case M is Vertices and N is Edges
		if (N == 0 and M == 0) break;
		
		UnionFind uf(M);
		
		// Populating GRAPH:
		for (int i = 1; i <= N; i++){
			int v, w, weight;
			cin >> v >> w >> weight;
			v++;									// V and W can be 0, that's why we add 1
			w++;									// V and W can be 0, that's why we add 1
			graph[v].push_back(ii(weight,w));	
			graph[w].push_back(ii(weight,v));
			
			edges.push_back(iii(weight,v,w));		// Kruskall
		}
		
		/*
		// Printing GRAPH:
		for (int v = 1; v <= M; v++){
			printf("V: %i\n",v);
			for (auto &neighbor : graph[v]){
				int weight, w;
				tie(weight, w) = neighbor;
				printf("\tW: %i = %i\n", w, weight);
			}
		}
		*/
		
		// Kruskall
		int saved = 0;
		sort(edges.begin(), edges.end());
		for(auto &edge : edges){
			int weight, v, w;
			tie(weight,v,w) = edge;
			//printf("\n%i (%i) <-> %i (%i)\n",     v, uf.find_set(v),   w, uf.find_set(w));
			if(not uf.same_set(v,w)){
				// Populating TREE:
				uf.union_set(v,w);
				tree.push_back(iii(weight,v,w));
			}else{
				saved += weight;
			}
		}
		
		/*
		// Printing TREE:
		cout << endl;
		for (auto &branch : tree){
			int weight, v, w;
			tie(weight, v, w) = branch;
			printf("%i-%i=%i\n", v,w,weight);
		}
		*/
		
		cout << saved << endl;
	}

	return 0;
}