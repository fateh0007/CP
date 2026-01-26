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

void solve() {
    int n;
    cin>>n;
    vector<pair<int,int> >  a(n);
    int mini = INT_MAX;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> temp(m);
        for(int i=0;i<m;i++){
            cin>>temp[i];
        }
        sort(temp.begin(),temp.end());
        a[i] = make_pair(temp[0],temp[1]);
        mini = min(mini,temp[0]);
    }    
    // cout<<mini<<endl;
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum =0 ;
        for(int j=0;j<n;j++){
            if(i==j){
                sum+=mini;
            }else{
                sum+=a[j].second;
            }
        }
        maxi = max(maxi,sum);
    }
    cout<<maxi<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
