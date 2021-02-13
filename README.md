# A collection of algorithms

## Competition Notes
- Runtime Error: Check memory limits, are there implicit conditions?
- Be generous with data type limits: 2,147,483,647 (int), 9,223,372,036,854,775,807 (ll)
- Usually, just set to ll.

### Implementation
- _array<ll, 5> = {1, 2, 3, 4, 5};_
- _pi cur = {3, 5};_
- _vector<int> v = {1, 2, 3};_
- _int* ptr; //creates a pointer of type int_
- _ptr = &var; //assigns pointer to address_
- _cout << *ptr << endl; //get the value that pointer is pointing to_
- _int& ref = var; //creates another ref to var_
- _cout << ref << endl; //get the value at ref_
- _typeid(var).name(); //gets the type of variable var_
  
### Checking for Error
_res[i] = (int)(a[i].real() + 0.5)_;
_error = max(error, abs(a[i].real() - (int)(a[i].real() + 0.5)))_;

## Maths
- Divisor function upper bound = _2*sqrt(N)_. Better bound =_N^(c/log(logN))_
- Operations: any invariants? Work backwards? Equivalent conditions?

## Graph Theory
- Vertices in MVC and vertices in MIS are complements (MVC + MIS = n)
- Konig's theorem: In any bipartite graph, the number of edges in a maximum matching is equal to the number of vertices in a minimum vertex cover.
- Flow methods: 
  - Augmented Path Algorithm: O(VE) but close to O(E)/O(Elg^2E) for dense/sparse graphs
  - Hopcroft Karp's Algorithm: O(Esqrt(v)), good for n <= 600
  - Min Cost Max Flow Algorithm: 
  - Edmonds's Matching Algorithm:
  - DP with bitmask:
- Max-flow Min-cut Theorem: The maximum flow of an s-t flow is equal to the minimum capacity over all s-t cuts.

## Data Structure

### Fenwick
- Array must be 1-indexed.
- Add 1 to each index if necessary.

### Heavy Light Decomposition
- Every path goes through at least O(logN) light edges

## Dynamic Programming

### General 
- _dp(x) = max<sub>i</sub>(|a<sub>i</sub> - a<sub>x</sub>| + dp(i)) = max(max<sub>i</sub>(a<sub>i</sub> + dp(i)) - a<sub>x</sub>, max<sub>i</sub>(- a<sub>i</sub> + dp(i)) + a<sub>x</sub>)_

### Convex Hull Trick
- _dp[i] = c<sub>i</sub> + min<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_
- _dp[i] = c<sub>i</sub> + max<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_

### DnC
- _dp[i][j] = min<sub>k<j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k<=j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k</sub>(dp[i - 1][k] + C[k][j]_

The necessary condition is _opt[i][j] <= opt[i][j + 1]_
