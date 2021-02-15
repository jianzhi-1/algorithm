struct veniceSet{
	
	map<ll,ll> m;
	ll waterLevel = 0;
	ll offset = 0;
	
	void updateAll(ll v){
		//FOR ALL s
		//dp(x, s) += v
		waterLevel += v;
	}
	
	void updateOne(ll s, ll v){
		//FOR ONE s
		//dp(x, s) += v
		s -= offset;
		if (m.find(s) != m.end()) m[s] += v;
		else m[s] = v;
	}
	
	void shift(ll v){
		//FOR ALL s
		//dp(x + 1, s) -> dp(x, s + v)
		offset += v;
	}
	
	ll query(ll s){
		//QUERY dp(0, s)
		s -= offset;
		if (m.find(s) != m.end()) return waterLevel + m[s];
		return waterLevel;
	}
	
	void clear(){
		m.clear();
		waterLevel = 0;
		offset = 0;
	}
	
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	
	veniceSet vs;
	
	vs.clear();
	
	//SET BASE CASE 
	//FOR ALL s
	//dp(n, s) = 1
	
	vs.updateAll(1); 
	
	REPD(j, n, 0){
		ll val = vs.query(b[j]);
		vs.shift(-b[j]);
		vs.updateAll(val);
		vs.updateOne(0, -val);
	}
	
	cout << vs.query(0) << endl;
	
}
