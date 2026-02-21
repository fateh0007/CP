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
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.first!=b.first) return a.first<b.first;
    return a.second>b.second;
}
void solve(){
    int n;
    cin>>n;
    vector<int> u(n),s(n);
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++) cin>>u[i];
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<n;i++){
        v.push_back(make_pair(u[i],s[i]));
    }
    sort(v.begin(),v.end(),comp);
    map<int,vector<int> > mp;
    for(int i=0;i<n;i++){
        if(mp[v[i].first].size()==0) mp[v[i].first].push_back(v[i].second);
        else mp[v[i].first].push_back(mp[v[i].first].back()+v[i].second);
    }
    int maxSize = 0;
    for(auto &it: mp){
        int sz = it.second.size();
        maxSize= max(maxSize,sz);
    }
    vector<int> ans(n,0);
    for(auto &it: mp){
        int sz = it.second.size();
        for(int k=1;k<=sz;k++){
            int ind = it.second.size()%k;
            if(it.second.size()>=k){
                ans[k-1] += it.second[it.second.size()-1-ind];
            }else{
                break;
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
