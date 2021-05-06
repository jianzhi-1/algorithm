# Graph Theory

Edge-based algorithms: Heavy Light
Node-based algorithms: Preorder

### Preorder Decomposition
- implemented but untested

### Centroid Decomposition
- max height of centroid tree is O(log N)
- a path that goes a -> c = lca(a, b) -> b in the centroid tree will go from a -> c -> b in the original tree too
- in the centroid decomposition, at each centroid, store the value from centroid to every node in the subtree of centroid
- implemented but untested

### Heavy Light Decomposition
- each node belongs to exactly one (heavy) chain
- every path from root to a node passes through at most logN light edges and logN heavy paths
- O(logN) per query
- edge/path updates, edge/path query
- unimplemented, untested

### 2k Decomposition
- unimplemented, untested

### Euler Tour Decomposition
- unimplemented, untested