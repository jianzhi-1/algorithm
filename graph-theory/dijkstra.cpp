const int N = 200005;
vector<pi> adjList[N];
ll dist[N];
priority_queue<pi, vector<pi>, greater<pi> > pq;

int main(){
	memset(dist, -1, sizeof(dist));
	dist[S] = 0;
	pq.push(MP(0, S));
	while (!pq.empty()) {
		pi cur = pq.top();
		pq.pop();
		ll x = cur.second, d = cur.first;
		if (d > dist[x]) continue;
		VREP(it, adjList[x]){
		ll nx = it->first, nd = d+it->second;
		if (dist[nx] != -1 && dist[nx] <= nd) continue;
		dist[n	x] = nd;
		pq.push(MP(nd, nx));
		}
	}
}
