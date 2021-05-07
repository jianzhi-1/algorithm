const int MAX_N = 100005;

set<int> adjList[MAX_N]; //original adjList
set<int> temp[MAX_N]; //temporary adjList to erase edges

int crank[MAX_N]; //rank of centroids, crank = 0 is the root
vector<int> cc[MAX_N]; //centroid tree O(N)
vector<int> cr[MAX_N]; //centroid rank vector, cr[0] stores root, cr[1] stores centroid dist 1 to root
map<int, ll> ma[MAX_N]; //map for centroid decomp O(NlogN)

int p[MAX_N]; //stores the centroid parent
int sts[MAX_N]; //stores subtree size

int dfs(int x, int par){
	//dfs to obtain subtree size
	int ans = 1; 
	VREP(it, temp[x]){
		if (*it == par) continue;
		ans += dfs(*it, x);
	}
	return sts[x] = ans;
}

int centroid(int x){
	int t = dfs(x, -1), cur = x, par = -1;
	while (true){
		pair<int,int> m = MP(-1, -1); //<max subtree size, node to move to>
		bool isCentroid = true;
		VREP(it, temp[cur]){
			if (*it == par) continue;
			if (2*sts[*it] > t) isCentroid = false;
			m = max(m, MP(sts[*it], *it));
		}
		if (isCentroid) return cur;
		par = cur; cur = m.second;
	}
}

void centroid_decomp(int x, int pc){
	int c = centroid(x);
	p[c] = pc;
	
	if (pc != -1){
		cc[pc].PB(c); cc[c].PB(pc);
		crank[c] = crank[pc] + 1;	
	} else crank[c] = 0;
	cr[crank[c]].PB(c);	

	VREP(it, temp[c]){
		temp[*it].erase(c);
		centroid_decomp(*it, c);
	}
	temp[c].clear();
}

void dfs2(int x, int par, int v, int cn){ 
	//x, p[x] or -1, value (in this case the distance), centroid --- dfs to obtain half path value
	VREP(it, adjList[x]){
		if (crank[*it] <= crank[cn] || (*it)==par) continue;
		ma[cn][*it] = v; //store half path value here
		dfs2(*it, x, v + 1, cn);
	}
}

int main(){

	REP(i, 0, n - 1){
		adjList[aa - 1].insert(bb - 1); adjList[bb - 1].insert(aa - 1);
		temp[aa - 1].insert(bb - 1); temp[bb - 1].insert(aa - 1);
	}
	memset(crank, -1, sizeof(crank));
	centroid_decomp(0, -1);
	
	REP(i, 0, n){
		if (sz(cr[i]) == 0) break; //no more
		VREP(it, cr[i]) dfs2(*it, -1, 1, *it); //start with distance of 0
	}
	
}
