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
    int n,c;
    cin>>n>>c;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        
    }
    int lo = 1;
    int hi = 1e9;
    int ans= 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        int sum = 0;
        for(int i=0;i<a.size();i++){
            int x= a[i] + 2*mid;
            x = x*x;
            sum+=x;
            if(sum>c) break;
        }
        if(sum==c){
            ans = mid;
            break;
        }
        else if(sum>c){
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
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
