#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define VREP(it, v) for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
typedef pair<ll,ll> pi;
typedef vector<ll> vi;

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int n, a, b;

//original adjList
set<int> adjList[100005];

//temporary adjList to erase edges
set<int> temp[100005];

//adjList after centroid decomposition
vector<int> cc[100005];

int crank[100005]; //rank of centroids, crank = 0 is the root
int p[100005]; //stores the centroid parent
int sts[100005]; //stores subtree size

//DFS to calculate subtree size, including the node itself
int dfs(int x, int parent){
	int ans = 1; 
	for (set<int>::iterator it = temp[x].begin(); it != temp[x].end(); it++){
		if (*it == parent) continue;
		ans += dfs(*it, x);
	}
	return sts[x] = ans;
}

//Finds the centroid, given some arbitrary node x
int centroid(int x){
	int t = dfs(x, -1); //finds the total subtree size
	int cur = x; int parent = -1;
	while (true){
		pair<int,int> m = MP(-1, -1); //<max subtree size, node to move to>
		bool yes = true;
		for (set<int>::iterator it = temp[cur].begin(); it != temp[cur].end(); it++){
			if (*it == parent) continue;
			if (2*sts[*it] > t) yes = false;
			m = max(m, MP(sts[*it], *it));
		}
		if (yes) return cur;
		parent = cur; cur = m.second;
	}
}

//x = arbitary node in the set that we want to find centroid
//prev_centroid = centroid of the previous centroid_decomp call
void centroid_decomp(int x, int prev_centroid){
	int c = centroid(x);
	p[c] = prev_centroid;
	
	if (prev_centroid != -1){
		cc[prev_centroid].PB(c);
		cc[c].PB(prev_centroid);
		crank[c] = crank[prev_centroid] + 1;		
	} else {
		crank[c] = 0;
	}

	for (set<int>::iterator it = temp[c].begin(); it != temp[c].end(); it++){
		temp[*it].erase(c);
		centroid_decomp(*it, c);
	}
	
	temp[c].clear();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	REP(i, 0, n - 1){
		cin >> a >> b; //assuming 0 indexed
		adjList[a].insert(b); adjList[b].insert(a);
		temp[a].insert(b); temp[b].insert(a);
	}
	memset(crank, -1, sizeof(crank));
	centroid_decomp(0, -1);
}

