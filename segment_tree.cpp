#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, arr[1000], x, y;
string command;

struct node{
	int s, e, m, maxi, mini, total;
	node *l, *r;
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), maxi(0), mini(0), total(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	//point update
	void update(int x, int nv){
		
		if (s == e){
			maxi = mini = total = nv;
			return;
		}
		if (x > m){
			r -> update(x, nv);
		}
		if (x <= m){
			l -> update(x, nv);
		}
		maxi = max(l -> maxi, r -> maxi);
		mini = min(l -> mini, r -> mini);
		total = l -> total + r -> total;
	}
	
	int rangemin(int x, int y){
		if (s == x && e == y) return mini;
		if (x > m) return r -> rangemin(x, y);
		if (y <= m) return l -> rangemin(x, y);
		return min(l -> rangemin(x, m), r -> rangemin(m + 1, y));
	}
	
	int rangemax(int x, int y){
		if (s == x && e == y) return maxi;
		if (x > m) return r -> rangemax(x, y);
		if (y <= m) return l -> rangemax(x, y);
		return min(l -> rangemax(x, m), r -> rangemax(m + 1, y));
	}
	
	int rangetotal(int x, int y){
		if (s == x && e == y) return total;
		if (x > m) return r -> rangetotal(x, y);
		if (y <= m) return l -> rangetotal(x, y);
		return l -> rangetotal(x, m) + r -> rangetotal(m + 1, y);		
	}
} *root;

int main(){
    scanf("%d", &n);
    root = new node(0, n - 1);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        root -> update(i, arr[i]);
    }
	
    while (true){
        cin >> command;
        scanf("%d%d", &x, &y);
        if (command == "min"){
            printf("%d\n", root -> rangemin(x, y));
        } else if (command == "max"){
            printf("%d\n", root -> rangemax(x, y));
        } else if (command == "sum"){
            printf("%d\n", root -> rangetotal(x, y));
        }
    }
}
