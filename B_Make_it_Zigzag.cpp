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
const int mod = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt = 0;
    int preMax = a[0];
    for(int i=1;i<n;i++){
        int idx = i+1;
        if(idx%2==0){
            a[i] = max(preMax,a[i]);
        }
        preMax = max(preMax,a[i]);
    }
    vector<int> temp = a;
    for(int i=0;i<n;i++){
        if(i%2==0){
            if(i>0){
                a[i] = min(a[i],a[i-1]-1);
            }if(i<n-1){
                a[i] = min(a[i],a[i+1]-1);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i%2==0){
            cnt+=temp[i] - a[i];
        }
    }
    cout<<cnt<<endl;
}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}