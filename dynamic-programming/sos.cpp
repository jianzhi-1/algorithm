const ll N = 15, pN = (1 << 15);

ll A[pN], F[pN];

REP (i, 0, pN) F[i] = A[i];

REP(i, 0, N){
    for (ll mask = 0; mask < pN; mask++){
	    if (mask & (1<<i)) F[mask] += F[mask^(1<<i)];
	    //if (!(mask & (1<<i))) F[mask] += F[mask^(1<<i)];
    }
}
