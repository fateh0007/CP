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
using namespace std;
#define int long long
const int mod = 1e9+7;

void solve(){
    string s;
    cin>>s;
    int n = s.size();
    char firstChar = '#';
    for(int i=0;i<n;i++){
        if(s[i]!='?'){
            firstChar = s[i];
            break;
        }
    }
    // cout<<firstChar<<endl;
    if(firstChar=='#'){
        string ans = "";
        for(int i=0;i<n;i++){
            ans.push_back('0');
        }
        cout<<ans<<endl;
        return;
    }
    string ans = "";
    for(int i=0;i<n;i++){
        if(s[i]=='?'){
            ans.push_back(firstChar);
        }
        else if(s[i]!=firstChar && firstChar!='#'){
            firstChar = s[i];
            ans.push_back(s[i]);
        }
        else{
            ans.push_back(s[i]);
        }
    }
    cout<<ans<<endl;
}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}