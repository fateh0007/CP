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
    int a,b;
    cin>>a>>b;
    int xr = 0;
    if((a-1)%4==0){
        xr = a-1;
    }
    else if((a-1)%4==1) xr = 1;
    else if((a-1)%4==2){
        xr = a;
    }
    else{
        xr = 0;
    }
    if(a==1 && b==1){
        cout<<3<<endl;
        return;
    }
    // cout<<xr<<endl;
    if(xr==b){
        cout<<a<<endl;
        return;
    }
    else if((xr^b)!=a){
        cout<<a+1<<endl;
        return;
    }
    cout<<a+2<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
