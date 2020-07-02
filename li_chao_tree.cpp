#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i < b; i++)
#define VREP(it, v) for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
#define INF 2000000000
typedef pair<ll,ll> pi;
typedef vector<ll> vi;

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

pair<pi, ll> arr[1000005];
ll n, dp[1000005];

//dot product of (m, c).(x, 1)
ll f(pi a, pi x){return a.F*x.F + a.S*x.S;}

//function to calculate the midpoint
//taking into account negative
ll mm(ll s, ll e){
	ll m = (s+e)/2;
	if (m - s > e - m) m--;
	return m;
}

//Li chao tree
struct node{
	int s, e, m;
	pi curw; //current function at this node
	bool assigned; //whether the current function has been assigned
	node *l, *r; //lazy creation
	node (int _s, int _e): s(_s), e(_e), m(mm(_s, _e)), l(NULL), assigned(false), r(NULL), curw(make_pair(-1, -1)){}
	
	//add_line of y = m*x + c
	//nw = (m, c)
	void add_line(pi nw){
		if (!assigned){
			assigned = true;
			curw = nw;
			return;
		}
		
		//flip signs for min
		bool lef = f(nw, MP(s, 1)) > f(curw, MP(s, 1));
		bool mid = f(nw, MP(m + 1, 1)) > f(curw, MP(m + 1, 1));
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
			return max(f(curw, MP(x, (ll)1)), l -> solve(x));
		} else {
			if (r == NULL) return f(curw, MP(x, 1));
			return max(f(curw, MP(x, (ll)1)), r -> solve(x));
		}
	}
} *root;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//create with all possible query points
	root = new node(-1000000001, 1000000001);
	cin >> n;
	REP(i, 0, n) cin >> arr[i].F.F >> arr[i].F.S >> arr[i].second;
	sort(arr, arr + n);

	root -> add_line(MP(0, 0));
	REP(i, 0, n){
		//add constants with i here
		dp[i] = (arr[i].F.F*arr[i].F.S - arr[i].S) + root -> solve(-arr[i].F.S);
		root -> add_line(MP(arr[i].F.F, dp[i]));
	}
	
	ll ans = 0;
	REP(i, 0, n) ans = max(ans, dp[i]);
	cout << ans << endl;
}
