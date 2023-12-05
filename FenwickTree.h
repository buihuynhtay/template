struct FenwickTree{
    int n;
    vector<int> t;

    FenwickTree(int _n = 0){
        n = _n;
        if(n)
            t.resize(n + 1, 0);
    }

    int get(int x){
        int res = 0;
        while(x > 0){
            res += t[x];
            x -= (x&-x);
        }
        return res;
    }

    void update(int x, int val){
        while(x <= n){
            t[x] += val;
            x += (x&-x);
        }
    }
};
