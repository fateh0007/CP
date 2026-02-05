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
    int n,m;
    cin>>n>>m;
    vector<int> k(n);
    vector<int> c(m);
    priority_queue<int,vector<int>, greater<int> > pq;
    for(int i=0;i<n;i++) {
        cin>>k[i];
    }
    for(int i=0;i<m;i++) {
        cin>>c[i];
        pq.push(c[i]);
    }
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        if(k[i]-1<m){
            v.push_back(make_pair(k[i],c[k[i]-1]));
        }
    }
    sort(v.begin(),v.end());
    int sum = 0;
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i].first<<" "<<v[i].second<<endl;
    // }
    for(int i=n-1;i>=0;i--){
        if(!pq.empty() && pq.top()<v[i].second){
            sum+=pq.top();
            pq.pop();
        }else{
            sum+=v[i].second;
        }
    }
    cout<<sum<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
