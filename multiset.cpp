#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
multiset<int> ms;

void print_ms(){
	printf("Multiset contains:\n");
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++){
		if (it != ms.begin()) printf(" ");
		printf("%d", *it);
	}
	printf("\n");
}

int main(){
	
	ms.insert(10);
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(30);
	ms.insert(40);
	print_ms();
	
	multiset<int>::iterator it = ms.lower_bound(30);
	ms.erase(it);
	print_ms();
	
	ms.erase(10);
	print_ms();
	
}
