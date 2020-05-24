#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define VREP(it, v) for (vector<long long>::iterator it = v.begin(); it != v.end(); it++)
const ll MAXN = 1000005;
const ll LOGN = 21;

typedef pair<ll,ll> pi;
typedef vector<ll> vi;

int twok[MAXN][LOGN];
int d[MAXN];

vi adjList[MAXN];

int n, q, a, b;

//Assign a parent-node relationship
void assignparent(int node, int parent){
    twok[node][0] = parent;
    for (int i = 1; i < LOGN; i++) {
        if (twok[node][i-1] == -1) break;
        else twok[node][i] = twok[twok[node][i-1]][i-1];
    }
}

//Assign a node-node relationship from the same parent
//Copies the twok decomposition
void assignnode(int node, int node2){
    for (int i = 0; i < LOGN; i++){
        twok[node][i] = twok[node2][i];
    }
}

//Returns the counterth parent of node
int findparent(int node, int counter){
    if (counter == 0) return node;
    for (int i = LOGN - 1; i >= 0; i--){
        if (twok[node][i] == -1) continue;
        if ((1 << i) > counter) continue;
        return findparent(twok[node][i], counter - (1 << i));
    }
}

//Assigns height of each node and calculates the 2k decomp
void dfs(int x){
	VREP(it, adjList[x]){
		if (d[*it] != -1) continue;
		d[*it] = 1 + d[x];
		assignparent(*it, x);
		dfs(*it);
	}
}

int lca(int x, int y) {
    if (d[x] < d[y]) swap(x,y);
    if (d[x] > d[y]) {
        int diff = d[x] - d[y];
        for (int i = 0; i < LOGN; i++){
            if (diff & (1 << i)) x = twok[x][i];
        }
    }
    if (x == y) return x;
    for (int i = LOGN - 1; i >= 0; i--) {
        if (twok[x][i] != twok[y][i]) {
            x = twok[x][i];
            y = twok[y][i];
        }
    }

    return twok[x][0];
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	REP(i, 0, n - 1){
		cin >> a >> b;
		adjList[a].PB(b);
		adjList[b].PB(a);
	}
	
	int root = 0;
	
	memset(twok, -1, sizeof(twok));
	memset(d, -1, sizeof(d));
	d[root] = 0;
	
	dfs(root);
	
	REP(i, 0, q){
		cin >> a >> b;
		cout << "The LCA is : " << lca(a, b) << endl;
	}
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

