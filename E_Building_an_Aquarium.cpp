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

bool possible(int mid, int x,vector<int> &a){
    int sum = 0;
    for(int i=0;i<a.size();i++){
        if(mid>a[i])sum+=mid-a[i]; 
    }
    return sum<=x;
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    int mini = LLONG_MAX;
    int maxi = LLONG_MIN;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        maxi = max(maxi,a[i]);
        mini = min(mini,a[i]);
    }
    int lo = mini;
    int hi = INT_MAX;
    int ans= 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(possible(mid,x,a)){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
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
