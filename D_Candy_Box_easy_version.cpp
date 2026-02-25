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
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    vector<pair<int,int> > v;
    for(auto it:mp){
        v.push_back(make_pair(it.second,it.first));
    }
    sort(v.rbegin(),v.rend());
    int maxSize = v[0].first;
    int i=1;
    int cnt = maxSize;
    while(i<v.size() && maxSize>0){
        maxSize = min(maxSize-1,v[i].first);
        cnt+=maxSize;
        i++;
    } 
    cout<<cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
