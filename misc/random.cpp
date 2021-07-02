mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	vector<ll> v;
	REP(i, 0, n) v.PB(i);
	shuffle(v.begin(), v.end(), rng);
	
	cout << rng() << endl;
}
