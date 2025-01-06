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

vector<vector<array<ll, 4>>> chess_board(33, vector<array<ll, 4>>(33));
array<array<bool, 33>, 33> visited;

int direc[10][2] = {
    {1, 2},
    {-1, -2},
    {2, 1},
    {-2, -1},
    {2, -1},
    {-2, 1},
    {1, -2},
    {-1, 2}
};

void preset() {
    int x = 16, y = 16;
    
    queue<array<int, 3>> q;

    q.push({x,y,1});
    chess_board[16][16] = {0,0,0,0};
    visited[16][16] = true;
    

    for(int i = 0; true; i++) {
        auto [cur_x, cur_y, count] = q.front();

        // cout << cur_x << " " << cur_y << "\n";

        if(count == 9) {
            break;
        }
        q.pop();

        for(int j = 0; j < 8; j++) {
            int next_x = cur_x + direc[j][0];
            int next_y = cur_y + direc[j][1];
            if(!visited[next_x][next_y]) {
                q.push({next_x, next_y, count+1});
                visited[next_x][next_y] = true;
                chess_board[next_x][next_y] = chess_board[cur_x][cur_y];
                if(j %2)
                    --chess_board[next_x][next_y][j/2];
                else 
                    ++chess_board[next_x][next_y][j/2];
                // cout << (next_x-16) << " " << (next_y-16) << ": " << chess_board[next_x][next_y][0] << " " << chess_board[next_x][next_y][1] << " " << chess_board[next_x][next_y][2] << " " << chess_board[next_x][next_y][3] << "\n";
            }
        }
    }

    chess_board[16][16][0] = 0;
}

int main(int argc, char* argv[]) {
    fio; 

    // preset();

    while(true){

        string s;
        getline(cin, s); // 한 줄 입력받기

        if(s.compare("END") == 0) {
            break;
        }
        ll x, y;
        stringstream ss(s);
        ss >> x >> y;

        x = abs(x);
        y = abs(y);

        ll temp1 = 2*x - y;
        ll temp2 = 2*y - x;

        ll result = LONG_LONG_MAX;

        for(int i = -1; i <= 1; i++) {
            ll temp_result = 0;
            for(int j = -1; j <= 1; j++) {
                ll p = temp1 + 5*i + 4*j;
                ll q = temp2 - 4*i - 5*j;

                if(p % 3 == 0 && q % 3 == 0) {
                    // cout << p << " " << q << " " << i << " " << j << "\n";
                    temp_result = abs(p)/3 + abs(q)/3 + abs(i) + abs(j);
                    result = min(result, temp_result);
                }
            }
        }

        cout << result << "\n";

        
    }

    return 0;
}
