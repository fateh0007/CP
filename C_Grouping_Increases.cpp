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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans =0;
    int x = INT_MAX;
    int y = INT_MAX;
    for(int i=0;i<n;i++){
        if(x>y){
            swap(x,y);
        }
        if(a[i]<=x){
            x=a[i];
        }else if(a[i]<=y){
            y = a[i];
        }else{
            x= a[i];
            ans++;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
