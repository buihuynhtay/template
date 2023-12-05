
vector<int> np;
vector<int> prime;

void Era(int n){
    np.resize(n + 1, 0);
    for(int i = 2; i * i <= n; i++){
        if(np[i]) continue;
        for(int j = i * i; j <= n; j += i){
            np[j] = i;
        }
    }
    np[1] = 1;
    for(int i = 2; i <= n; i++){
        if(np[i] == 0) np[i] = i, prime.pb(i);
    }
}
