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
#define int  long long 
const int mod = 1e9 + 7;

int msb_pos(long long x) {
    if (x == 0) return -1;
    int pos = 0;
    while (x > 1) {
        x >>= 1;
        pos++;
    }
    return pos;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>a[i];
        int pos = msb_pos(a[i]);
        mp[pos]++;
    }
    int cnt =0;
    for(auto it:mp){
        int c = it.second;
        cnt+= (c*(c-1))/2;
    }
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
