typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define println(s) cout << s << "\n"
#define mp() make_pair()
#define PRIME_SIZE 5
#define PIE M_PIf64

#ifdef BOJ
#define debug(x)  ((void)0);
#define debug_value(x)  ((void)0);
#define fio cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false);
#else
#define debug(x)  cout << "[Debug] " << x;
#define debug_value(x)  cout << "[Debug] " << #x << " is " << x << '\n';
#define fio ((void)0);
#endif

#include <bits/stdc++.h>

using namespace std;

struct Direction {
    ll dx;
    ll dy;
};

struct Position {
    ll x;
    ll y;
};

ll fastpow(ll a, ll n, ll c){
    ll result=1;
    while(n){
        if(n&1){
            result *=a;
            if(result>=c) result%=c;
        }
        a*=a;
        if(a>=c) a%=c;
        n>>=1;
    }
    return result;
}

vector<ll> prime_list;
bool is_prime[PRIME_SIZE+1] = {1,1,0}; // 0이 소수
void siv(ll n) {
    for(int i = 2; i <= n; i++) {
        if(!is_prime[i]) prime_list.push_back(i);
        for(auto p : prime_list) {
            if(i*p > n) break;
            is_prime[i*p] = true;
            if(i%p == 0) break;
        }
    }
}

ll get_modulo(ll n, ll r) {
    return ((n % r) + r) % r;
}

ll f(ll x, ll y, ll t, ll n, ll m, ll o) {
    return abs((2*x + y + 4*o)/3 + 3*t +5*n + 4*m) + abs((2*y + x + 5*o)/3 + 3*t + 4*n + 5*m) + abs(3*n + t) + abs(3*m + t + o);
}

void solution(ll x, ll y) {
    x = abs(x);
    y = abs(y);

    ll temp1 = 2*x - y;
    ll temp2 = 2*y - x;

    ll a, b, c, d, o;

    ll pos[4][2] = {
        {-1e9, -1e9},
        {1e9, -1e9},
        {1e9, 1e9},
        {-1e9, 1e9}
    };

    for(int t = 0; t < 3; t++) {
        switch(get_modulo(temp1, 3)) {
            case 0: 
                o = 0;
                break;
            case 1:
                o = -1;
                break;
            case 2:
                o = 1;
                break;
        }


    }   
}

int main(int argc, char* argv[]) {
    fio;

    while(true){

        string s;
        getline(cin, s); // 한 줄 입력받기

        if(s.compare("END") == 0) {
            break;
        }
        ll x, y;
        stringstream ss(s);
        ss >> x >> y;

        solution(x, y);
    }

    return 0;
}
