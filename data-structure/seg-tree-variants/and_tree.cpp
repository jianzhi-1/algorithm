struct node{
	
	ll s, e, m;
	bool val;
	node *l, *r;
	node (ll _s, ll _e): s(_s), e(_e), m((_s + _e)/2), val(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
			val = (l -> val)&(r -> val);
		} else {
			val = a[s];
		}
	}
	
	bool query(int x, int y){
		if (y < x) return false;
		if (s == x && e == y) return val;
		if (x > m) return r -> query(x, y);
		if (y <= m) return l -> query(x, y);
		return (l -> query(x, m)) & (r -> query(m + 1, y));		
	}
	
} *root;
