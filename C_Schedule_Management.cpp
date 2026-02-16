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
#include <numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int INF = LLONG_MAX;
bool possible(int n,int t,int m,vector<int> &fr){
    int maxPoss = 0;
    for(int i=0;i<n;i++){
        if(t<fr[i]){
            maxPoss+=t;
        }else{
            maxPoss += fr[i] + (t-fr[i])/2;
        }
    }
    return maxPoss>=m;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> tasks(m);
    vector<int> fr(n,0);
    for(int i=0;i<m;i++){
        cin>>tasks[i];
        fr[tasks[i]-1]++;
    }
    int lo = 0;
    int hi = 2*m;
    int ans = 0;
    while(lo<hi){
        int mid = lo + (hi-lo)/2;
        if(possible(n,mid,m,fr)){
            ans = mid;
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
