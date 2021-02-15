struct node{
	
	int s, e, m;
	node *l, *r;
	vector<int> v;
	
	node (int s, int e): s(s), e(e), m((s + e)/2){
		if (s != e){
			l = new node(s, m);
			r = new node(m + 1, e);
		}
	}
	
	void update(int x, int nv){
		v.PB(nv);
		if (s == e) return;
		if (x > m) r -> update(x, nv);
		if (x <= m) l -> update(x, nv);
	}
	
	void nodeSort(){
		if (s == e) return;
		sort(v.begin(), v.end());
		l -> nodeSort(); r -> nodeSort();
	}
	
	int smallerThan(int x, int y, int k){
		if (s == x && e == y) return upper_bound(v.begin(), v.end(), k) - v.begin();
		if (x > m) return r -> smallerThan(x, y, k);
		if (y <= m) return l -> smallerThan(x, y, k);
		return l -> smallerThan(x, m, k) + r -> smallerThan(m + 1, y, k);
	}
	
	int query(int x, int y, int k){
		int mini = -1, maxi = 1000000000;
		while (mini + 1 != maxi){
			int middle = (mini + maxi + 1)/2;
			if (smallerThan(x, y, middle) >= k) maxi = middle;
			else mini = middle;
		}
		return maxi;
	}

};

int main(){
	node *root = new node(0, n);
	REP(i, 0, n) root -> update(i, a[i]);
	root -> nodeSort();
	REP(i, 0, q) cout << root -> query(l, r, k) << endl;
}
