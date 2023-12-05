ll Pow(ll x, ll exp){
    if(exp == 0) return 1;
    if(exp == 1) return x;
    ll t = Pow(x, exp/2);
    return exp&1 ? t * t % mod * x % mod : t * t % mod;
}

vector<ll> fac, ifac;

void iModulo(int n){
    fac.resize(n + 1, 1);
    iface.resize(n + 1);

    for(int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;

    ifac[n] = Pow(fac[n], mod - 2);
    for(int i = n; i >= 1; i--)
        ifac[i - 1] = ifac[i] * i % mod;
}

ll C(ll k, ll n){
    if(k > n) return 0;
    return fac[n] * ifac[n - k] % mod * ifac[k] % mod;
}
