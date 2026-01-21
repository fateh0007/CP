#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {
    int a,b,n;
    cin>>a>>b>>n;
    if(n==1){
        cout<<1<<endl;
        return;
    }

    int x = (a/n);
    if(b>x){
        if(b>=a){
            cout<<1<<endl;
            return;
        }
        else {
            cout<<2<<endl;
            return;
        }
    }
    else cout<<1<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
