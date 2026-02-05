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
    int n;
    cin>>n;
    int k = n/2;
    int ans = 0;
    if(n%2==0){
        ans = (k+1)*(k+1);
    }else{
        ans = 2*(k+1)*(k+2);
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) solve();
}
