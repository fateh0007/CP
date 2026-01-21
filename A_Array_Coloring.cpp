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

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int> > a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += a[i].first;
    }
    for(int i=n-1;i>0;i--){
        if((i>0) && (a[i].second % 2) == (a[i-1].second % 2)){
            cout<<"NO"<<endl;
            return;
        }
    }
    // cout<<sum<<endl;
    cout<<"YES"<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
