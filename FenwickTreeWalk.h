struct FenwickTree{
    int n;
    vector<pll> t;

    FenwickTree(int _n = 0){
        n = _n;
        if(n)
            t.resize(n + 1, pll(0, 0));
    }

    void update(int x, pll val){
        while(x <= n){
            t[x].fi += val.fi;
            t[x].se += val.se;
            x += (x&-x);
        }
    }

    pll get(int val){
        int cr = 0;
        pll res = {0, 0};
        int lg = 31 - __builtin_clz(n);
        for(int i = lg; i >= 0; i--){
            if(cr + MASK(i) <= n && t[cr + MASK(i)].se + res.se <= val){
                cr += MASK(i);
                res.fi += t[cr].fi;
                res.se += t[cr].se;
            }
        }
        return res;
    }
};
