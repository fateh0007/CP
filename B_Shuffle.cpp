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
    int n,x,m;
    cin>>n>>x>>m;
    int ans = 1;
    int prevL = INT_MAX;
    int prevR = INT_MIN;
    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        if(x>=l&&x<=r && prevL==INT_MAX && prevR==INT_MIN){
            prevL = min(prevL,l);
            prevR = max(prevR,r);
            ans = prevR-prevL+1;
        }
        else if(prevL!=INT_MAX && prevR!=INT_MIN){
            if(max(prevL,l)<=min(prevR,r)){
                prevL = min(prevL,l);
                prevR = max(prevR,r);
                ans = prevR-prevL+1;
            }
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
