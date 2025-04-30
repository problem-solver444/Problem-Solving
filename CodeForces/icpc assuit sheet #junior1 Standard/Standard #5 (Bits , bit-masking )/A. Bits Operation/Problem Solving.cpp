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
void solve() {
    ll n, q; cin >> q >> n;
    while (q--) {
        ll type, x; cin >> type;
        if (type == 1) {
            cin >> x;
            n |= x;
            cout << n << endl;
        }
        else if (type == 2) {
            cin >> x;
            n &= x;
            cout << n << endl;
        }
        else if (type == 3) {
            cin >> x;
            n ^= x;
            cout << n << endl;
        }
        else {
            n = ~n;
            cout << n << endl;
        }
    }

}
int main() {
    fast();
    solve();
}
