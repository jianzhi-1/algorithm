//dot product of (m, c).(x, 1)
ll f(pi a, pi x){return a.F*x.F + a.S*x.S;}

struct node{
	ll s, e, m;
	pi curw;
	bool assigned;
	node *l, *r;
	node (ll _s, ll _e): s(_s), e(_e), l(NULL), assigned(false), r(NULL), curw(make_pair(-1, -1)){
		m = (s + e)/2;
		if (m - s > e - m) m--;
	}
	
	// Add line of y = m(i)*x + c(i); nw = MP(m(i), c(i))
	void add_line(pi nw){
		if (!assigned){
			assigned = true;
			curw = nw;
			return;
		}
		
		bool lef = f(nw, MP(s, 1)) > f(curw, MP(s, 1)); // FLIP SIGNS FOR MIN
		bool mid = f(nw, MP(m + 1, 1)) > f(curw, MP(m + 1, 1)); // FLIP SIGNS FOR MIN
		if (m > e || s > m) return;
		if (mid) swap(curw, nw);
		if (e - s == 0) return;
		if (lef != mid){
			if (l == NULL) l = new node(s, m);
			l -> add_line(nw);
		} else {
			if (r == NULL) r = new node(m + 1, e);
			r -> add_line(nw);
		}
	}
	
	ll solve(ll x){
		if (l == NULL && r == NULL) return f(curw, MP(x, 1));
		if (x <= m){
			if (l == NULL) return f(curw, MP(x, 1));
			return max(f(curw, MP(x, (ll)1)), l -> solve(x)); // CHANGE MAX TO MIN
		} else {
			if (r == NULL) return f(curw, MP(x, 1));
			return max(f(curw, MP(x, (ll)1)), r -> solve(x)); // CHANGE MAX TO MIN
		}
	}
} *root;

int main(){

	//create with ALL possible query points
	root = new node(-10000000000001, 10000000000001);
	root -> add_line(MP(0, 0)); // CHANGE BASE CASE IF NECESSARY

	REP(i, 1, n + 1){
		dp[i] = cc(i) + root -> solve(a(i)); // get answer for dp(i) = cc(i) + max_{j < i}{m(j)*a(i) + c(j)}
		root -> add_line(MP(m(i), c(i))); // add line for this iteration y = m(i)*x + c(i)
	}
	
}
