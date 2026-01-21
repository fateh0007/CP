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
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<int> gap;
    for(int i=1;i<m;i++){
        gap.push_back(a[i]-a[i-1]-1);
    }
    gap.push_back(n-a[m-1]+a[0]-1);
    sort(gap.rbegin(),gap.rend());
    int sum = 0;
    int red = 0;
    // for(int i=0;i<gap.size();i++){
    //     cout<<gap[i]<<" ";
    // }
    // cout<<endl;
    int x =0 ;
    for(int i=0;i<gap.size();i++){
        if(gap[i]<=red) break;
        // cout<<gap[i]<<" ";
        if(gap[i]-red>1)sum+= gap[i]-1-red;
        else{
            sum+=1;
        }
        // cout<<sum<<" ";
        red+=4;
        x = red;
    }
    // cout<<endl;
    cout<<n-sum<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
