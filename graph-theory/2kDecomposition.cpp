int twok[MAXN][LOGN]; // twok[node][k] stores the (2^k)th parent of node
int d[MAXN];

vector<int> adjList[MAXN];

//Assign a parent-node relationship
void assignParent(int node, int parent){
    twok[node][0] = parent;
	REP(i, 1, LOGN){
        if (twok[node][i-1] == -1) break;
        else twok[node][i] = twok[twok[node][i-1]][i-1];
    }
}

//Assign a node-node relationship from the same parent
//Copies the twok decomposition
void assignNode(int node, int node2){
    REP(i, 0, LOGN) twok[node][i] = twok[node2][i];
}

//Returns the counterth parent of node
int findParent(int node, int c){
    if (c == 0) return node;
    for (int i = LOGN - 1; i >= 0; i--){
        if (twok[node][i] == -1) continue;
        if ((1 << i) > c) continue;
        return findParent(twok[node][i], c - (1 << i));
    }
}

//Assigns height of each node and calculates the 2k decomp
void dfs(int x){
	VREP(it, adjList[x]){
		if (d[*it] != -1) continue;
		d[*it] = 1 + d[x];
		assignParent(*it, x);
		dfs(*it);
	}
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x,y);
    if (d[x] > d[y]) {
        int diff = d[x] - d[y];
        REP(i, 0, LOGN) if (diff & (1 << i)) x = twok[x][i];
    }
    if (x == y) return x;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (twok[x][i] != twok[y][i]) {
            x = twok[x][i]; y = twok[y][i];
        }
    }
    return twok[x][0];
}


int main(){
	
	memset(twok, -1, sizeof(twok));
	memset(d, -1, sizeof(d));

	int root = 0;
	d[root] = 0;
	dfs(root);
	
	cout << lca(a, b) << endl;
}

/*
5 4
0 1
1 2
1 3
0 4
0 4
2 3
2 1
4 3
*/
//Should give output of 0, 1, 1, 0

