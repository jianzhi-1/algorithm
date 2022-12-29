ll n, a[1000], x, y;

struct node{
	
	ll s, e, m, val;
	node *l, *r;
	node(ll _s, ll _e): s(_s), e(_e), m((_s + _e)/2), val(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
			val = (l -> val) + (r -> val);
		} else {
			val = a[s];
		}
	}
	
	//point update
	void update(int x, ll nv){
		if (s == e){
			val = nv;
			return;
		}
		if (x > m) r -> update(x, nv);
		if (x <= m) l -> update(x, nv);
		val = (l -> val) + (r -> val);
	}
	
	ll query(int x, int y){
		if (s == x && e == y) return val;
		if (x > m) return r -> query(x, y);
		if (y <= m) return l -> query(x, y);
		return l -> query(x, m) + r -> query(m + 1, y);		
	}
	
} *root;

int main(){
    root = new node(0, n - 1);
    cout << root -> query(0, n - 1) << endl;
}
