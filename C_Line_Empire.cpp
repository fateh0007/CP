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

void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> x(n+1);
    x[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    vector<int> suff(n+2,0);
    suff[n] = x[n];
    for(int i=n-1;i>=1;i--){
        suff[i] = suff[i+1] + x[i];
    }
    int mini = LLONG_MAX;
    for(int i=0;i<=n;i++){
        int c = (a+b)*x[i] + b*(suff[i+1]-(n-i)*x[i]);
        mini = min(mini,c);
    }
    cout<<mini<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin>>t;
    while(t--) solve();
}