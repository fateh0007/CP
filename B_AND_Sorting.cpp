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
    vector<int> b = a;
    sort(b.begin(),b.end());
    vector<int> res;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            res.push_back(a[i]);
        }
    }
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" "; 
    // }
    // cout<<endl;
    
    int andd = res[0];
    for(int i=1;i<res.size();i++){
        andd = andd & res[i];
    }
    cout<<andd<<endl;
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
