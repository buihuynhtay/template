void floy(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j)
                dist[i][j] = inf;
        }
    }

    for(int z = 1; z <= n; z++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                Min(dist[u][v], dist[u][z] + dist[z][v]);
}
