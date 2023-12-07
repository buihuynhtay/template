#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define BIT(mask, i) (((mask) >> (i)) & 1LL)
#define MASK(i) (1LL << (i))
#define Size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pll pair<long long, long long>
#define pii pair<int, int>
#define ll long long


template<class T1, class T2>
    bool Max(T1 &x, T2 y){
        if(x < y){x = y; return true;}
        return false;
    }
template<class T1, class T2>
    bool Min(T1 &x, T2 y){
        if(x > y){x = y; return true;}
        return false;
    }

const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const ll INF = 1e18 + 7;
const int N = 1e6 + 5;

#define task ""

const int test = 1000;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

ll Rand(ll l, ll r){
    return l + rd() % (r - l + 1);
}

void make_test(){
    ofstream inp("test.inp");
    inp.close();
}
int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= test; i++){
        make_test();
        system(task".exe");
        system(task"_trau.exe");
        if(system("fc test.out test.ans")){
            cout << "test " << i << " WA\n";
            return 0;
        }
        cout << "test " << i << " AC\n";
    }
    return 0;
}
