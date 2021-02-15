#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;

//toposort
//edges come from vertices on the left to vertices on the right

int n, m, a, b;
bool visited[1005];
vector<int> adjList[1005];
vector<int> topo;

void dfs(int x){
	visited[x] = true;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++){
		if (visited[*it]) continue;
		dfs(*it);
	}
	topo.push_back(x);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++){
		scanf("%d%d", &a, &b);
		adjList[a].push_back(b);
	}
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++){
		if (!visited[i]) dfs(i);
	}
	
	reverse(topo.begin(), topo.end());
	
	for (vector<int>::iterator it = topo.begin(); it != topo.end(); it++){
		if (it != topo.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
	
}
