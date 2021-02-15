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

typedef int ftype;
typedef complex<ftype> point;
#define x real
#define y imag

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	complex<double> c (4, 2);
	cout << "Real part of c is " << c.x() << endl;				
	cout << "Imaginary part of c is " << c.y() << endl;			
	cout << "Modulus of c is " << abs(c) << endl;
	cout << "Normal of c is " << norm(c) << endl;	
	cout << "Argument of c is " << arg(c) << endl;			
	if (c == complex<double>(4, 2)) cout << "Same" << endl;
	cout << "Conjugate of c is " << conj(c) << endl;
	
	cout << "Polar " << polar(2.0, 3.141592) << endl;
	
}
