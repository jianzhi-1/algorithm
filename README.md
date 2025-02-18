# A collection of algorithms

## Competition Notes
- Runtime Error: Check memory limits, are there implicit conditions?
- Runtime Error: Do all declared functions return? If a function is int, make sure it returns something!
- Be generous with data type limits: 2,147,483,647 (int), 9,223,372,036,854,775,807 (ll)
- Usually, just set to ll.
- Offline query
- Probabilistic method (anything to do with 1/2)
- Mod can be negative! Do NOT use _if (x%2 == 1)_. Rather, use _if (x%2 != 0)_

## Facebook Hacker Cup
- `ulimit -s unlimited`
- [In-program](https://nor-blog.codeberg.page/posts/2023-09-25-increase-stack-size/)
- Compiler optimisation `-O2`

```
g++ --std=c++20 -O2 script.cpp -o script
./script
```

## Debugging
- Index array last (caches)
- long long instead of int
- Array size, ordering, increments
- TLE: use '\n' instead of endl (no intermediate flush)

## Resources
- [Stanford's ICPC Notebook](https://cs.stanford.edu/group/acm/oldsite/SLPC/notebook.pdf)
- [CP Algorithms](https://cp-algorithms.com/)

