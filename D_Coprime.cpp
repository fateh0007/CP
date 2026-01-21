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
#define int long long
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a[i]] = i;
    }
    vector<pair<int,int> > v;
    for(auto it: mp){
        v.push_back(make_pair(it.first,it.second));
    }
    int res = -1;
    for(int i=0;i<v.size();i++){
        for(int j=i;j<v.size();j++){
            if(gcd(v[i].first,v[j].first)==1){
                res = max(res,v[i].second+v[j].second+2);
            }
        }
    }
    cout<<res<<endl;
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
