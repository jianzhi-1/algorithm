int rint(int n){
	srand(time(0));
	return rand()%n;
}

int main(){
	vector<int> v;
	v.resize(10);
	iota(v.begin(), v.end(), 0);
	random_shuffle(v.begin(), v.end());
	
	cout << rint(100) << endl;
}
