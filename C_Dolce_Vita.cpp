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

bool pf(long long val, int ind, int x, int mid)
{
	if (val + (1LL * (ind + 1) * (mid - 1)) <= x)
		return true;
	return false;
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> pre(n);
    sort(a.begin(),a.end());
    if(a[0]>x){
        cout<<0<<endl;
        return;
    }
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+a[i];
    }

    int y = 0;
    int cnt =0;
    for(int i=0;i<n;i++){
        int lo = 1;
        int hi = 1e9+5;
        int ans = 0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(pf(pre[i],i,x,mid)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        cnt+=(ans);
    }
    // cout<<endl;
    cout<<cnt<<endl;
    // int j = idx;
    // int xx = 0;
    // int cnt =0;
    // while(j>=0){
    //     int max_xx = (x - pre[j])/(j+1);
    //     if(max_xx<xx){
    //         j--;
    //         continue;
    //     }
    //     if(j<0) break;
    //     // else{
    //         cnt += j+1;
    //         xx++;
    //     // }
    // }
    // cout<<cnt<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
