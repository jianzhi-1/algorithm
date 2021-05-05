pi idx[100005];
int c = 0;

void dfs(int x, int par){
	idx[x].first = c;
	VREP(it, v[x]){
		if (*it == par) continue;
		c++;
		dfs(*it, x);
	}
	idx[x].second = c;
}

struct node{
	
	int s, e, m;
	ll val;
	pair<bool, ll> lazy;
	node *l, *r;
	
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), val(0), lazy(MP(0, 0)){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
			val = (l -> val) + (r -> val);
		} else {
			val = a[s];
		}
	}
	
	ll value(){
		if (s == e){
			if (lazy.first){
				val += lazy.second;
				lazy.first = 0;
			}
			return val;
		}
		if (lazy.first){
			l -> lazy = MP(1, lazy.second);
			r -> lazy = MP(1, lazy.second);
			lazy.first = 0;
			return val += lazy.second*(e - s + 1);
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
	
	bool isAncestor(int p, int x){
		//is p an ancestor of x
		return (idx[p].first <= x && idx[p].second >= x);
	}
	
} *root;



int main(){
	dfs(0, -1);
	root = new node(0, c);
}
