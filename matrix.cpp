#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
#define ll long long

int n;
ll mod = 1e9 + 9;

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

matrix expo(matrix a, int n){

	if (n == 1) return a;
	matrix half = expo(a, n/2);
	half = half*half;
	if (n % 2 == 1) half = half*a;
	return half;
}

int main(){
	scanf("%d", &n);
	if (n == 0){
		printf("%d\n", 0);
		return 0;
	}
	
	ll arr[50][50];
	arr[0][0] = 1;
	arr[0][1] = 1;
	arr[1][0] = 1;
	arr[1][1] = 0;
	
	matrix fib = matrix(2, arr);
	
	matrix ans = expo(fib, n);

	printf("%lld\n", ans.m[1][0]);
	
}
