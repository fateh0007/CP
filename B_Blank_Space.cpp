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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin>>n;
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==0){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else if(x==1){
            cnt = 0;
        }
    }
    cout<<maxi<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
