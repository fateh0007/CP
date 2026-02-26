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
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    if(k==1){
        cout<<b[n-1]-b[0]+1<<endl;
        return;
    }
    if(k==n){
        cout<<n<<endl;
        return;
    }
    vector<int> gap;
    for(int i=0;i<n-1;i++){
        gap.push_back(b[i+1]-b[i]);
    }
    sort(gap.rbegin(),gap.rend());
    map<int,int> gapsAvoided;
    for(int i=0;i<k-1;i++){
        gapsAvoided[gap[i]]++;
    }
    int prev = b[0];
    int ans = 0;
    for(int i=1;i<n;i++){
        int currGap = b[i]-b[i-1];
        if(gapsAvoided.find(currGap)!=gapsAvoided.end()){
            ans+=b[i-1]-prev+1;
            prev = b[i];
            gapsAvoided[currGap]--;
            if(gapsAvoided[currGap]==0) gapsAvoided.erase(currGap);
        }
    }
    ans+=b[n-1]-prev+1;
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
