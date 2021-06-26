bool decomp(int s, int e, bool x){

	if (e - s == 1){
		if (s2[s] == '0') return 0;
		if (s2[s] == '1') return 1;
		if (s2[s] == 'x') return x;
		return !x;
	}
	
	pair<char, int> op;
	int tt = 0;
	REP(i, s, e){
		if (s2[i] == '('){
			tt++;
		} else if (s2[i] == ')'){
			tt--;
		} else if (tt == 1){
			if (s2[i] == '&' || s2[i] == '^' || s2[i] == '|'){
				op = MP(s2[i], i);
			}
		} 
	}
    
	bool left = decomp(s + 1, op.se, x);
	bool right = decomp(op.se + 1, e - 1, x);
	
	if (op.fi == '&') return (left&right);
	else if (op.fi == '^') return (left^right);
	else return (left|right);
	
}
