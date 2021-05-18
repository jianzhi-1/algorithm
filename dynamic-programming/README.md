# Dynamic Programming

### General 
- Handling absolute value in transition state: _dp(x) = max<sub>i</sub>(|a<sub>i</sub> - a<sub>x</sub>| + dp(i)) = max(max<sub>i</sub>(a<sub>i</sub> + dp(i)) - a<sub>x</sub>, max<sub>i</sub>(- a<sub>i</sub> + dp(i)) + a<sub>x</sub>)_
- Be sure of what state is unreachable, set an inf or -inf that is larger.
- Bottom up DP if top down DP TLEs.

### DP On Graphs
- Must find an order for the graph.
- Is it Directed Acyclic Graph?
- Is it a Tree?
- Is it topo-sortable?
- Is it SCC-able?

### Venice Set Trick
- _dp(x, c) = dp(x + 1, c + b<sub>x</sub>) + dp(x + 1, b<sub>x</sub>)_
- Linear shift in keys/values and/or point update
- Keep a map with offset (keys) and waterLevel (values)

### Convex Hull Trick
- Use Li Chao Tree
- _dp[i] = c<sub>i</sub> + min<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_
- _dp[i] = c<sub>i</sub> + max<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_

### DnC
- _dp[i][j] = min<sub>k<j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k<=j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k</sub>(dp[i - 1][k] + C[k][j]_

The necessary condition is _opt[i][j] <= opt[i][j + 1]_

### Knuth Yao Optimisation
- unimplemented
- https://codeforces.com/blog/entry/47932

### Aliens Trick
- _res<sub>i+1</sub> - res<sub>i</sub> <= res<sub>i</sub> - res<sub>i-1</sub>_
- exists real _X_ such that _res<sub>i</sub> + i*X <= res<sub>j</sub> + j*X_
- binary search for _X_
- _O(NK)_ to _O(N log A)_
