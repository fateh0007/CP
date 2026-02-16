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
const int INF = LLONG_MAX;

void solve(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<"YES"<<endl;
        return;
    }
    if(n%k==0 || n%2==0){
        cout<<"YES"<<endl;
        return;
    }
    int rem = n-k;
    if(rem%2==0){
        cout<<"YES"<<endl;
        return;
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
