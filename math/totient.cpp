#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define ll long long
ll n;

ll totient(ll x){
	ll ans = x;
	if (x % 2 == 0){
		while (x % 2 == 0){
			x /= 2;
		}
		ans -= ans/2;		
	}

	for (ll i = 3; i*i <= x; i+=2){
		if (x % i == 0){
			while (x % i == 0){
				x /= i;
			}
			ans -= ans/i;			
		}
	}
	if (x > 1){
		ans -= ans/x;
	}
	return ans;
}

int main(){
	scanf("%lld", &n);
	printf("%lld\n", totient(n));
}
