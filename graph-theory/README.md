# Graph Theory

### General
- phantom nodes, phantom edges
- reverse node and edges
- Vertices in MVC and vertices in MIS are complements (MVC + MIS = n)
- Minimum cycle-breaking graph = Maximum spanning tree [GKS-A 2021]

### Trees

##### Binary Search
- binary lifting

##### DFS Variants (DFS Low-link)
- preorder/postorder
- undirected graphs do not have cross edges
- finding bridges: _O(V+E)_
- finding cut-vertex: _O(V+E)_

Before using these, can the problem be solved using simple tree DP?

##### Preorder Decomposition
- preorder DFS + segment tree
- implemented but untested

##### Centroid Decomposition
- max height of centroid tree is _O(log N)_
- a path that goes a -> c = lca(a, b) -> b in the centroid tree will go from a -> c -> b in the original tree too
- in the centroid decomposition, at each centroid, store the value from centroid to every node in the subtree of centroid
- _O(log N)_ layers, each layer stores max _O(N)_. i.e. total path stored: _O(N log N)_
- every other path is the concatenation between two paths at a centroid 
- when set merging, always merge smaller set to larger set _O(Nlog<sup>2</sup>N)_
- do NOT merge same sets from same branch together!

##### Heavy Light Decomposition
- each node belongs to exactly one (heavy) chain
- every path from root to a node passes through at most _log(N)_ light edges and _log(N)_ heavy paths
- _O(log N)_ per query
- edge/path updates, edge/path query
- unimplemented, untested

##### 2k Decomposition
- implemented, untested

##### Euler Tour Decomposition
- implemented, untested

### Directed Acyclic Graphs (DAG)

##### SCC

### Flows and Matching

##### Matching
- Maximum Cardinality Bipartite Matching (MCBM): Augmenting paths algorithm _O(N<sup>3</sup>)_
- Minimum cost maximum matching: Hungarian Algorithm _O(N<sup>3</sup>)_
- Konig's theorem: In any bipartite graph, the number of edges in a maximum matching is equal to the number of vertices in a minimum vertex cover.

##### Flow (To be improved)
- Maximum flow: Dinic's Algorithm _O(E√V)_
- Minimum cost: minCost.cpp
- Min-cost Max-flow: combine the above two
- Max-flow Min-cut Theorem: The maximum flow of an s-t flow is equal to the minimum capacity over all s-t cuts.

- Augmented Path Algorithm: O(VE) but close to O(E)/O(Elg^2E) for dense/sparse graphs
- Hopcroft Karp's Algorithm: O(Esqrt(v)), good for n <= 600
- Min Cost Max Flow Algorithm: 
- Edmonds's Matching Algorithm:
- DP with bitmask:


