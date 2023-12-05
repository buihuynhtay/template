struct Hash{
    vector<ll> pw, code;
    ll mod, base;

    Hash(string &s, int _mod = 1e9 + 7, int _base = 137){
        mod = _mod;
        base = _base;
        pw.resize(Size(s) + 1, 1);
        code.resize(Size(s) + 1, 0);
        for(int i = 1; i <= Size(s); i++)
            pw[i] = pw[i - 1] * base % mod;
        for(int i = 1; i <= Size(s); i++)
            code[i] = (code[i - 1] * base + s[i - 1]) % mod;
    }

    ll get(int l, int r){
        return (code[r] - code[l - 1] * pw[r - l + 1] + mod * mod) % mod;
    }
};
