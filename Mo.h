struct Query{
    const BLOCK = 320;
    int l, r, id;
    Query(int l = 0, int r = 0, int id = 0) :
        l(l), r(r), id(id) {}
    bool operator < (const Query &other) const{
        if(l / BLOCK == other.l / BLOCK)
            return r < other.r;
        return l / BLOCK < other.l / BLOCK;
    }
};

void Add(int x){

}
void Sub(int x){

}

void process(){
    sort(all(query));
    int crL = 0, crR = 0;
    for(auto it : query){
        int l = it.l;
        int r = it.r;
        int id = it.id;
        while(crL < l) Sub(crL++);
        while(crL > l) Add(--crL);
        while(crR < r) Add(++crR);
        while(crR > r) Sub(crR--);
    }
}
