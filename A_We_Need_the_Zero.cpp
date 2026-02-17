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

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int xr = 0;
    for(int i=0;i<n;i++){
        xr^=a[i];
    }
    vector<int> b = a;
    for(int i=0;i<n;i++){
        b[i]^=xr;
    }
    int xr2 = 0;
    for(int i=0;i<n;i++){
        xr2^=b[i];
    }
    if(xr2!=0){
        cout<<-1<<endl;
        return;
    }
    cout<<xr<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
