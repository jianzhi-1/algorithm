const int MAX_N = 200005;

struct two_edge_connected_decomposition {
    vector<vector<int> > v;
    vector<vector<int> > _v; // decomposition graph
    vector<pi> edge_list;
    set<pi> bridges;
    set<int> s[MAX_N];
    int group[MAX_N];
    int dfs_low[MAX_N];
    int dfs_num[MAX_N];
    int c = 0; // dfs count
    int gc = 0; // group count
    int n = 0;

    two_edge_connected_decomposition(int _n){
        n = _n;
        c = gc = 0;
        v.resize(n);
        _v.resize(n);
        REP(i, 0, n) v[i].clear();
        REP(i, 0, n) _v[i].clear();
        REP(i, 0, n) s[i].clear();
        REP(i, 0, n) dfs_low[i] = dfs_num[i] = group[i] = -1;
        edge_list.clear();
        bridges.clear();
    }

    void clear(int _n){
        n = _n;
        c = gc = 0;
        v.resize(n);
        _v.resize(n);
        REP(i, 0, n) v[i].clear();
        REP(i, 0, n) _v[i].clear();
        REP(i, 0, n) s[i].clear();
        REP(i, 0, n) dfs_low[i] = dfs_num[i] = group[i] = -1;
        edge_list.clear();
        bridges.clear();
    }

    void dfs(int x, int par){
        dfs_num[x] = dfs_low[x] = c++;
        VREP(it, v[x]){
            if (*it == par) continue;
            if (dfs_num[*it] != -1){
                dfs_low[x] = min(dfs_low[x], dfs_num[*it]);
                continue;
            }
            dfs(*it, x);
            dfs_low[x] = min(dfs_low[x], dfs_low[*it]);
            if (dfs_low[*it] > dfs_num[x]){
                bridges.insert({x, *it});
            }
        }
    }

    void dfs_group(int x, int par, int group_no){ // used by calc
        s[group_no].insert(x);
        group[x] = group_no;
        VREP(it, _v[x]){
            if (*it == par) continue;
            if (s[group_no].find(*it) != s[group_no].end()) continue;
            dfs_group(*it, x, group_no);
        }
    }

    void calc(){ // forms decomposition graph and dfs on this graph to get group numbers
        VREP(it, edge_list){
            if (bridges.find(*it) != bridges.end() || bridges.find({it -> second, it -> first}) != bridges.end()) continue;
            _v[it -> first].PB(it -> second);
            _v[it -> second].PB(it -> first);
        }
        REP(i, 0, n){
            if (group[i] == -1) dfs_group(i, -1, gc++);
        }
    }

    void print(){
        REP(i, 0, n){
            cout << "node " << i << ": group = " << group[i] << " dfs_num = " << dfs_num[i] << " , dfs_low = " << dfs_low[i] << endl;
        }
        cout << "bridges:" << endl;
        VREP(it, bridges){
            cout << it -> first << " " << it -> second << endl;
        }
    }
};

int main(){
    two_edge_connected_decomposition graph(0);
    graph.clear(n);
    graph.dfs(0, 1);
    graph.calc();
}
