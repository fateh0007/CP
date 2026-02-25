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
    vector<vector<int> >  adj(n);
    vector<bool> good(n);
    for(int i=0;i<n;i++){
        int parent,type;
        cin>>parent>>type;
        if(type==0) good[i] = true;
        if(parent!=-1){
            adj[parent-1].push_back(i);
        }
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(good[i]) continue;
        bool flag = true;
        for(auto x : adj[i]){
            if(good[x]) flag = false;
        }
        if(flag) ans.push_back(i+1);
    }
    if(ans.size()==0){
        cout<<-1<<endl;
        return;
    }
    else{
        // sort(ans.begin(),ans.end());
        for(auto x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
