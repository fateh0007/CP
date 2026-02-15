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

void helper(vector<int> &a,vector<int> &b){
    int n = a.size()-1;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vector<int> ind,cur,need;
        int x =i;
        while(x<=n&& !vis[x]){
            vis[x] = 1;
            ind.push_back(x);
            cur.push_back(a[x]);
            need.push_back(b[x]);
            x*=2;
        }
        sort(cur.begin(),cur.end());
        sort(need.begin(),need.end());
        if(cur!=need){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    vector<vector<int> > adj(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(2*i<=n){
            adj[i].push_back(2*i);
            adj[2*i].push_back(i);
        }
    }
    int sum = 0;
    for(int i=0;i<1000;i++){
        sum+=i;
    }
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vector<int> ind,cur;
            vector<int> q;
            q.push_back(i);
            vis[i] =  1;
            int head = 0;
            while(head<q.size()){
                int u = q[head++];
                ind.push_back(u);
                cur.push_back(a[u]);
                for(int v:adj[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push_back(v);
                    }
                }
            }

            sort(ind.begin(),ind.end());
            sort(cur.begin(),cur.end());
            if(cur!=ind){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
