vector<string> split(string ss, string delimiter) {
    size_t s = 0, e, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((e = ss.find(delimiter, s)) != string::npos) {
        token = ss.substr(s, e - s);
        s = e + delim_len;
        res.PB(token);
    }

    res.PB(ss.substr(s));
    return res;
}
