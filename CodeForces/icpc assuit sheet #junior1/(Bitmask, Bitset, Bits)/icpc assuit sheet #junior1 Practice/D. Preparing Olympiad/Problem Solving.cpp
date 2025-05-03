#include <iostream>
#include <vector>
#define endl "\n"
#include <cmath>
#include <set>
#include <bitset>
#include <algorithm>
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

bool knowBit(ll n, ll x) {
    return n & (1 << x);
}

ll setBitto1(ll n, ll x) {
    return n | (1 << x);
}

ll resetBitto0(ll n, ll x) {
    return n & (~(1 << x));
}

ll resetBit2(ll n, ll x) {
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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> difficulties(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> difficulties[i];
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        int total = 0, mn = 1e9, mx = 0, numChosen = 0;
        for (int i = 0; i < n; i++) {
            if (knowBit(mask, i)) {
                total += difficulties[i];
                mn = min(mn, difficulties[i]);
                mx = max(mx, difficulties[i]);
                numChosen++;
            }
        }
        if (numChosen >= 2 && total >= l && total <= r && (mx - mn) >= x) {
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    fast();
    solve();
}
