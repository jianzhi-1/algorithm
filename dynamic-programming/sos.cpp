const ll N = 15, pN = (1 << 15);

ll A[pN], F[pN];
ll dp[pN][N + 1];

for (ll mask = 0; mask < pN; mask++){
	dp[mask][0] = A[mask];
	REP(i, 0, N){
		if (mask & (1<<i)) dp[mask][i + 1] = dp[mask][i] + dp[mask^(1<<i)][i];
		//if (!(mask & (1<<i))) dp[mask][i + 1] = dp[mask][i] + dp[mask^(1<<i)][i];
		else dp[mask][i + 1] = dp[mask][i];
	}
	F[mask] = dp[mask][N];
}

REP (i, 0, (1 << N)) F[i] = A[i];

REP(i, 0, N)
    for (ll mask = 0; mask < pN; mask++){
	    if (mask & (1<<i)) F[mask] += F[mask^(1<<i)];
	    //if (!(mask & (1<<i))) F[mask] += F[mask^(1<<i)];
    }
}
