int z[MAX_N];

void zfunction(string s) {
    int n = (int)s.length(), l = 0, r = 0;
    z[0] = 0;
    REP(i, 1, n){
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] - 1 > r){
            l = i, r = i + z[i] - 1;
        }
    }
}
