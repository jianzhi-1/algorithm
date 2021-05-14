multiset<int> ms;

void print_ms(){
	cout << "Multiset contains: " << endl;
	VREP(it, ms){
		if (it != ms.begin()) cout << " ";
		cout << *it;
	}
	cout << endl;
}

int main(){
	
	ms.insert(10);
	ms.insert(10);
	ms.insert(20);
	ms.insert(30);
	ms.insert(30);
	ms.insert(40);
	print_ms();
	
	auto it = ms.lower_bound(30);
	ms.erase(it);
	print_ms();
	
	ms.erase(10);
	print_ms();
	
}
