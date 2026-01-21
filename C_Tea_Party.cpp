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
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    int n,w;
    cin>>n>>w;
    vector<int> a(n);
    vector<int> half(n);
    vector<pair<int,int> > v(n);
    int sumHalf = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        half[i] = ceil((double)a[i]/2.0);
        sumHalf += half[i];
        v[i] = make_pair(a[i],i);
    }
    if(sumHalf>w){
        cout<<-1<<endl;
        return;
    }
    vector<int> res(n);
    sort(v.begin(),v.end());
    int sum =0 ;
    for(int i=0;i<n-1;i++){
        res[v[i].second] = half[v[i].second];
        sum+= half[v[i].second];
    }
    res[v[n-1].second] = min(w - sum, a[v[n-1].second]);
    sum+= res[v[n-1].second];
    int rem = w - sum;
    if(rem>0){
        for(int i=n-2;i>=0;i--){
            if(rem==0) break;
            int idx = v[i].second;
            int canAdd = a[idx] - res[idx];
            int toAdd = min(canAdd, rem);
            res[idx] += toAdd;
            rem -= toAdd;
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

    
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}