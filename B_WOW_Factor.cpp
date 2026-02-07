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
string t = "wow";

int helper(string &s,int i,int j,vector<vector<int> > &dp){
    if(j==t.size()){
        return 1;
    }
    if(i==s.size()) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int cnt = 0;
    if(s[i]==t[j]){
        cnt = helper(s,i+1,j+1,dp) + helper(s,i+1,j,dp);
    }else{
        cnt = helper(s,i+1,j,dp);
    }
    return dp[i][j] =  cnt;
}

void solve() {
    string s;
    cin>>s;
    int cnt =0 ;
    string newS = "";
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='v'&& s[i+1]=='v'){
            newS+="w";
        }
        else if(s[i]=='v'&& s[i+1]=='o'){
            continue;
        }else{
            newS+='o';
        }
    }
    int n = newS.size();
    vector<vector<int> > dp(n,vector<int>(3,-1));
    string temp = "";
    int ans = helper(newS,0,0,dp);
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) solve();
}
