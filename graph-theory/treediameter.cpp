#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define VREP(it, v) for (vector<long long>::iterator it = v.begin(); it != v.end(); it++)
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
const ll MAXINT = 505;
vi adjList[MAXINT];
ll n, a, b;
ll dist[MAXINT];

void dfs(int x){
	VREP(it, adjList[x]){
		if (dist[*it] != -1) continue;
		dist[*it] = dist[x] + 1;
		dfs(*it);
	}
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	REP(i, 0, n - 1){
		cin >> a >> b;
		adjList[a].PB(b);
		adjList[b].PB(a);
	}
	memset(dist, -1, sizeof(dist));
	
	//root at a random node
	dist[0] = 0;
	dfs(0);
	
	int u = 0;
	REP(i, 0, n){
		u = (dist[i] > dist[u]) ? i : u;
	}
	memset(dist, -1, sizeof(dist));
	dist[u] = 0;
	dfs(u);
	int w = u;
	REP(i, 0, n){
		w = (dist[i] > dist[w]) ? i : w;
	}
	cout << "The two ends are: " << u << " " << w << "\n";
	cout << "The length of the diameter is: " << dist[w] << "\n";
}

/*
12
0 1
0 2
0 3
1 4
1 5
3 6
3 7
3 8
4 9
4 10
6 11
*/
