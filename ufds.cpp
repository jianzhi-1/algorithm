#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, a, b;
string command;
int p[1005], r[1005];

int parent(int x){
	if (p[x] == x) return x;
	return p[x] = parent(p[x]);
}

void merge_set(int a, int b){
	if (a == b)
	if (r[parent(a)] < r[parent(b)]){
		merge_set(b, a);
	}
	p[parent(b)] = parent(a); //a will be the bigger rank
	if (r[parent(b)] == r[parent(a)]){
		r[parent(a)]++;
	}
}

int main(){
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		p[i] = i;
		r[i] = 0;
	}
	
	while (true){
		cin >> command;
		if (command == "merge"){
			scanf("%d%d", &a, &b);
			merge_set(a, b);
		} else if (command == "parent"){
			scanf("%d", &a);
			printf("%d\n", parent(a));
		}
	}
	
	
}
