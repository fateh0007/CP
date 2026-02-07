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
    vector<pair<int,int> > v;
    int sum = 0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        sum+=x;
        v.push_back(make_pair(x,i+1));
    }
    sort(v.begin(),v.end());
    vector<int> indexes;
    for(int i=0;i<n;i++){
        int x = sum;
        x-=v[i].first;
        if(i<n-1 && 2*v[n-1].first==x){
            indexes.push_back(v[i].second);
        }
        if(i==n-1 && 2*v[n-2].first==x){
            indexes.push_back(v[i].second);
        }
    }
    if(indexes.size()==0){
        cout<<0<<endl;
        return;
    }
    cout<<indexes.size()<<endl;
    for(int i=0;i<indexes.size();i++){
        cout<<indexes[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) solve();
}
