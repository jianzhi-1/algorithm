#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define sz(a) int((a).size())
#define REP(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define REPD(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define VREP(it, v) for (auto it = v.begin(); it != v.end(); it++)
typedef pair<ll,ll> pi;
typedef vector<ll> vi;

const ll MOD = 1000000009;
const double PI = acos(-1);

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;
int n, q, a, b;
vector<pi> adjList[500005];
//pi chain[10005]; //position of the start of chain on segment tree, length of the chain
vector<vector<int> > heavyChain; //chain of nodes
pair<int, pi> v[500005]; //<position of the node on segment tree, which chain it belongs to, what position in the chain>

int d[500005]; //distance of node from the root
int root = 0;
int p[500005]; //parent of node[x]. parent of root is -1 
const int INF = INT_MAX;

bool isSameHeavyPath(int x, int y){
	//checks if node x and y are in the same heavy path, i.e. the same chain
	return v[x].second.first == v[y].second.first;
}
/*
int getPath(int x, int y){
	//x is ancestor of y

	ll ans = 0;
	
	while (!isSameHeavyPath(x, y)){
		if (v[y].second.second == 0){ //if y is first in its chain
			ans += root -> query(v[y].first, v[y].first);
			y = p[y];
		} else { //shift y to head of chain
			int heady = heavyChain[v[y].second.first][0];
			ans += root -> query(v[heady].first, v[y].first);
			y = p[heady];
		}
	}
	if (y == x) return ans;
	return ans + root -> query(v[x].first + 1, v[y].first);
	
}

int getPathGen(int x, int y){
	//get the sum of all edges from x to y
	int l = lca(x, y);
	return getPath(l, x) + getPath(l, y);
}
*/
int lca(int x, int y){

	while (!isSameHeavyPath(x, y)){
		
		int headx = heavyChain[v[x].second.first][0];
		int heady = heavyChain[v[y].second.first][0];
		
		if (d[headx] < d[heady]){
			y = p[heady];
		} else if (d[heady] < d[headx]){
			x = p[headx];
		} else {
			x = p[headx];
			y = p[heady];
		}
	}
	return (d[x] > d[y])?y:x;
}

int c = 0;
int cc = 0;
void chaindfs(int x){
	v[x] = MP(cc, MP(c, sz(heavyChain[c])));
	heavyChain[c].PB(x);
	cc++;
	REP(i, 0, sz(adjList[x])){
		if (d[adjList[x][i].second] < d[x]) continue;
		if (i != 0) c++;
		chaindfs(adjList[x][i].second);
	}
}

//dfs to set up d and p
int dfs(int x){
	ll cursz = 1;
	REP(i, 0, sz(adjList[x])){
		if (d[adjList[x][i].second] != -1) continue;
		d[adjList[x][i].second] = d[x] + 1;
		p[adjList[x][i].second] = x;
		adjList[x][i].first = dfs(adjList[x][i].second);
		cursz += adjList[x][i].first;
	}
	
	sort(adjList[x].begin(), adjList[x].end());
	reverse(adjList[x].begin(), adjList[x].end());
	return cursz;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	REP(i, 0, n - 1){
		cin >> a;
		adjList[a].PB(MP(-1, i + 1));
		adjList[i + 1].PB(MP(-1, a));
	}
	heavyChain.resize(n);
	memset(d, -1, sizeof(d));
	d[0] = 0;
	p[0] = -1;
	dfs(0);
	//cout << "DONE DFS" << endl;
	chaindfs(0);
	
	REP(i, 0, q){
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
}

//cout.flush()
//cout << fixed << setprecision(9) << x << endl;
