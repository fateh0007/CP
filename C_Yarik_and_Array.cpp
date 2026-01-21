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
    int sum = a[0];
    int maxSum = sum;
    for(int i=1;i<n;i++){
        if(sum<0){
            sum = 0;
        }
        if((a[i]%2==a[i-1]%2)||(a[i]%2)!=0&&a[i-1]%2!=0){
            sum = a[i];
            maxSum = max(maxSum,sum);
        }
        else{
            sum+=a[i];
            maxSum = max(maxSum,sum);
        }
    }
    cout<<maxSum<<endl;
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
