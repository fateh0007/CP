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

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        if(k<(n*(n-1)/2)){
            cout<<0<<endl;
        }
        int lo = 1;
        int hi = 6;
        int ans = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            int len = mid*(mid-1)/2;
            if(len<=k){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
        cout<<ans<<endl;
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            v[i] = i+1;
        }
        int lp = n;
        for(int i=n-ans;i<n;i++){
            v[i] = lp;
            lp--;
        } 
        // for(int i=0;i<n;i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        int curr = ans*(ans-1)/2;
        int rem = k-curr;
        if(rem<ans){
            swap(v[n-1],v[rem-1]);
        }
        
    }
}