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
int calc(vector<int> &v){
    sort(v.begin(),v.end());
    int pref = 0;
    int res = 0;
    for(int i=0;i<v.size();i++){
        res+= v[i]*i - pref;
        pref+=v[i];
    }
    return res;
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m));
    map<int,vector<pair<int,int> > > mp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            mp[a[i][j]].push_back(make_pair(i,j));
        }
    }
    int sum = 0;
    for(auto it: mp){
        vector<int> rows,cols;
        for(auto &p:it.second){
            rows.push_back(p.first);
            cols.push_back(p.second);
        }
        sum+= calc(rows);
        sum+=calc(cols);
    }
    cout<<sum<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
