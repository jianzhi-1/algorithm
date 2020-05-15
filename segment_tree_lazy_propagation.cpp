#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int n, arr[1000], x, y, v;
string command;

struct node{
	int s, e, m, maxi, mini, total, delta;
	//delta stores the value to be added
	node *l, *r;
	node (int _s, int _e): s(_s), e(_e), m((_s + _e)/2), maxi(0), mini(0), total(0), delta(0){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	//range update, increase by value of nv
	void update(int x, int y, int nv){
		
		if (s == x && e == y){
			delta += nv;
			if (s == e){
				total += delta;
				maxi = mini = total;
				delta = 0;
			}
			return;
		}
		if (x > m){
			r -> update(x, y, nv);
		} else if (y <= m){
			l -> update(x, y, nv);
		} else {
			l -> update(x, m, nv);
			r -> update(m + 1, y, nv);			
		}
		maxi = max(l -> maxi + l -> delta, r -> maxi + r -> delta);
		mini = min(l -> mini + l -> delta, r -> mini + r -> delta);
		total = l -> total + (m - s + 1)*(l -> delta) + r -> total + (e - m)*(r -> delta);

	}
	
	//point query
	int query(int x){
		if (s == e){
			total += delta;
			maxi = mini = total;
			delta = 0;
			return total;
		}
		if (delta != 0){
			l -> delta += delta;
			r -> delta += delta;
			delta = 0;
		}
		if (x > m){
			return r -> query(x);
		} else {
			return l -> query(x);
		}
	}
	
	int rangemin(int x, int y){
		if (s == x && e == y){
			return mini + delta;
		}
		if (x > m) return r -> rangemin(x, y);
		if (y <= m) return l -> rangemin(x, y);
		return min(l -> rangemin(x, m) + l -> delta, r -> rangemin(m + 1, y) + r -> delta);
	}
	
	int rangemax(int x, int y){
		if (s == x && e == y){
			return maxi + delta;
		}
		if (x > m) return r -> rangemax(x, y);
		if (y <= m) return l -> rangemax(x, y);
		return min(l -> rangemax(x, m) + l -> delta, r -> rangemax(m + 1, y) + r -> delta);
	}
	
	int rangetotal(int x, int y){
		if (s == x && e == y){
			return total + (y - x + 1)*delta;
		}
		if (x > m) return r -> rangetotal(x, y);
		if (y <= m) return l -> rangetotal(x, y);
		return l -> rangetotal(x, m) + (m - x + 1)*(l -> delta) + r -> rangetotal(m + 1, y) + (y - m)*(r -> delta);
	}	
	
} *root;

int main(){
    scanf("%d", &n);
    root = new node(0, n - 1);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        root -> update(i, i, arr[i]);
    }
	
    while (true){
        cin >> command;
        
        if (command == "update"){
        	scanf("%d%d%d", &x, &y, &v);
        	root -> update(x, y, v);
            printf("Updated\n");
        } else if (command == "max"){
        	scanf("%d%d", &x, &y);
            printf("%d\n", root -> rangemax(x, y));
        } else if (command == "sum"){
        	scanf("%d%d", &x, &y);
            printf("%d\n", root -> rangetotal(x, y));
        } else if (command == "min"){
        	scanf("%d%d", &x, &y);
        	printf("%d\n", root -> rangemin(x, y));
        } else if (command == "query"){
        	scanf("%d", &x);
        	printf("%d\n", root -> query(x));
        }
    }
}
