struct AugPath {
    int A, B;   // size of left, right groups
    vector<vector<int> > G; // size A
    vector<bool> visited;   // size A
    vector<int> P;          // size B
    
    AugPath(int _A, int _B): A(_A), B(_B), G(_A), P(_B, -1){}

    void addEdge(int a, int b){    
        // just need edges from A to B; a from left, b from right
        G[a].PB(b);
    }

    bool aug(ll x) {
        if (visited[x]) return false;
        visited[x] = true;
        VREP(it, G[x]){
            if (P[*it] == -1 || aug(P[*it])){
                P[*it] = x;
                return true;
            }
        }
        return false;
    }
    
    int mcbm(){
        int matchings = 0;
        REP(i, 0, A){
            visited.resize(A, 0);
            matchings += aug(i);
            visited.clear();
        }
        return matchings;
    }

    vector<pi> getMatchings() {
        vector<pi> matchings;
        REP(i, 0, B) if (P[i] != -1) matchings.emplace_back(P[i], i);
        return matchings;
    }
};


int main(){
    AugPath graph = AugPath(n, n);
    REP(i, 0, m) graph.addEdge(u, v)
    cout << graph.mcbm() << endl;
}
