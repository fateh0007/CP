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
const int mod = 1e9 + 7;

int x,y,k;
bool check(int z){
    for(int i=0;i<x;i++) z-= (z/y);
    return z>=k;
}

void solve(){
    cin>>x>>y>>k;
    int l = 1, r = 1e12, ans = 1e12;
    if(!check(r)){
        cout<<-1<<endl;
        return;
    }
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l= mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
