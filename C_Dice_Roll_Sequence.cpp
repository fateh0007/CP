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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    mp[1] = 6;
    mp[2] = 5;
    mp[3] = 4;
    mp[4] = 3;
    mp[5] = 2;
    mp[6] = 1;
    int cnt =0;
    int i=1;
    while(i<n){
        if(a[i]==a[i-1] || a[i]==mp[a[i-1]]){
            cnt++;
            i+=2;
        }else{
            i++;
        }
    }
    cout<<cnt<<endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
