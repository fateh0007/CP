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

void solve() {
    int n;
    cin>>n;
    int x= (n*(n-1))/2;
    vector<int> a(x);
    map<int,int> mp;
    vector<pair<int,int> > v;
    int maxi = INT_MIN;
    for(int i=0;i<x;i++){
        cin>>a[i];
        mp[a[i]]++;
        maxi = max(maxi,a[i]);
    }
    for(auto it:mp){
        v.push_back(make_pair(it.first,it.second));
    }
    sort(v.begin(),v.end());
    vector<int> res(n,INT_MAX);
    int idx = 0;
    int s = n;
    for(int i=0;i<v.size();i++){
        int freq = v[i].second;
        int val = v[i].first;
        while(freq>0){
            res[idx] = val;
            idx++;
            freq-= s-1;
            s--;
        }
    }
    
    for(int i=0;i<n;i++){
        if(res[i] == INT_MAX){
            res[i] = maxi;
        }
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
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
