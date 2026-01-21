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
#define int long long 
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        v[i]=c-'0';
    }
    bool check = false;
    for(int i=1;i<n;i++){
        if(v[i]<v[i-1]){
            check = true;
            break;
        }
    }
    if(!check){
        cout<<"Bob"<<endl;
        return;
    }

    cout<<"Alice"<<endl;

    vector<int > ans;
    int p1=0;
    int p0=n-1;
    while(p1<p0){
        while(p1<n && v[p1]!=1) p1++;
        while(p0>=0 && v[p0]!=0) p0--;
        if(p1>=p0) break;
        ans.push_back(p1);
        ans.push_back(p0);
        p1++;
        p0--;
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i+1<<" ";
    cout<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
