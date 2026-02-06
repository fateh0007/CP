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
#define int  long long 
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]] = i;
    }
    vector<int> c(n,0);
    for(int i=0;i<n;i++){
        cin>>b[i];
        c[mp[b[i]]] = i;
    }
    int mx = c[0];
    int ans = 0;
    for(int i=1;i<n;i++){
        if(c[i]<mx){
            ans++;
        }
        mx = max(mx,c[i]);
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) solve();
}
