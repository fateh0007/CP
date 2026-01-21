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
#include<numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    int n,q;
    cin >> n>>q;
    vector<int> a(51,n+1);
    for(int i=1;i<=n;i++){
        int color;
        cin>>color;
        if(a[color] == n+1){
            a[color] = i;
        }
    }
    while(q--){
        int color ;
        cin>>color;
        int ans = a[color];
        for(int i=1;i<=50;i++){
            if(a[i]<ans){
                a[i]++;
            }
        }
        a[color] = 1;
        cout<<ans<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin >> t;
    while (t--) solve();
}
