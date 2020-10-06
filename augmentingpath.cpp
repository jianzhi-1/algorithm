struct AugPath {
    ll A, B;   //size of left, right groups
    vector<vector<ll> > G; //size A
    vector<bool> visited;   //size A
    vector<ll> P;          //size B
    
    AugPath(ll _A, ll _B): A(_A), B(_B), G(_A), P(_B, -1){}
    
    void AddEdge(ll a, ll b){    //a from left, b from right
        G[a].push_back(b);
    }
    
    bool Aug(ll x) {
        if (visited[x]) return 0;
        visited[x] = 1;
        VREP(it, G[x]){
            if (P[*it] == -1){
                P[*it] = x;
                return 1;
            }
        }
        VREP(it, G[x]){
            if (Aug(P[*it])){
                P[*it] = x;
                return 1;
            }
        }
        return 0;
    }
    
    ll MCBM(){
        ll matchings = 0;
        REP(i, 0, A){
            visited.resize(A, 0);
            matchings += Aug(i);
            visited.clear();
        }
        return matchings;
    }
    
    vector<pi> GetMatchings() {
        vector<pi> matchings;
        REP(i, 0, B) if (P[i] != -1) matchings.emplace_back(P[i], i);
        return matchings;
    }
    
};


int main(){
    AugPath graph(n, n);
    REP(i, 0, m) graph.AddEdge(u, v)
    cout << graph.MCBM() << endl;
}
