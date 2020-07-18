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

ll n, mod = 1e9 + 7;

struct matrix {
	ll siz = 0;
	ll m[50][50];
	matrix(int n, ll arr[][50]){
		//assumes square array for exponentiation
		if (n >= 50){
			printf("Matrix too large. Change size limit.\n");
			return;
		}
		siz = n;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				m[i][j] = arr[i][j];
			}
		}
	}
	
	matrix clone(){
		return matrix(siz, m);
	}
	
	matrix operator* (matrix b){

		matrix a = (*this).clone();
		if (a.siz != b.siz){
			printf("Not square matrix\n");
		}
		matrix res = b;
		for (int i = 0; i < a.siz; i++){
			for (int j = 0; j < b.siz; j++){
				res.m[i][j] = 0;
				for (int k = 0; k < a.siz; k++){
					res.m[i][j] += a.m[i][k]*b.m[k][j];
					res.m[i][j] %= mod;
				}
			}
		}
		
		return res;
	}
};

matrix expo(matrix a, ll n){
	if (n == 1) return a;
	matrix half = expo(a, n/2);
	half = half*half;
	if (n % 2 == 1) half = half*a;
	return half;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	ll arr[50][50];
	arr[0][0] = 19;
	arr[0][1] = 7;
	arr[1][0] = 6;
	arr[1][1] = 20;
	
	matrix fib = matrix(2, arr);
	
	matrix ans = expo(fib, n);
	cout << ans.m[0][0] << endl;
	
}

//cout.flush()
