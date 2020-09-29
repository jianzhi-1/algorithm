//FENWICK ARRAY CANNOT BE 0-INDEXED!
//ADD ONE TO INDEX IF NECESSARY

const ll MAX_N = 300005;

ll n, q, nq, x, y;
ll fw[MAX_N], arr[MAX_N];

void update(ll x, ll v){
	for (; x < MAX_N; x+=x&(-x)) fw[x] += v;
}

ll sum(ll x){
	ll res = 0;
	for (; x; x-=x&(-x)) res += fw[x];
	return res;
}

int main(){
	REP(i, 0, n) update(i + 1, arr[i]); //assuming 0-indexed
	update(x + 1, y); 
	cout << sum(y + 1) - sum(x) << endl; //sum [x, y]
}

//cout.flush()
//cout << fixed << setprecision(9) << x << endl;
