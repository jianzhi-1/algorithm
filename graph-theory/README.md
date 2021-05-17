# Graph Theory

Before using these, can the problem be solved using simple tree DP?

### Preorder Decomposition
- implemented but untested

### Centroid Decomposition
- max height of centroid tree is _O(log N)_
- a path that goes a -> c = lca(a, b) -> b in the centroid tree will go from a -> c -> b in the original tree too
- in the centroid decomposition, at each centroid, store the value from centroid to every node in the subtree of centroid
- _O(log N)_ layers, each layer stores max _O(N)_. i.e. total path stored: _O(N log N)_
- every other path is the concatenation between two paths at a centroid 
- when set merging, always merge smaller set to larger set _O(Nlog<sup>2</sup>N)_
- do NOT merge same sets from same branch together!

### Heavy Light Decomposition
- each node belongs to exactly one (heavy) chain
- every path from root to a node passes through at most _log(N)_ light edges and logN heavy paths
- _O(log N)_ per query
- edge/path updates, edge/path query
- unimplemented, untested

### 2k Decomposition
- unimplemented, untested

### Euler Tour Decomposition
- unimplemented, untested

### Matching
- Maximum Cardinality Bipartite Matching (MCBM): Augmenting paths algorithm _O(N<sup>3</sup>)_
- Minimum cost maximum matching: Hungarian Algorithm _O(N<sup>3</sup>)_

### Flow
- Maximum flow: Dinic's Algorithm _O(VE)_
- Minimum cost: minCost.cpp
- Min-cost Max-flow: combine the above two
