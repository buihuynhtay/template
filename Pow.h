ll Pow(ll x, ll exp){
    if(exp == 0) return 1;
    if(exp == 1) return x;
    ll t = Pow(x, exp/2);
    return exp&1 ? t * t % mod * x % mod : t * t % mod;
}
