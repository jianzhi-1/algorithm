ll n, arr[1000], x, y;
string command;

struct node{
	ll s, e, m, total;
	node *l, *r;
	node (ll _s, ll _e): s(_s), e(_e), m((_s + _e)/2), total(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	//point update
	void update(ll x, ll nv){
		if (s == e){
			total = nv;
			return;
		}
		if (x > m) r -> update(x, nv);
		if (x <= m) l -> update(x, nv);
		total = l -> total + r -> total;
	}
	
	ll range_total(ll x, ll y){
		if (s == x && e == y) return total;
		if (x > m) return r -> range_total(x, y);
		if (y <= m) return l -> range_total(x, y);
		return l -> range_total(x, m) + r -> range_total(m + 1, y);		
	}
	
} *root;

int main(){
    root = new node(0, n - 1);
    REP(i, 0, n) root -> update(i, arr[i]);
    cout << root -> range_total(x, y) << endl;
}
