struct pt {
    int x, y;
    pt(int _x, int _y): x(_x), y(_y){}
};

bool comparePt(pt a, pt b){
	return MP(a.x, a.y) < MP(b.x, b.y);
}

int orientation(pt a, pt b, pt c) {
    int v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    if (a.size() == 1) return;

    sort(a.begin(), a.end(), comparePt);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.PB(p1); down.PB(p1);
    REP(i, 1, a.size()){
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.PB(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.PB(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    REP(i, 0, up.size()) a.PB(up[i]);
    for (int i = down.size() - 2; i > 0; i--) a.PB(down[i]);
}

set<pi> s; // removes all repeated points

int n, xx, yy;
vector<pt> v;

int main(){
    cin >> n;
    v.clear(); s.clear();
    
    // setting up the points
    REP(i, 0, n){
        cin >> xx >> yy;
        if (s.find(MP(xx, yy)) != s.end()) continue;
        s.insert(MP(xx, yy));
        v.PB(pt(xx, yy));
    }
    
    convex_hull(v, false);
    reverse(v.begin(), v.end()); // in counter clockwise order
    cout << v.size() << endl;
    VREP(it, v) cout << it -> x << " " << it -> y << endl;
}


