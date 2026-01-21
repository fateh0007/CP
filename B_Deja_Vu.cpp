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
    int n,q;
    cin>>n>>q;
    vector<int> a(n),x(q);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        cin>>x[i];
    }
    int mini = LLONG_MAX;
    for(int i=0;i<q;i++){
        if(x[i]<mini){
            int power = pow(2,x[i]);
            int add = pow(2,x[i]-1);
            for(int j=0;j<n;j++){
                if(a[j]%power==0){
                    a[j]+=add;
                }
            }
            mini = min(mini,x[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;   
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
