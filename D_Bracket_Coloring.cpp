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
    string s;
    cin>>s;
    int col = 1;
    int cntOpen = 0;
    int cntClose = 0;
    bool flag = false;
    int x = 0;
    vector<int> bal(n);
    int mini = INT_MAX;
    int maxi = INT_MIN;
    bal[0] = s[0]=='('?1:-1;
    for(int i=1;i<n;i++){
        bal[i] = bal[i-1] + (s[i]=='('?1:-1);
    }
    if(bal[n-1]!=0){
        cout<<-1<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        mini = min(mini,bal[i]);
        maxi = max(maxi,bal[i]);
    }
    if(mini==0 || maxi == 0){
        cout<<1<<endl;
        for(int i=0;i<n;i++){
            cout<<1<<" ";
        }
        cout<<endl;
        return;
    }
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        if(bal[i]>0) ans[i] = 1;
        else if(bal[i]<0) ans[i] = 2;
        else ans[i] = (bal[i-1]>0)?1:2;
    }
    cout<<2<<endl;
    for(int i=0;i<n;i++){
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
