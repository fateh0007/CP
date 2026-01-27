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
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ways = 0;
    int i=0;
    int cnt =0;
    while(i<n){
        if(a[i]>q){
            cnt = 0;
            i++;
        }
        while(i<n && a[i]<=q){
            cnt++;
            i++;
        }
        if(cnt>=k){
            ways+= (cnt*(cnt+1)/2) - (((k-1)*(2*cnt-k+2))/2);
        }
    }
    cout<<ways<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
