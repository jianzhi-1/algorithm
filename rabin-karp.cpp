#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
string s, t;
ll p = 11;
ll mod = 1e9 + 9;
vector<int> v;
ll pp[1505];
ll inv;

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
		val += (s[i] - 'a' + 1)*pp[i];
		val %= mod;
	}
	return val;
}

int rabin_karp(string a, string b){
	//return the number of occurences
	int at = a.length(), bt = b.length();
	ll ahash = hashing(a);
	string str = "";
	for (int i = 0; i < at; i++){
		str = str + b[i];
	}
	ll cur = hashing(str);
	int counter = 0;
	if (cur == ahash){
		counter++;
		v.push_back(0);
	}
	for (int i = at; i < bt; i++){
		cur += (b[i] - 'a' + 1)*pp[at];
		cur %= mod;
		cur -= (b[i - at] - 'a' + 1);
		cur %= mod;
		cur *= inv;
		cur %= mod;
		if (cur == ahash){
			counter++;
			v.push_back(i - at + 1);
		}
		counter += (cur == ahash);
	}
	return counter;
}

int main(){
	
	pp[0] = 1;
	for (int i = 1; i < 1505; i++){
		pp[i] = pp[i - 1]*p;
		pp[i] %= mod;
	}
	inv = power(p, mod - 1);
	
	cin >> s >> t;
	printf("%d\n", rabin_karp(s, t));
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
		if (it != v.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
}
