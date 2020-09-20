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
typedef pair<ll,ll> pi;
typedef vector<ll> vi;

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

//FENWICK ARRAY CANNOT BE 0-INDEXED!
//ADD ONE TO INDEX IF NECESSARY

const ll MAX_N = 300005;

ll n, q, nq, x, y;
ll fw[MAX_N], arr[MAX_N];

void update(ll x, ll v){
	for (; x < MAX_N; x+=x&(-x)) fw[x] += v;
}

ll sum(ll x){
	ll res = 0;
	for (; x; x-=x&(-x)) res += fw[x];
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	REP(i, 0, n){
		cin >> arr[i];
		update(i + 1, arr[i]);
	}
	REP(i, 0, q){
		cin >> nq >> x >> y;
		if (nq == 1) update(x + 1, y);
		else cout << sum(y + 1) - sum(x) << endl;
	}
}

//cout.flush()
//cout << fixed << setprecision(9) << x << endl;
