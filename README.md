# A collection of algorithms

### Competition Notes
- Runtime Error: Check memory limits, are there implicit conditions?

### Graph Theory
- Vertices in MVC and vertices in MIS are complements (MVC + MIS = n)
- Konig's theorem: In any bipartite graph, the number of edges in a maximum matching is equal to the number of vertices in a minimum vertex cover.
- Flow methods: 
  - Augmented Path Algorithm: O(VE) but close to O(E)/O(Elg^2E) for dense/sparse graphs
  - Hopcroft Karp's Algorithm: O(Esqrt(v)), good for n <= 600
  - Min Cost Max Flow Algorithm: 
  - Edmonds's Matching Algorithm:
  - DP with bitmask:

### Fenwick
- Array must be 1-indexed.
- Add 1 to each index if necessary.

### Heavy Light Decomposition
- Every path goes through at least O(logN) light edges

### Convex Hull Trick
- _dp[i] = c<sub>i</sub> + min<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_
- _dp[i] = c<sub>i</sub> + max<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_

### DnC
- _dp[i][j] = min<sub>k<j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k<=j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k</sub>(dp[i - 1][k] + C[k][j]_

The necessary condition is _opt[i][j] <= opt[i][j + 1]_
