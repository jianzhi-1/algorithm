struct centroidDecomposition{
	
	int sz, cur_size = 0, mainCentroid = 0; //mainCentroid is the overall centroid of graph
	vector<vector<int> > tree, ctree;
	vector<int> isCentroid;
	
	//initialise with adjList
	centroidDecomposition(int n, vector<vector<int> > adjList){
		sz = n;
		tree.resize(n);
		ctree.resize(n);
		isCentroid.resize(n, 0); //set all to false
		REP(i, 0, n){
			VREP(it, adjList[i]) tree[i].PB(*it);
		}
	}
	
	void dfs(int src, vector<bool> &visited, vector<int> &subtree){

		visited[src] = true;
		subtree[src] = 1;
		cur_size += 1;
		VREP(it, tree[src]){
			if ((!visited[*it]) && (!isCentroid[*it])){
				dfs(*it, visited, subtree);
				subtree[src] += subtree[*it];
			}
		}
	}
	
	int findCentroid(int src, vector<bool> &visited, vector<int> &subtree){

		visited[src] = true;
		bool testCentroid = true;
		int heavy_node = 0;
        
		VREP(it, tree[src]){
			if ((!visited[*it]) && (!isCentroid[*it])){
				if (2*subtree[*it] > cur_size) testCentroid = false;
				if (heavy_node == 0 || subtree[*it] > subtree[heavy_node]) heavy_node = (*it);
			}
		}
		
		if (testCentroid && 2*(cur_size - subtree[src]) <= cur_size) return src;
		return findCentroid(heavy_node, visited, subtree);
		
	}
	
	//return the centroid of the tree/subtree given a source node
	int findCentroidUtil(int src){

		vector<bool> visited;
        vector<int> subtree;
        
		visited.resize(sz, 0); //all initially false
		subtree.resize(sz, 0);
		cur_size = 0;
        
		dfs(src, visited, subtree);
		REP(i, 0, sz) visited[i] = false;
        
		int centroid = findCentroid(src, visited, subtree);
		isCentroid[centroid] = true;
		return centroid;
	}
	
	//decomposes tree given root is a node
	int decomposeTree(int root){
		int centroid_tree = findCentroidUtil(root);
		VREP(it, tree[centroid_tree]){
			if (!isCentroid[*it]){
				int centroid_subtree = decomposeTree(*it);
				ctree[centroid_tree].PB(centroid_subtree);
				ctree[centroid_subtree].PB(centroid_tree);
			}
		}
		return mainCentroid = centroid_tree;
	}
	
};

void dfsprint(int x, int par, centroidDecomposition &a){
	cout << "the children of node " << x << " are: ";
	VREP(it, a.ctree[x]){
		if ((*it) == par) continue;
		cout << (*it) << " ";
	}
	cout << endl;
	VREP(it, a.ctree[x]){
		if ((*it) == par) continue;
		dfsprint(*it, x, a);
	}
}

int n, a, b;
int main(){
	cin >> n;
	vector<vector<int> > adjList;
	adjList.resize(n);
	REP(i, 0, n - 1){
		cin >> a >> b;
		adjList[a].PB(b);
		adjList[b].PB(a);
	}
	
	centroidDecomposition a = centroidDecomposition(n, adjList);
	a.decomposeTree(0);
        
    //more for debugging purposes
	dfsprint(a.mainCentroid, -1, a);
}
