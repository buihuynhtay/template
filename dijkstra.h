void dijkstra(int s, vector<ll> &minDist){
    minDist.resize(n + 1, 1e18 + 7);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    minDist[s] = 0;
    pq.push({s, minDist[s]});
    while(pq.empty() == 0){
        int u = pq.top().se;
        ll dist = pq.top().fi;
        pq.pop();

        if(minDist[u] != dist) continue;
        for(pii it : graph[u]){
            int v = it.fi;
            int w = it.se;
            if(Min(minDist[v], minDist[u] + w)){
                pq.push({minDist[v], v});
            }
        }
    }
}
