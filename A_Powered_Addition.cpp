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
#include <numeric>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<int> b = a;
    sort(b.begin(),b.end());
    if(b==a){
        cout<<0<<endl;
        return;
    }
    int maxi = a[0];
    int x = 0;
    for(int i=1;i<n;i++){
        if(a[i]>=maxi){
            maxi = max(maxi,a[i]);
            continue;
        }
        int diff = maxi-a[i];
        int t= 0;
        while((1LL<<t)-1<diff) t++;
        x = max(x,t);
    }
    cout<<x<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}