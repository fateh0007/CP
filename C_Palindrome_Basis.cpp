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
int N = 40000;

bool isPalindromic(int n){
    string s = to_string(n);
    int i=0;int j = s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}


void solve(vector<int> &dp){
    int n;
    cin>>n;
    cout<<dp[n]<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> palindrome;
    for(int i=1;i<=N;i++){
        if(isPalindromic(i)) palindrome.push_back(i);
    }
    vector<int> dp(N+1,0);
    dp[0] = 1;
    for(int p: palindrome){
        for(int s=p;s<=N;s++){
            dp[s] = (dp[s]+dp[s-p])%mod;
        }
    }
    
    int t;
    cin>>t;
    while(t--) solve(dp);
}