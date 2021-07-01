const ll MAX_INT = 200005;
bool sieve[MAX_INT];
vector<ll> primeList;   // primeList: a vector of all primes
map<ll, int> pmap;      // primeMap: maps prime to index
map<int, ll> rpmap;     // reverse primeMap: maps index to prime

void initSieve(){
   	REP(i, 0, MAX_INT) sieve[i] = true;
	sieve[0] = sieve[1] = false;
   	primeList.PB(2);
	for (int i = 4; i < MAX_INT; i+=2) sieve[i] = false;
	for (int i = 3; i < MAX_INT; i+=2){
		if (!sieve[i]) continue;
		primeList.PB(i);
		for (int j = 2*i; j < MAX_INT; j+=i) sieve[j] = false;
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
