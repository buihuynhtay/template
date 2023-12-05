int depth[N];
int par[N][19];

void build_lca(int u){
    for(int v : graph[u]){
        if(v == par[u][0]) continue;
        depth[v] = depth[u] + 1;
        par[v][0] = u;
        for(int i = 1; i <= 18; i++){
            par[v][i] = par[par[v][i - 1]][i - 1];
        }
        dfs(v);
    }
}

int lca(int u, int v){
    if(depth[v] > depth[u]) swap(u, v);
    int denta = depth[u] - depth[v];
    for(int i = 0; i <= 18; i++)
        if(BIT(denta, i)){
            u = par[u][i];
        }
    if(u == v) return 0;
    for(int i = 18; i >= 0; i--){
        if(par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
