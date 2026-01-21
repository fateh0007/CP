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
const int mod = 1e9 + 7;

bool possible(int mid, int x,vector<int> &a){
    int sum = 0;
    for(int i=0;i<a.size();i++){
        if(mid>a[i])sum+=mid-a[i]; 
    }
    return sum<=x;
}

void solve() {
    int n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[i] = make_pair(x,y);
    }
    if(k<=1){
        int x1 = v[a-1].first;
        int y1 = v[a-1].second;
        int x2 = v[b-1].first;
        int y2 = v[b-1].second;
        int dist = abs(x1-x2) + abs(y1-y2);
        cout<<dist<<endl;
        return;
    }
    if(a<=k && b<=k){
        cout<<0<<endl;
        return;
    }
    
    vector<pair<int,int> > dist1;
    vector<pair<int,int> > dist2;
    for(int i=0;i<k;i++){
        int x = abs(v[i].first - v[a-1].first);
        int y = abs(v[i].second - v[a-1].second);
        if(i!=a-1)dist1.push_back(make_pair(x+y,i));
    }
    // cout<<v[b-1].first<<" "<<v[b-1].second<<endl;
    // cout<<"-----------------"<<endl;
    for(int i=0;i<k;i++){
        
        int x = abs(v[i].first - v[b-1].first);
        int y = abs(v[i].second - v[b-1].second);
        // cout<<x<<" "<<y<<endl;
        if(i!=b-1)dist2.push_back(make_pair(x+y,i));
    }
    // cout<<dist1[0].first<<" "<<dist2[0].first<<endl;
    sort(dist1.begin(),dist1.end());
    sort(dist2.begin(),dist2.end());
    if(a<=k || b<=k){
        if(a<=k){
            cout<<dist2[0].first<<endl;
            return;
        }else{
            cout<<dist1[0].first<<endl;
            return;
        }
    }
    int d = abs(v[a-1].first - v[b-1].first) + abs(v[a-1].second - v[b-1].second);
    int ans = dist1[0].first + dist2[0].first;
    cout<<min(ans,d)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
