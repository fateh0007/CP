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
    int n;
    cin>>n;
    vector<int> a(n);
    int asum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> pre(n);
    pre[0] = a[0];
    for(int i=1;i<n;i++){
        pre[i] = pre[i-1] + a[i];
    }
    int maxDiff = 0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            int mini = LLONG_MAX;
            int maxi = LLONG_MIN;
            for(int j=i-1;j<n;j+=i){
                int sum = pre[j];
                if(j>i-1) sum -= pre[j-i];
                mini = min(mini,sum);
                maxi = max(maxi,sum);
            }
            maxDiff = max(maxDiff,maxi-mini);
        }
    }
    cout<<maxDiff<<endl;
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
