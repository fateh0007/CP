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
    int n;
    cin>>n;
    vector<int> a(n);
    int cnt =0 ;
    vector<long long> bits(32, 0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        int x = a[i];
        for (int j = 0; j < 32; j++) {
            if ((x >> j) & 1) {
                bits[j]++;
            }
        }
    }
    cout<<1<<" ";
    for(int i=2;i<=n;i++){
        bool flag = true;
        for(int j=0;j<32;j++){
            if(bits[j]%i!=0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
