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
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    vector<int> px(n+1);
    px[1] = a[1];
    for(int i=2;i<=n;i++){
        px[i] = px[i-1]^a[i];
    }
    int xr0 = 0;
    int xr1 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            xr0 ^= a[i+1];
        }else{
            xr1^=a[i+1];
        }
    }
    int q;
    cin>>q;
    vector<int> ans;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            int rangeXor = px[r]^px[l-1];
            xr0 ^= rangeXor;
            xr1^=rangeXor;
        }
        else{
            int g;
            cin>>g;
            if(g==0){
                ans.push_back(xr0);
            }else{
                ans.push_back(xr1);
            }
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
