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
int fact[200000];

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int totalAnd = a[0];
    for(int i=1;i<n;i++){
        totalAnd &= a[i];
    }
    int countAnd =0;
    for(int i=0;i<n;i++){
        if(a[i]==totalAnd) countAnd++;
    }
    if(countAnd<2){
        cout<<0<<endl;
        return;
    }
    cout<<1LL*countAnd*(countAnd-1)%mod*fact[n-2]%mod<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for(int i=1;i<=200000;i++){
        fact[i] = (1LL*fact[i-1]*i) % mod;
    }
    int t;
    cin>>t;
    while(t--) solve();
}
