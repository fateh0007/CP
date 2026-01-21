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
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt =0;
    if(n==1){
        cout<<n<<endl;
        return;
    }
    vector<int> ans;
    ans.push_back(a[0]);
    for(int i=1;i<n;i++){
        if((a[i]<a[i-1] && (i<n-1 && a[i]>a[i+1])) || (a[i]>a[i-1] && (i<n-1 && a[i]<a[i+1]))){
            cnt++;
        }
        else if(a[i]==a[i-1]) cnt++;
        else ans.push_back(a[i]);
    }
    // for(int i=0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    
    int x =0;
    for(int i=1;i<ans.size()-1;i++){
        if((ans[i]<ans[i-1] && (ans[i]>ans[i+1]&&i<ans.size()-1)) || (ans[i]>ans[i-1] && (ans[i]<ans[i+1] && i<ans.size()-1))){
            x++;
        }
    }
    // cout<<endl;
    cout<<ans.size()-x<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
