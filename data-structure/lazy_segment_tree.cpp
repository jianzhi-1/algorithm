struct node{
	
	int s, e, m;
    ll val;
	pair<bool, ll> lazy;
	
	node *l, *r;
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), val(0), lazy(MP(0, 0)){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	ll value(){
		if (s == e){
			if (lazy.first){
				val = lazy.second;
				lazy.first = 0;
			}
			return val;
		}
		if (lazy.first){
			l -> lazy = MP(1, lazy.second);
			r -> lazy = MP(1, lazy.second);
			lazy.first = 0;
			return val = lazy.second*(e - s + 1);
		}
		return val;
	}
	
	void range_update(int x, int y, ll nv){
		
		if (lazy.first) val = value();
		
		if (s == x && e == y){
			lazy = MP(1, nv);
		} else {
			if (x > m) r -> range_update(x, y, nv);
			else if (y <= m) l -> range_update(x, y, nv);
			else l -> range_update(x, m, nv), r -> range_update(m + 1, y, nv);
			val = l -> value() + r -> value();
		}
	}
	
	ll query(int x, int y){
		value();
		if (s == x && e == y) return value();
		if (x > m) return r -> query(x, y);
		if (y <= m) return l -> query(x, y);
		return val = l -> query(x, m) + r -> query(m + 1, y);
	}
	
};
