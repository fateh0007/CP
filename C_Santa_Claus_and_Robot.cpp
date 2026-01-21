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
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    if(n==0){ 
        cout<<0<<endl;
        return;
    }
    int segments = 1;
    int xsign = 0;
    int ysign = 0; 
    for(char c: s){
        if(c=='L' || c=='R'){
            int sign = (c=='L' ? -1 : 1);
            if(xsign==0) {
                xsign = sign;
            } else if(xsign != sign){
                segments++;
                xsign = sign;
                ysign = 0;
            }
        } else {
            int sign = (c=='D' ? -1 : 1);
            if(ysign==0) {
                ysign = sign;
            } else if(ysign != sign){
                segments++;
                ysign = sign;
                xsign = 0;
            }
        }
    }

    cout<<segments<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}
