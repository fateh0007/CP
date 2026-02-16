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
    vector<int> f(n);
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    vector<int> a(n);
    for(int i=1;i<n-1;i++){
        a[i] = (f[i-1]+f[i+1]-2*f[i])/2;
    }

    a[0] = f[n-1];
    for(int i=1;i<n;i++){
        a[0]-=(n-1-i)*a[i];
    }
    a[0]/=n-1;

    a[n-1] = f[0];
    for(int i=0;i<n-1;i++){
        a[n-1] -= i*a[i];
    }
    a[n-1]/=n-1;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
