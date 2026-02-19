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

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> cntSpace(n,0);
    cntSpace[0] = (s[0]=='.'?1:0);
    for(int i=1;i<n;i++){
        cntSpace[i] = cntSpace[i-1]+(s[i]=='.'?1:0);
    }
    if(cntSpace[n-1]==0 || cntSpace[n-1]==n){
        cout<<0<<endl;
        return;
    }
    vector<int> a;
    for(int i=0;i<n;i++){
        if(s[i]=='*') a.push_back(cntSpace[i]);
    }
    vector<int> pref(a.size()),suff(a.size());
    pref[0] = a[0];
    for(int i=1;i<a.size();i++){
        pref[i] = pref[i-1]+a[i];
    }
    suff[a.size()-1] = a[a.size()-1];
    for(int i=a.size()-2;i>=0;i--){
        suff[i] = suff[i+1]+a[i];
    }
    int res = 1e18;
    for(int i=0;i<a.size();i++){
        int sumLeft = (i-1>=0?pref[i-1]:0);
        int sumRight = (i+1<a.size()?suff[i+1]:0);
        int left = a[i]*i - sumLeft;
        int right = sumRight - a[i]*(a.size()-1-i);
        res = min(res,left+right);
    }
    cout<<res<<endl;
    // for(int i=0;i<a.size();i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
