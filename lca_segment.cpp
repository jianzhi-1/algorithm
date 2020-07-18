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

const int MAX_N = 500005;

int n, a, b, q;
//assumes a tree
vector<int> adjList[MAX_N];
vector<int> euler; //the size of this list is 2*E (= O(N) for trees)
//hence segment tree must be declared as at least 2*n
int fvisit[MAX_N];
int height[MAX_N]; 

struct node{
	int s, e, m;
	pi mini; //<lowest height, index>
	node *l, *r;
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), mini(MP(-1,-1)){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	//point update
	void update(int x, int nv){
		
		if (s == e){
			mini = MP(nv, s);
			return;
		}
		if (x > m) r -> update(x, nv);
		if (x <= m) l -> update(x, nv);
		mini = min(l -> mini, r -> mini);
	}
	
	//returns <min, index that points to the minimum element (in the euler vector)>
	//euler[index] gives the LCA
	pi min_index(int x, int y){
		if (s == x && e == y) return mini;
		if (x > m) return r -> min_index(x, y);
		if (y <= m) return l -> min_index(x, y);
		return min(l -> min_index(x, m), r -> min_index(m + 1, y));
	}
	
} *root;

void dfs(int x, int h){
	fvisit[x] = (int)euler.size();
	height[x] = h;
	euler.push_back(x);
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++){
		if (fvisit[*it] != -1) continue;
		dfs(*it, h + 1);
		euler.push_back(x);
	}
}

int lca(int x, int y){
	if (fvisit[x] > fvisit[y]) swap(x, y);
	return euler[(root -> min_index(fvisit[x], fvisit[y])).second];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(fvisit, -1, sizeof(fvisit));
	cin >> n >> q;
	REP(i, 0, n - 1){
		cin >> a >> b;
		adjList[b].push_back(a);
		adjList[a].push_back(b);
	}
	
	dfs(0, 0);
	
	root = new node(0, 2*n);
	REP(i, 0, (int)euler.size()){
		root -> update(i, height[euler[i]]);
	}
	
	REP(i, 0, q){
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
	
}
