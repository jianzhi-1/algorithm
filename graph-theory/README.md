# Graph Theory

Before using these, can the problem be solved using simple tree DP?

### Preorder Decomposition
- implemented but untested

### Centroid Decomposition
- max height of centroid tree is O(log N)
- a path that goes a -> c = lca(a, b) -> b in the centroid tree will go from a -> c -> b in the original tree too
- in the centroid decomposition, at each centroid, store the value from centroid to every node in the subtree of centroid
- O(logN) layers, each layer stores max O(N). i.e. total path stored: O(N log N)
- every other path is the concatenation between two paths at a centroid 
- when set merging, always merge smaller set to larger set O(Nlog^2N)
- do NOT merge same sets from same branch together!

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

### Matching
- Maximum Cardinality Bipartite Matching (MCBM): Augmenting paths algorithm O(N^3)
- Minimum cost maximum matching: Hungarian Algorithm O(N^3)

### Flow
- Maximum flow: Dinic's Algorithm O(VE)
- Minimum cost: minCost.cpp
- Min-cost Max-flow: combine the above two
