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

bool possible(vector<pair<int,vector<int> > > &v,int mid){
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<v[i].second.size();j++){
            if(v[i].second[j]<mid){
                mid+=1;
            }else{
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        vector<int> temp;
        for(int j=0;j<k;j++){
            int x;
            cin>>x;
            temp.push_back(x-j+1);
        }
        sort(temp.begin(),temp.end());
        v.push_back(make_pair(temp[k-1],k));
    }
    sort(v.begin(),v.end());
    int ans = v[0].first;
    int inc = v[0].second;
    for(int i=1;i<n;i++){
        ans = max(ans,v[i].first-inc);
        inc+= v[i].second;
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
