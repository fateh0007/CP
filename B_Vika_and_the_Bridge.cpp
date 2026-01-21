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
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int> colours[k+1];
    for(int i=1;i<=k;i++){
        colours[i].push_back(0); 
    }
    for(int i=0;i<n;i++){
        colours[v[i]].push_back(i+1);
    }
    for(int i=1;i<=k;i++){
        colours[i].push_back(n+1);
    }
    priority_queue<int> jumps[k+1];
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        for(int j=0;j<colours[i].size()-1;j++){
            jumps[i].push(colours[i][j+1]-colours[i][j]-1); 
        }
        int maxi = jumps[i].top();
        jumps[i].pop();
        if(maxi%2==0){
            jumps[i].push(maxi/2);
            jumps[i].push((maxi/2)-1);
        }
        else{
            jumps[i].push(maxi/2);
            jumps[i].push(maxi/2);
        }
        ans = min(ans,jumps[i].top());
    }
    cout<<ans<<endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
