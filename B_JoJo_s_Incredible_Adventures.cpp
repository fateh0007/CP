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

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    string res = s+s;
    int cnt = 0;
    int maxi = 0;
    bool one = false;
    bool zeros = false;
    for(int i=0;i<res.size();i++){
        if(res[i]=='1'){
            cnt++;
            maxi = max(maxi,cnt);
            one  = true;
        }else{
            cnt = 0;
            zeros = true;
        }
    }
    if(zeros==true && one==false){
        cout<<0<<endl;
        return;
    }
    if(one==true && zeros==false){
        cout<<n*n<<endl;
        return;
    }
    if(maxi == 0){
        cout<<0<<endl;
        return;
    }
    if(maxi==1){
        cout<<1<<endl;
        return;
    }
    int x= 1;
    int ans = 0;
    while(x<=maxi){
        ans = x*maxi;
        x++;
        maxi--;
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
