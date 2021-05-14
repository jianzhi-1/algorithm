void factorise(int x, vector<int> &fx){
	if (x == 1) return;
	VREP(it, primeList){
		if (x % (*it) == 0){
			fx.PB(*it);
			while (x % (*it) == 0) x /= (*it);
		}
		if (SQR(*it) > x) break;
	}
	if (x != 1) fx.PB(x);
	return;
}
