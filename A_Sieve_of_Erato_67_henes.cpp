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
    map<int,int> mp;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    bool flag1 = false;
    bool flag2 = true;
    if(mp.find(67)!=mp.end()){
        flag1 = true;
    }
    if(flag1){
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
