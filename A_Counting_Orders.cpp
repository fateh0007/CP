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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 1;
    int  j= n-1;
    for(int i=n-1;i>=0;i--){
        int lo= 0;
        int hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(a[mid]<=b[i]){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        j=lo;
        ans = (ans * (((n - j) - (n - 1 - i)) % mod)) % mod;
        if(ans==0) break;
    }
    cout<<ans%mod<<endl;
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
