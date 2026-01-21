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
    vector<vector<int> >  v(n,vector<int>(n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='0') v[i][j]=0;
            else v[i][j]=1;
        }
    }
    
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int one =0 ;
            int zero = 0;
            if(v[i][j]==0) zero++;
            else one++;

            if(v[j][n-i-1]==0)zero++;
            else one++;

            if(v[n-i-1][n-j-1]==0)zero++;
            else one++;

            if(v[n-j-1][i]==0)zero++;
            else one++;

            if(zero==0 || one ==0) continue;

            if(zero>=one){
                ans+=one;
                v[i][j]=0;
                v[j][n-i-1]=0;
                v[n-i-1][n-j-1]=0;
                v[n-j-1][i]=0;
            }else{
                ans+=zero;
                v[i][j]=1;
                v[j][n-i-1]=1;
                v[n-i-1][n-j-1]=1;
                v[n-j-1][i]=1;
            }
        }
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
