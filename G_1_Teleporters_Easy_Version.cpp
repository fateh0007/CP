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
    int n,c;
    cin>>n>>c;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x+i+1);
    }
    sort(a.begin(),a.end());
    int cnt=0;
    int idx = 0;
    while(idx<n && c>=a[idx]){
        c = c - (a[idx]);
        cnt++;
        idx++;
    }
    cout<<cnt<<endl;
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
