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
    vector<pair<int,int> > a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i] = x;
        a[i] = make_pair(x,i+1);
    }
    sort(a.rbegin(),a.rend());
    vector<int> ans(n+1);
    ans[0] = 0;
    int x= 1;
    for(int i=0;i<n;i+=2){
        int idx = a[i].second;
        ans[idx] = -1* x;
        x++;
    }
    x= 1;
    for(int i=1;i<n;i+=2){
        int idx = a[i].second;
        ans[idx] = x;
        x++;
    }
    int sum =0 ;
    for(int i=0;i<n;i++){
        sum += b[i]*2*abs(ans[i+1]);
    }
    cout<<sum<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
