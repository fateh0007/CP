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
    vector<int> b(n);
    map<int,vector<int> > mp;
    for(int i=0;i<n;i++){
        cin>>b[i];
        mp[b[i]-i+1].push_back(b[i]);
    }
    int sum = INT_MIN;
    for(auto it: mp){
        int s = 0;
        for(int x: it.second){
            s+=x;
        }
        sum = max(sum,s);
    }
    cout<<sum<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
