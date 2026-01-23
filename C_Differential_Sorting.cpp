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
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> b = a;
    vector<int> c = a;
    sort(b.begin(),b.end());
    if(b==a){
        cout<<0<<endl;
        return;
    }
    // sort(c.rbegin(),c.rend());
    // if(c==a){
    //     cout<<-1<<endl;
    //     return;
    // }
    
    vector<pair<int,pair<int,int> > > ans;
    for(int i=0;i<n-2;i++){
            a[i] = a[n-2]-a[n-1];
            ans.push_back(make_pair(i+1,make_pair(n-1,n)));
    }
    bool flag = true;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            flag = false;
            break;
        }
    }
    if(flag==false){
        cout<<-1<<endl;
        return;
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
