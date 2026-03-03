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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+b[i];
    }
    vector<int> cnt(n+2,0),ans(n+1,0);
    for(int i=1;i<=n;i++){
        int x = a[i] + pre[i-1];
        auto j = upper_bound(pre.begin(),pre.end(),x) - pre.begin();
        if(j<=n){
            ans[j] += x-pre[j-1];//partial sum
        }
        cnt[i]++;
        cnt[j]--;
    }
    for(int i=1;i<=n;i++){
        cnt[i]+=cnt[i-1];
        ans[i] += cnt[i]*b[i];
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
