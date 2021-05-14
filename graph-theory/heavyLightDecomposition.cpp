int n, q, t, aa, bb;
vector<pair<int, pi> > adjList[10005]; //size of subtree, node, weight
vector<vector<int> > heavyChain; //chain of nodes
pair<int, pi> v[10005]; //<position of the node on segment tree, which chain it belongs to, what position in the chain>
 
int d[10005], p[10005]; //distance of node from the root //parent of node[x]. parent of root is -1 
map<pi, int> ma; //map edge<node1, node2> to edge index
map<int, int> mma; //map edge index to node
map<int, int> minv; //map node to edge index
int w[10005], inv[10005]; //edge weight of index
int c = 0;
int cc = 0;
 
struct node{
	
	int s, e, m;
    ll val; //in this case it is the edge value
	node *l, *r;
	
	//construct the node for the cccth heavy chain
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), val(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
			val = max((l -> val), (r -> val));
		} else {
			if (inv[s] == 0) val = 0; //root node
			else val = w[minv[inv[s]]]; //map position on segment tree to node
		}
	}
	
	//point update
	void update(int x, ll nv){
		if (s == e){
			val = nv;
			return;
		}
		if (x > m) r -> update(x, nv);
		if (x <= m) l -> update(x, nv);
		val = max((l -> val), (r -> val));
	}
	
	int query(int x, int y){
		if (s == x && e == y) return val;
		if (x > m) return r -> query(x, y);
		if (y <= m) return l -> query(x, y);
		return max(l -> query(x, m), r -> query(m + 1, y));		
	}
	
};
 
node* root;

//checks if node x and y are in the same heavy path, i.e. the same chain
bool isSameHeavyPath(int x, int y){ return v[x].second.first == v[y].second.first;}
 
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

//x is ancestor of y
int query(int x, int y){
	
	int ans = 0;
	while (!isSameHeavyPath(x, y)){
		int heady = heavyChain[v[y].second.first][0];
		if (y == heady){ //if y is first in its chain
			ans = max(ans, w[minv[y]]);
			y = p[y];
		} else { //shift y to head of chain
			ans = max(ans, root -> query(v[heady].first, v[y].first));
			y = p[heady];
		}
	}
	if (y == x) return ans;
	return max(ans, root -> query(v[x].first + 1, v[y].first));
	
}
 
int queryGen(int x, int y){
	//get the max edges from x to y
	int l = lca(x, y);
	return max(query(l, x), query(l, y));
}

//dfs to add nodes to chains
void chaindfs(int x){
	v[x] = MP(cc, MP(c, sz(heavyChain[c])));
	inv[cc] = x;
	heavyChain[c].PB(x);
	cc++;
	REP(i, 0, sz(adjList[x])){
		if (d[adjList[x][i].second.first] < d[x]) continue;
		if (i != 0) c++;
		mma[ma[MP(x, adjList[x][i].second.first)]] = adjList[x][i].second.first;
		minv[adjList[x][i].second.first] = ma[MP(x, adjList[x][i].second.first)];
		chaindfs(adjList[x][i].second.first);
	}
}
 
//dfs to set up d and p
int dfs(int x){
	ll cursz = 1;
	REP(i, 0, sz(adjList[x])){
		if (d[adjList[x][i].second.first] != -1) continue;
		d[adjList[x][i].second.first] = d[x] + 1;
		p[adjList[x][i].second.first] = x;
		adjList[x][i].first = dfs(adjList[x][i].second.first);
		cursz += adjList[x][i].first;
	}
	
	sort(adjList[x].begin(), adjList[x].end());
	reverse(adjList[x].begin(), adjList[x].end());
	return cursz;
}
 
int main(){

    REP(i, 0, n - 1){
        cin >> aa >> bb >> w[i];
        aa--; bb--;
        ma[MP(aa, bb)] = i;
        ma[MP(bb, aa)] = i;
        adjList[aa].PB(MP(-1, MP(bb, w[i])));
        adjList[bb].PB(MP(-1, MP(aa, w[i])));
    }
    heavyChain.resize(n); //max n heavy chains
    memset(d, -1, sizeof(d));
    d[0] = 0;
    p[0] = -1;
    dfs(0);
    chaindfs(0);
    root = new node(0, n - 1);
    
    //handle update and query
    root -> update(v[mma[aa]].first, bb);
    cout << queryGen(aa, bb) << endl;
		
}
