# A collection of algorithms

### Convex Hull Trick
- _dp[i] = c<sub>i</sub> + min<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>
- _dp[i] = c<sub>i</sub> + max<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>

### DnC
- _dp[i][j] = min<sub>k<j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k<=j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k</sub>(dp[i - 1][k] + C[k][j]_

The necessary condition is _opt[i][j] <= opt[i][j + 1]_
