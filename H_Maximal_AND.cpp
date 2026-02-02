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
    vector<int> bits(31,0);
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int x = a[i];
        for(int b=0;b<31;b++){
            if(x&1){
                bits[b]++;
            }
            x>>=1;
        }
    }
    for(int i=0;i<31;i++){
        bits[i] = n-bits[i];
    }
    
    int ans = 0;
    for(int i=30;i>=0;i--){
        if(bits[i]<=k){
            ans |= (1LL<<i);
            k-=bits[i];
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
