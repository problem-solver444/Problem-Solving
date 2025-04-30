#include <iostream>
#include <vector>
#define endl "\n"
#include <cmath>
#include<set>
#include<bitset>
#include<algorithm>
#define all(v) v.begin(), v.end()
#define ll long long int
using namespace std;
const int sz = 9000000;
const int OO = 0x3f3f3f3f;
bool composite[sz + 1];
void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

// binary representation will be known in the program inside n  with & (00010000)left shift  while return 1 or 0 the number of bit 
bool knowBit(ll n, ll x) {
    return n & (1 << x);
}

ll setBit(ll n, ll x)//set bit to 1
{
    return n | (1 << x);
}

ll resetBit(ll n, ll x)//reset bit to 0
{
    return n & (~(1 << x));
}

ll resetBit2(ll n, ll x)//-1 has all of his bits 11111111   
{
    return n & (-1 ^ (1 << x));
}

ll flipBit(ll n, ll x) {
    return n ^ (1 << x);
}

bool ispoweroftwo(int n) {
    bitset<32> bits(n);
    return (bits.count() == 1);
}
void solve() {
    int n; cin >> n;
    vector<int>v1(n);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    int cnt = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int even = 0, odd = 0;
        for (int i = 0; i < n; i++) {
            if (knowBit(mask, i) == 1) {
                if (v1[i] & 1)
                {
                    odd++;
                }else
                {
                    even++;
                }
        }  
    }
        if (even > odd)
        {
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    fast();
    solve();
}
