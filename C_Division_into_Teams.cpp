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
    int n;
    cin>>n;
    vector<int> a(n);
    vector<pair<int,int> > b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i] = make_pair(a[i],i+1);
    }
    sort(b.begin(),b.end());
    vector<pair<int,int> > x;
    vector<pair<int,int> > y;
    int sum_xi = 0;
    int sum_yi = 0;
    for(int i=0;i<n;i++){
        if(i%2==0){
            x.push_back(b[i]);
            sum_xi += b[i].first;
        }else{
            y.push_back(b[i]);
            sum_yi += b[i].first;
        }
    }
    if(abs(sum_xi - sum_yi)>b[n-1].first){
        cout<<-1<<endl;
        return;
    }
    cout<<x.size()<<endl;
    for(int i=0;i<x.size();i++){
        cout<<x[i].second<<" ";
    }
    cout<<endl;
    cout<<y.size()<<endl;
    for(int i=0;i<y.size();i++){
        cout<<y[i].second<<" ";
    }
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
