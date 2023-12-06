struct Node{
    int l, r, val;
    Node(){
        l = r = val = 0;
    }
};

struct SegmentTree{
    int n;
    vector<Node> st;
    int cnt = 0;

    SegmentTree(int _n = 0){
        n = _n;
        if(n){
            st.resize(n * 4 + 5, Node());
        }
    }
    void cal(int id){
        int l = st[id].l;
        int r = st[id].r;
        st[id].val = st[l].val + st[r].val;
    }
    int update(int id, int l, int r, int u, int val){
        if(l == r){
            int new_node = ++cnt;
            st[new_node].val += val;
            return new_node;
        }
        int mid = (l + r) >> 1;
        int new_node = ++cnt;

        if(u <= mid){
            st[new_node].l = update(st[id].l, l, mid, u, val);
            st[new_node].r = st[id].r;
        }
        else{
            st[new_node].l = st[id].l;
            st[new_node].r = update(st[id].r, mid + 1, r, u, val);
        }

        cal(new_node);
        return new_node;
    }
    int get(int id, int l, int r, int u, int v){
        if(r < u || v < l) return 0;
        if(u <= l && r <= v) return st[id].val;
        int mid = (l + r) >> 1;
        return get(st[id].l, l, mid, u, v) + get(st[id].r, mid + 1, r, u, v);
    }
};
