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
    int n,m;
    cin>>n>>m;
    int cnt2 = 0;
    int cnt5 = 0;
    int temp = n;
    while(temp%2==0){
        cnt2++;
        temp/=2;
    }
    while(temp%5==0){
        cnt5++;
        temp/=5;
    }
    int ans = 1;
    while(cnt2>cnt5 && ans*5<=m){
        ans*=5;
        cnt5++;
    }
    while(cnt5>cnt2 && ans*2<=m){
        ans*=2;
        cnt2++;
    }
    while(ans*10<=m){
        ans*=10;
    }
    ans *= (m/ans);
    cout<<ans*n<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
