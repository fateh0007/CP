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
int k;
int largest_divisor_le_k(int n, int k) {
    int ans = 1;
    for(int i=1;i*i<=n;i++) {
        if(n%i==0) {
            if(i<=k) ans = max(ans,i);
            if(n/i<=k) ans = max(ans,n/i);
        }
    }
    return ans;
}

void solve() {
    int n;
    cin>>n>>k;
    int ans = 1;
    if(k>=n){
        cout<<1<<endl;
    }else{
        int largest_divisor = largest_divisor_le_k(n,k);
        // cout<<largest_divisor<<endl;
        cout<<n/largest_divisor<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
