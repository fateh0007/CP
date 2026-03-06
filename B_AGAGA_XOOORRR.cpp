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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> suff(n),pref(n);
    suff[n-1] = a[n-1];
    pref[0] = a[0];
    for(int i=n-2;i>=0;i--){
        suff[i] = suff[i+1] ^ a[i];
    }
    for(int i=1;i<n;i++){
        pref[i] = a[i] ^ pref[i-1];
    }

    bool flag = true;
    for(int k=0;k<n-1;k++){
        int xr = 0;
        for(int i=k;i<n-1;i++){
            xr^=a[i];
            bool flag2 = true;
            if(k>0){
                if(!(pref[k-1] == xr)){
                    flag2 = false;
                }
            }
            // if(i+1<n){
                if(!(suff[i+1] == xr)){
                    flag2=false;
                }
            // }
            // for(int j=0;j<k;j++){
            //     if(xr!=a[j]){
            //         flag2 = false;
            //         break;
            //     }
            // }
            // for(int j=i+1;j<n;j++){
            //     if(xr!=a[j]){
            //         flag2 = false;
            //         break;
            //     }
            // }
            if(flag2==true){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}