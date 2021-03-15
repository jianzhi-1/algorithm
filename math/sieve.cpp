bool sieve[200005];
vector<ll> primeList;   // primeList: a vector of all primes
map<ll, int> pmap;      // primeMap: maps prime to index
map<int, ll> rpmap;     // reverse primeMap: maps index to prime

void initSieve(){
   	REP(i, 0, 200005) sieve[i] = true;
	sieve[0] = sieve[1] = false;
   	primeList.PB(2);
	for (int i = 4; i < 200005; i+=2) sieve[i] = false;
	for (int i = 3; i < 200005; i+=2){
		if (!sieve[i]) continue;
		primeList.PB(i);
		for (int j = 2*i; j < 200005; j+=i) sieve[j] = false;
	}
   	int c = 0;
	VREP(it, primeList){
        pmap[*it] = c;
        rpmap[c] = *it;
    }
}

int main(){
    initSieve();
}
