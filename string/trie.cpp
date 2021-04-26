struct stringTrie{
	
	vector<set<pair<char, int> > > s;
	vector<int> e; //number of words that end at node
	int root = 0, newn = 1;
	
	stringTrie(int n){
        //n = number of characters
		s.resize(n + 1); //including root
		e.resize(n + 1, 0);
	}
	
	void addString(string str){
		int curnode = root;
		REP(i, 0, (int)str.length()){
			auto it = s[curnode].upper_bound(MP(str[i], -1));
			if (it == s[curnode].end() || (it -> first) != str[i]){
				s[curnode].insert(MP(str[i], newn));
				curnode = newn;
				newn++;
			} else {
				curnode = (it -> second);
			}
		}
		e[curnode]++;
	}

};

int main(){
    stringTrie tt = stringTrie(n);
    REP(i, 0, n) tt.addString(str);
}
