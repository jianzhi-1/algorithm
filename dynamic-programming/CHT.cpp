struct CHT{
	
	deque<pd> v;
	
	double get(ld x) {
		while (sz(v) >= 2) {
			ld a = v[0].fi*x + v[0].se;
			ld b = v[1].fi*x + v[1].se;
            //flip for max
			if (a <= b) break;
			v.pop_front();
		}
		return v[0].fi*x + v[0].se;
	}
	
	void add(pd x) {
		while (sz(v) >= 2) {
			pd y = v[sz(v) - 1];
			pd z = v[sz(v) - 2];
			if ((x.se-y.se)*(z.fi-y.fi) >= (y.fi-x.fi)*(y.se-z.se)) break;
			v.pop_back();
		}
		v.PB(x);
	}
	
	void clear(){ v.clear(); }
	
};

int main(){
    CHT d;
    d.add(MP(m, c));
    cout << d.get(x); << endl;
    d.clear();
}
