#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;
#define ll long long
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define LB lower_bound
#define UB upper_bound
#define sz(a) int((a).size())
#define REP(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define REPD(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define VREP(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define BIT(bs, i) (!!(bs&(1 << i)))
#define SQR(x) ((x)*(x))
#define LSONE(x) ((x)&(-x))
#define TRACE(x) cout << #x << " = " << x << endl
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ld, ld> pd;

const ll MOD = 1000000009;
const double PI = acos(-1);

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

//cout.flush()
//cout << fixed << setprecision(9) << x << endl;
