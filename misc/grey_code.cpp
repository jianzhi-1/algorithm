int g(int n) {
    return n^(n >> 1);
}

int inv_g(int g) {
    int n = 0;
    for (; g; g >>= 1) n ^= g;
    return n;
}
