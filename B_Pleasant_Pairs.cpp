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
   vector<pair<int,int> > a(n);
   for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i+1;
   } 
    sort(a.begin(),a.end());
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((a[i].first*a[j].first)>2*n) break;
            if(a[i].first*a[j].first==a[i].second + a[j].second){
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
