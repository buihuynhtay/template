struct Edge{
    int u, v, w;
    bool operator < (const Edge &other) const{
        return w < other.w;
    }
};
struct DSU{
    vector<int> sz, par;
    int n;

    DSU(int _n = 0){
        n = _n;
        if(n){
            sz.resize(n + 1, 1);
            par.resize(n + 1, 0);
        }
    }

    int root(int u){
        return par[u] ? par[u] = root(par[u]) : u;
    }

    bool join(int u, int v){
        u = root(u);
        v = root(v);
        if(u == v) return false;
        if(sz[v] > sz[u]) swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }

    bool same(int u, int v){
        return root(u) == root(v);
    }
};
