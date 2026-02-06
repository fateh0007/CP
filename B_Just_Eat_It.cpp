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
    vector<int> a(n);
    int sum =0 ;
    int ans = 0;
    int sum2 = 0;
    int size = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=0;i<n-1;i++){
        sum2+=a[i];
        if(sum2<0){
            sum2 = 0;
        }
        ans= max(ans,sum2);
    }
    sum2 = 0;
    for(int i=1;i<n;i++){
        sum2+=a[i];
        if(sum2<0){
            sum2 = 0;
        }
        ans= max(ans,sum2);
    }
    // cout<<sum<<" "<<ans<<endl;
    // if(flag==false){
    //     if(a[0]==0 || a[n-1]==0){
    //         cout<<"NO"<<endl;
    //     }
    //     else cout<<"YES"<<endl;
    // }
    if(sum>ans){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
