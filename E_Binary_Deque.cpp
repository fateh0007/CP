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
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==s){
        cout<<0<<endl;
        return;
    }
    if(sum<s){
        cout<<-1<<endl;
        return;
    }
    int i=0;
    int j=0;
    int currSum =0;
    int maxi = INT_MIN;
    while(j<n){
        currSum+=a[j];
        while(currSum>s){
            currSum-=a[i];
            i++;
        }
        if(currSum==s){
            maxi = max(maxi,j-i+1);
            
        }
        j++;
    }
    int ans= n-maxi;
    cout<<ans<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
