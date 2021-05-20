//WARNING: multiple edges unaccounted for

vector<int> adjList[400005];
pi dist[400005]; //MP(preorder, highest preorder that can be reached from vertex)

int c = 0; //preorder idx
void dfs(int x, int par){
	dist[x].first = dist[x].second = c;
	c++;
	VREP(it, adjList[x]){
		if (*it == par) continue;
		if (dist[*it].first != -1){
			//backward edge
			dist[x].second = min(dist[x].second, dist[*it].first);
			continue;
		}
		dfs(*it, x);
		dist[x].second = min(dist[x].second, dist[*it].second);
	}
}

int main(){
	REP(i, 0, n) dist[i] = MP(-1, -1);
	dfs(0, -1);
}
