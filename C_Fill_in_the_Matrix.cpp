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

void solve() {
    int n,m; 
    cin >> n>>m;
    if(m==1){
        cout<<0<<endl;
        for(int i=0;i<n;i++){
            cout<<0<<endl;
        }
        return;
    }
    if(n==1){
        cout<<2<<endl;
        for(int i=0;i<m;i++){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    int x;
    if(n<=m-1) x = n+1;
    else x= m;
    cout<<x<<endl;
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (start + j) % m << " ";
        }
        cout <<endl;

        start++;
        if (start == m - 1) {
            start = 0;
        }       
    }
    // cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
