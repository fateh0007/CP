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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> pre(n,0);
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1]+a[i];
    }
    double x = 0;
    double sum = 0;
    for(int i=k-1;i<n;i++){
        if(i==k-1){
            sum+=pre[i];
            x++;
        }else{
            sum+=pre[i]-pre[i-k];
            x++;
        }
    }
    // cout<<x<<endl;
    //setpreciosn upto 6
    double ans = sum/x;
    cout<<fixed<<setprecision(6)<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
