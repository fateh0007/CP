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
//performing dfs on evernode

int cnt = 0;
int dfs(int u,map<int,vector<int> > &mp, string &s){
    int sum = (s[u-1]=='B'?1:-1);
    for(auto it: mp[u]){
        sum+=dfs(it,mp,s);
    }
    if(sum==0){
        cnt++;
    }
    return sum;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n-1);
    map<int,vector<int> > mp;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        mp[a[i]].push_back(i+2);
    }
    string s;
    cin>>s;
    cnt = 0;
    dfs(1,mp,s);
    cout<<cnt<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
