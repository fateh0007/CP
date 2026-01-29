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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m));
    int cntNeg = 0;
    int absSum = 0;
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            absSum+=abs(a[i][j]);
            mini = min(mini,abs(a[i][j]));
            if(a[i][j]<=0){
                cntNeg++;
            }
        }
    }
    if(cntNeg%2==0){
        cout<<absSum<<endl;
        return;
    }
    // cout<<absSum<<endl;
    int res = absSum-2*mini;
    cout<<res<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
