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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<vector<int> >  pos(n+1);
    for(int i=0;i<n;i++){
        pos[a[i]].push_back(i);
    }
    vector<int> ans(n,-1);
    for(int i=1;i<=n;i++){
        if(pos[i].size()==0) continue;
        int mx = pos[i][0] + 1;
        for(int j=1;j<(int)pos[i].size();j++){
            mx = max(mx,pos[i][j]-pos[i][j-1]);
        }
        mx = max(mx,n-pos[i].back());
        for(int j= mx-1;j<n;j++){
            if(ans[j]!=-1) break;
            ans[j] = i;
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) solve();
}