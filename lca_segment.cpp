#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,int> pi;

int n, a, b;
//assumes a tree
vector<int> adjList[1005];
vector<int> euler; //the size of this list is 2*E (= O(N) for trees)
//hence segment tree must be declared as at least 2*n
int fvisit[1005];
int height[1005]; 

struct node{
	int s, e, m, mini, fi;
	node *l, *r;
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), mini(0), fi(_s){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	//point update
	void update(int x, int nv){
		
		if (s == e){
			mini = nv;
			fi = s;
			return;
		}
		if (x > m){
			r -> update(x, nv);
		}
		if (x <= m){
			l -> update(x, nv);
		}
		if (l -> mini > r -> mini){
			fi = r -> fi;
		} else {
			fi = l -> fi;
		}
		mini = min(l -> mini, r -> mini);
	}
	
	//returns <min, index that points to the minimum element (in the euler vector)>
	//euler[index] gives the LCA
	pi min_index(int x, int y){
		if (s == x && e == y) return make_pair(mini, fi);
		if (x > m) return r -> min_index(x, y);
		if (y <= m) return l -> min_index(x, y);
		return min(l -> min_index(x, m), r -> min_index(m + 1, y));
	}
	
} *root;

void dfs(int x, int h){
	fvisit[x] = euler.size();
	height[x] = h;
	euler.push_back(x);
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); it++){
		if (fvisit[*it] != -1) continue;
		dfs(*it, h + 1);
		euler.push_back(x);
	}
}

int lca(int x, int y){
	if (fvisit[x] > fvisit[y]) return lca(y, x);
	return euler[(root -> min_index(fvisit[x], fvisit[y])).second];
	
}

int main(){
	
	memset(fvisit, -1, sizeof(fvisit));
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d", &a, &b);
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	
	dfs(0, 0);
	
	root = new node(0, 2*n);
	for (int i = 0; i < euler.size(); i++){
		root -> update(i, height[euler[i]]);
	}
	
	
	while (true){
		scanf("%d%d", &a, &b);
		printf("LCA of %d and %d: %d\n", a, b, lca(a, b));
	}
	
}
