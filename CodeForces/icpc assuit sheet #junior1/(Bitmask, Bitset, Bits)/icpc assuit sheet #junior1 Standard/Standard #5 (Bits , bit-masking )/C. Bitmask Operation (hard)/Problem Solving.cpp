#include <iostream>
#include <vector>
#define endl "\n"
#include <cmath>
#include<set>
#include<bitset>
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

void solve() {
    int q, n, query; cin >> n >> q;
    while (q--) {
        cin >> query;
        if (query == 1) {
            for (int i = 0; i < 32; i++) {
                if (knowBit(n, i) == 0) {
                    n = setBit(n, i);
                    break;
               }
          }
            cout << n << endl;
        }
        else if (query == 2) {
            for (int i = 0; i < 32; i++) {
                if (knowBit(n, i) == 1) {
                    n = resetBit(n, i);
                    break;
                }
            }
            cout << n << endl;
        }
        else if (query == 3) {
            if (n == 0) {
                n = -1;
            }
            else {
                for (int i = 0; i < 32; i++) {
                    if (knowBit(n, i) == 1) {
                        break;
                    }
                    n = setBit(n, i);
                }
            }
            cout << n << endl;
         }
            
        else if (query == 4) {
            for (int i = 0; i < 32; i++) {
                if (knowBit(n, i) == 0) {
                    break;
                }
                n = resetBit(n, i);
            }
            cout << n << endl;
        }
        else {
            bitset<32> bits(n);
            if (bits.count()==1) {
                cout << "is power of two" << endl;
            }
            else {
                cout << "not power of two" << endl;
            }
        }
    }

}
int main() {
    fast();
    solve();
}
