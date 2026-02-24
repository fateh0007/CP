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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x%k;
        if(a[i]!=0) mp[a[i]]++;
    }
    int x = 1;
    while(!mp.empty()){
        vector<int> temp;
        for(auto it = mp.rbegin();it!=mp.rend();++it){
            if((it->first+x)%k!=0){
                int r = (it->first+x)%k;
                int need = k-r;
                x+=need;
                temp.push_back(it->first);
                x++;
            }else{
                temp.push_back(it->first);
                x++;
            }
        }
        for(int x: temp){
            mp[x]--;
            if(mp[x]==0){
                mp.erase(x);
            }
        }
    }
    if(x==1){
        cout<<0<<endl;
        return;
    }
    cout<<x<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
