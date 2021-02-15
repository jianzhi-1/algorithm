struct ufds{
	
	int n;
	vector<int> p, s;
	
	ufds(int n): n(n){
		p.resize(n);
		s.resize(n);
		REP(i, 0, n){
			p[i] = i;
			s[i] = 1;
		}
	}
	
	int parent(int x){
		if (p[x] == x) return x;
		return p[x] = parent(p[x]);
	}
	
	void mergeNode(int x, int y){
		x = parent(x); y = parent(y);
		if (s[x] < s[y]) swap(x, y);
		p[y] = x;
	}
	
	bool sameParent(int x, int y){
		x = parent(x); y = parent(y);
		return x==y;
	}
};

int main(){
	
	ufds x = ufds(n);
	x.mergeNode(0, 1);
	cout << x.sameParent(0, 1) << endl;

}
