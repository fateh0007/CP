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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i++){
        if((a[i]<0&&a[i+1]>=0) && abs(a[i])>abs(a[i+1])){
            a[i] = -1*a[i];
            a[i+1] = -1*a[i+1];
        }else if(a[i]<0 && a[i+1]<0){
            a[i] = -1*a[i];
            a[i+1] = -1*a[i+1];
        }
    }
    int sum =0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<sum<<endl;
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
