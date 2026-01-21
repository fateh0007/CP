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

int solve(unordered_map<string,int> &mp, string s) {
    if(s.length() <= 1) return 0;
    // if(s.size()==0) return 0;
    string one = s.substr(0,1) + s.substr(2);
    string two = s.substr(1);
    int cnt  = 0;
    if(mp.find(one) == mp.end()) {//nhi mila
        mp[one] = 1;
        cnt += 1 + solve (mp, one);
    }
    if(mp.find(two) == mp.end()) {
        mp[two] = 1;
        cnt += 1 + solve(mp, two);
    }
    return cnt;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    unordered_map<char,int> mp;
    int ans = 0;
    for(int i=0;i<n;i++){
        if(mp.find(s[i])==mp.end()){
            ans+=n-i;
            mp[s[i]]=1;
        }
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
