# A collection of algorithms

## Competition Notes
- Runtime Error: Check memory limits, are there implicit conditions?
- Runtime Error: Do all declared functions return? If a function is int, make sure it returns something!
- Be generous with data type limits: 2,147,483,647 (int), 9,223,372,036,854,775,807 (ll)
- Usually, just set to ll.
- Offline query
- Probabilistic method (anything to do with 1/2)
- Mod can be negative! Do NOT use _if (x%2 == 1)_. Rather, use _if (x%2 != 0)_

### Implementation
- Fast Data Structure Declaration
```c++
array<ll, 5> = {1, 2, 3, 4, 5};
pi cur = {3, 5};
vector<int> v = {1, 2, 3};
```
- Pointers and References
```c++
int* ptr; //creates a pointer of type int
ptr = &var; //assigns pointer to address
cout << *ptr << endl; //get the value that pointer is pointing to
int& ref = var; //creates another ref to var
cout << ref << endl; //get the value at ref
```
- Misc
```c++
typeid(var).name(); //gets the type of variable var
assert(condition); //good for debugging, checking the validity of DP states
assert(x >= 0); //program stops if x < 0
```

- Forward declaration
```c++
void f(int x);
void g(int x){return (x == 0)?0:f(x-1);}
void f(int x){return (x == 0)?0:g(x-1);}
```
  
- Floating Point
```c++
res[i] = (int)(a[i].real() + 0.5);
error = max(error, abs(a[i].real() - (int)(a[i].real() + 0.5)));
```

## Maths
- Divisor function upper bound = _2*sqrt(N)_. Better bound =_N^(c/log(logN))_
- Operations: any invariants? Work backwards? Equivalent conditions?
- Time complexity of sieve and its variants: _O(N log(log(N)) )_

## Graph Theory
- Phantom nodes, phantom edges
- Vertices in MVC and vertices in MIS are complements (MVC + MIS = n)
- Minimum cycle-breaking graph = Maximum spanning tree [GKS-A 2021]
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
- Handling absolute value in transition state: _dp(x) = max<sub>i</sub>(|a<sub>i</sub> - a<sub>x</sub>| + dp(i)) = max(max<sub>i</sub>(a<sub>i</sub> + dp(i)) - a<sub>x</sub>, max<sub>i</sub>(- a<sub>i</sub> + dp(i)) + a<sub>x</sub>)_
- Be sure of what state is unreachable, set an inf or -inf that is larger.
- Bottom up DP if top down DP TLEs.

### Venice Set Trick
- _dp(x, c) = dp(x + 1, c + b<sub>x</sub>) + dp(x + 1, b<sub>x</sub>)_
- Linear shift in keys/values and/or point update
- Keep a map with offset (keys) and waterLevel (values)

### Convex Hull Trick
- _dp[i] = c<sub>i</sub> + min<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_
- _dp[i] = c<sub>i</sub> + max<sub>j<i</sub>m<sub>j</sub>f<sub>i</sub>+c'<sub>j</sub>_

### DnC
- _dp[i][j] = min<sub>k<j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k<=j</sub>(dp[i - 1][k] + C[k][j]_
- _dp[i][j] = min<sub>k</sub>(dp[i - 1][k] + C[k][j]_

The necessary condition is _opt[i][j] <= opt[i][j + 1]_
