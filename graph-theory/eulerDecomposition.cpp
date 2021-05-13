const int MAX_N = 500005;

int n, a, b, q;

vector<int> adjList[MAX_N];
vector<int> euler; //the size of this list is 2*E (= O(N) for trees)
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
	
	//returns <min, index that points to the minimum element (in the euler vector)>, euler[index] gives the LCA
	pi min_index(int x, int y){
		if (s == x && e == y) return mini;
		if (x > m) return r -> min_index(x, y);
		if (y <= m) return l -> min_index(x, y);
		return min(l -> min_index(x, m), r -> min_index(m + 1, y));
	}
	
} *root;

void dfs(int x, int h){
	fvisit[x] = sz(euler);
	height[x] = h;
	euler.PB(x);
	VREP(it, adjList[x]){
		if (fvisit[*it] != -1) continue;
		dfs(*it, h + 1);
		euler.PB(x);
	}
}

int lca(int x, int y){
	if (fvisit[x] > fvisit[y]) swap(x, y);
	return euler[(root -> min_index(fvisit[x], fvisit[y])).second];
}

int main(){

	memset(fvisit, -1, sizeof(fvisit));

	dfs(0, 0);
	
	root = new node(0, 2*n);
	REP(i, 0, sz(euler)) root -> update(i, height[euler[i]]);
	
	REP(i, 0, q){
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
	
}
