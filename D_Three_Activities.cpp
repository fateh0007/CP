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

int helper(vector<pair<int,int> > a,vector<pair<int,int> > b,vector<pair<int,int> > c){
    int n = a.size();
    int x1 = a[n-1].first;
    int idx_a = a[n-1].second;
    int idx_b = -1;
    int x2 = 0;
    for(int i=n-1;i>=0;i--){
        if(b[i].second!=idx_a){
            x2 = b[i].first;
            idx_b  = b[i].second;
            break;
        }
    }
    int idx_c = -1;
    int x3 = 0;
    for(int i=n-1;i>=0;i--){
        if(c[i].second!=idx_a && c[i].second!=idx_b){
            x3 = c[i].first;
            idx_c  = c[i].second;
            break;
        }
    }
    int total1 = x1+x2+x3;
    int y1 = a[n-1].first;
    int idx_cc = -1;
    int y3 = 0;
    for(int i=n-1;i>=0;i--){
        if(c[i].second!=idx_a){
            y3 = c[i].first;
            idx_cc = c[i].second;
            break;
        }
    }
    int y2 = 0;
    int idx_bb= -1;
    for(int i= n-1;i>=0 ;i--){
        if(b[i].second!=idx_a && b[i].second!=idx_cc){
            y2 = b[i].first;
            idx_bb=b[i].second;
            break;
        }
    }
    int total2 = y1+y2+y3;
    return max(total1,total2);
}

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int> > a(n),b(n),c(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i] = make_pair(x,i);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b[i] = make_pair(x,i);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        c[i] = make_pair(x,i);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    int ans = 0;
    int maxi1 = helper(a,b,c);
    int maxi2 = helper(b,a,c);
    int maxi3 = helper(c,a,b);
    ans = max(maxi1,max(maxi2,maxi3));
    cout<<ans<<endl;
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
