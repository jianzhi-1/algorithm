# A collection of algorithms

## Competition Notes
- Runtime Error: Check memory limits, are there implicit conditions?
- Runtime Error: Do all declared functions return? If a function is int, make sure it returns something!
- Be generous with data type limits: 2,147,483,647 (int), 9,223,372,036,854,775,807 (ll)
- Usually, just set to ll.
- Offline query
- Probabilistic method (anything to do with 1/2)
- Mod can be negative! Do NOT use _if (x%2 == 1)_. Rather, use _if (x%2 != 0)_

### Implementation
- Fast Data Structure Declaration
```c++
array<ll, 5> = {1, 2, 3, 4, 5};
pi cur = {3, 5};
vector<int> v = {1, 2, 3};
```
- Pointers and References
```c++
int* ptr; //creates a pointer of type int
ptr = &var; //assigns pointer to address
cout << *ptr << endl; //get the value that pointer is pointing to
int& ref = var; //creates another ref to var
cout << ref << endl; //get the value at ref
```
- Misc
```c++
typeid(var).name(); //gets the type of variable var
assert(condition); //good for debugging, checking the validity of DP states
assert(x >= 0); //program stops if x < 0
```

- Forward declaration
```c++
void f(int x);
void g(int x){return (x == 0)?0:f(x-1);}
void f(int x){return (x == 0)?0:g(x-1);}
```
  
- Floating Point
```c++
res[i] = (int)(a[i].real() + 0.5);
error = max(error, abs(a[i].real() - (int)(a[i].real() + 0.5)));
```

