#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
#define ll long long
ll mod = 1e9 + 9;
ll p = 11;
string s;
ll running_hash[50];
ll inv[50];

ll power(ll a, ll b){
	if (b == 0) return 1;
	if (b == 1) return a;
	ll half = power(a, b/2);
	half *= half;
	half %= mod;
	if (b % 2 == 1) half*=a;
	return half %= mod;
}

ll hashing(string s){
	//all must be in lowercase
	ll val = 0;
	for (int i = 0; i < s.length(); i++){
		val += (s[i] - 'a' + 1)*power(p, i);
		val %= mod;
		running_hash[i + 1] = val;
	}
	return val;
}

ll substr_hashing(string s, int i, int j){
	//inclusive s[i, ..., j]
	return (inv[i]*((running_hash[j + 1] - running_hash[i] + mod)%mod))%mod;
}

int main(){
	inv[1] = power(p, mod - 2);
	for (int i = 2; i < 50; i++){
		inv[i] = inv[i - 1]*inv[1];
		inv[i] %= mod;
	}
	cin >> s;
	cout << hashing(s) << endl;
}
