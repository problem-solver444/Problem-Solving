#include <iostream>
#include <vector>
#define endl "\n"
#include <cmath>
#include<set>
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

ll setBit(ll n, ll x) {
    return n | (1 << x);
}

ll resetBit(ll n, ll x) {
    return n & (~(1 << x));
}

ll resetBit2(ll n, ll x)//-1 has all of his bits 11111111   
{
    return n & (-1 ^ (1 << x));
}

ll flipBit(ll n, ll x) {
    return n ^ (1 << x);
}

void solve() {
    ll q, n, x, query; cin >> q >> n;
    while (q--) {
        cin >> query >> x;
        if (query == 1) {
            cout << knowBit(n, x) << endl;
        }
        else if (query == 2) {
            n = setBit(n, x);
            cout << n << endl;
        }
        else if (query == 3) {
            n = resetBit(n, x);
            cout << n << endl;
        }
        else {
            n = flipBit(n, x);
            cout << n << endl;
        }
    }

}
int main() {
    fast();
    solve();
}
