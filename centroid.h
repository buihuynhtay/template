int child[N], dd[N];

void dfs(int u, int par){
    child[u] = 1;
    for(int v : graph[u]){
        if(v == par || dd[v]) continue;
        dfs(v, u);
        child[u] += child[v];
    }
}
int centroid(int u, int par, int n){
    for(int v : graph[u]){
        if(v == par || dd[v]) continue;
        if(child[v] > n/2) return centroid(v, u, n);
    }
    return u;
}

void cal(int u){
    dd[u] = 1;

    for(int v : graph[u]){
        if(dd[v]) continue;
        dfs(v, u);
        cal(centroid(v, -1, child[v]));
    }
}
