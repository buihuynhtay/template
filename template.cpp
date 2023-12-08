#include<bits/stdc++.h>

#define fi first
#define se second
#define Size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define BIT(mask, i) (((mask) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

using namespace std;
using pii = pair<int,int>;
using pll = pair<long long, long long>;
using ll = long long;

void __print(int x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void _print(){cerr << "]\n";}

template<typename T, typename V>
    void __print(const pair<T, V> &x){
        cerr << '{';
        __print(x.first);
        cerr << ',';
        __print(x.second);
        cerr << '}';
    }

template<typename T>
    void __print(const T &x){
        int f = 0;
        cerr << '{';
        for (auto &i: x)
            cerr << (f++ ? "," : ""), __print(i);
        cerr << "}";
    }

template<typename T>
    void Debug(string name, const T &x, int sz){
        cerr << "[" << name << "] = [";
        vector<int> ar;
        for(int i = 0; i <= sz; i++)
            ar.push_back(x[i]);
        __print(ar);
        _print();
    }

template <typename T, typename... V>
    void _print(T t, V... v){
        __print(t);
        if (sizeof...(v))
            cerr << ", ";
        _print(v...);
    }

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

template<class X, class Y>
    bool Min(X &x, const Y &y){
        if (x > y){ x = y; return true;}
        return false;
    }

template<class X, class Y>
    bool Max(X &x, const Y &y){
        if (x < y){ x = y; return true;}
        return false;
    }

const ll mod = 1e9 + 7;

template<class X, class Y>
    void add(X &x, const Y &y){
        x = (x + y);
        if(x >= mod) x -= mod;
    }

template<class X, class Y>
    void sub(X &x, const Y &y){
        x = (x - y);
        if(x < 0) x += mod;
    }

/** Author : Bui Huynh Tay, Binh Dinh **/

const ll inf = 1e9 + 7;
const int N = 1e6 + 10;

void babifish(){

}

signed main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #define task ""
    if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}

	#define task "test"
    if(fopen(task".inp", "r")){
		freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
	}

    int test = 1;
    bool multitest = 1;
    if(multitest) cin >> test;

    while(test--){
        babifish();
    }

    return 0;
}
