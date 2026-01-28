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
    vector<int> s(n);
    map<int,int> mp;
    vector<pair<int,int> > p;
    for(int i=0;i<n;i++){
        cin>>s[i];
        mp[s[i]]++;
        p.push_back(make_pair(s[i],i+1));
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        if(mp[s[i]]==1){
            flag = false;
        }
    }
    if(flag==false){
        cout<<-1<<endl;
        return;
    }
    sort(p.begin(),p.end());
    int idx = 0;
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        if(i==n-1){
            ans[p[i].second]=idx+1;
            break;
        }
        if(p[i].first==p[i+1].first){
            ans[p[i].second]=p[i+1].second;
        }else{
            ans[p[i].second] = idx+1;
            idx = i+1;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
