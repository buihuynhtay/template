void build_rmq(int ar[]){
    for(int i = 1; i <= n; i++)
        rmq[i][0] = ar[i];
    for(int j = 1; j <= 18; j++)
        for(int i = 1; i + MASK(j) - 1 <= n; i++)
            rmq[i][j] = min(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);
}

int get(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return min(rmq[l][k], rmq[r - MASK(k) + 1][k]);
}
