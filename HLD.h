struct SegmentTree{
    int n;
    vector<int> st, lz;
    SegmentTree(int _n = 0){
        n = _n;
        if(n){
            st.resize(n * 4 + 5, 0);
            lz.resize(n * 4 + 5, 0);
        }
    }
    void down(int id, int l, int r){
        if(lz[id] == 0) return;
        int mid =(l + r) >> 1;
        st[id * 2] += (mid - l + 1) * lz[id];
        lz[id * 2] += lz[id];
        st[id * 2 + 1] += (r - mid) * lz[id];
        lz[id * 2 + 1] += lz[id];
        lz[id] = 0;
    }
    void update(int id, int l, int r, int u, int v, int val){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            st[id] += (r - l + 1) * val;
            lz[id] += val;
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id];
        down(id, l, r);
        int mid = (l + r) >> 1;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
};

SegmentTree seg;
int n, m, child[N], depth[N], par[N], heavy[N], pos[N], root[N];

void dfs(int u){
    child[u] = 1;
    int mx = 0;
    for(int v : graph[u]){
        if(v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs(v);
        if(Max(mx, child[v])){
            heavy[u] = v;
        }
        child[u] += child[v];
    }
}

void hld(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(par[i] == 0 || heavy[par[i]] != i){
            for(int j = i; j; j = heavy[j]){
                root[j] = i;
                pos[j] = ++cnt;
            }
        }
    }
}

void update(int u, int v){
    while(root[u] != root[v]){
        if(depth[root[u]] < depth[root[v]]) swap(u, v);
        seg.update(1, 1, n, pos[root[u]], pos[u], 1);
        u = par[root[u]];
    }
    if(depth[u] > depth[v]) swap(u, v);
    seg.update(1, 1, n, pos[u], pos[v], 1);
}

int get(int u, int v){
    int res = 0;
    while(root[u] != root[v]){
        if(depth[root[u]] < depth[root[v]]) swap(u, v);
        res += seg.get(1, 1, n, pos[root[u]], pos[u]);
        u = par[root[u]];
    }
    if(depth[u] < depth[v]) swap(u, v);
    res += seg.get(1, 1, n, pos[v], pos[u]);
    return res;
}
