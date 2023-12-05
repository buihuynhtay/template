struct Node{
    int val, lz;
    Node(int _val = 0, int _lz = 0){
        val = _val;
        lz = _lz;
    }
    Node operator + (const Node &other) const{
        Node res = Node();
        res.val = val + other.val;
        return res;
    }
};
struct SegmentTree{
    int n;
    vector<Node> st;

    SegmentTree(int _n = 0){
        n = _n;
        if(n) st.resize(n * 4 + 5, Node());
    }

    void build(int id, int l, int r, vector<int> &ar){
        if(l == r){
            st[id] = ar[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(id * 2, l, mid, ar);
        build(id * 2 + 1, mid + 1, r, ar);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    void down(int id, int l, int r, int mid){
        if(st[id].lz == 0) return;
        st[id * 2].val += st[id].lz;
        st[id * 2].lz += st[id].lz;
        st[id * 2 + 1].val += st[id].lz;
        st[id * 2 + 1].lz += st[id].lz;
        st[id].lz = 0;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if(r < u || v < l) return;
        if(u <= l && r <= v){
            st[id] = st[id] + val;
            lz[id] = lz[id] + val;
            return;
        }
        int mid = (l + r) >> 1;
        down(id, l, r, mid);
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    Node get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return Node();
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) >> 1;
        down(id, l, r, mid);
        Node g1 = get(id * 2, l, mid, u, v);
        Node g2 = get(id * 2 + 1, mid + 1, r, u, v);
        return g1 + g2;
    }

    void update(int l, int r, int val){
        update(1, 1, n, l, r, val);
    }
    int get(int l, int r){
        return get(1, 1, n, l, r).val;
    }
};
