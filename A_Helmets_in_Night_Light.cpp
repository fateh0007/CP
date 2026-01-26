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
    int n,p;
    cin>>n>>p;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    vector<pair<int,int> >  v(n);
    for(int i=0;i<n;i++){
        v[i] = make_pair(b[i],a[i]);
    }
    sort(v.begin(),v.end());
    int minCost = p;
    int alreadyShared=1;
    for(auto it: v){
        int canShare = it.second;
        int sharingCost = it.first;
        if(sharingCost>=p){
            break;
        }
        if(alreadyShared+canShare>n){
            minCost += (n-alreadyShared)*sharingCost;
            alreadyShared = n;
            break;
        }else{
            minCost+=canShare*sharingCost;
            alreadyShared+=canShare;
        }
    }
    minCost+=(n-alreadyShared)*p;
    cout<<minCost<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
