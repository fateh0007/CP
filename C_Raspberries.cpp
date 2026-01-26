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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    int mini = INT_MAX;
    int even = 0;
    int odd = 0;
    bool flag = false;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%4==0){
            flag = true;
        }
        if(a[i]%2==0){
            even++;
        }else{
            odd++;
        }
    }
    if(k==2){
        if(even>0){
            cout<<0<<endl;
            return;
        }else{
            cout<<1<<endl;
            return;
        }
    }
    if(k==4){
        int ans;
        if(even>1 || flag){
            ans =0 ;
        }
        else if(even==1){
            ans = 1;
        }
        else{
            ans=2;
        }
        for(int i=0;i<n;i++){
            int multiple = ceil((double(a[i]))/k)*k;
            ans = min(ans,multiple - a[i]);
        }
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n;i++){
        int multiple = ceil((double(a[i]))/k)*k;
        mini = min(mini,multiple - a[i]);
    }
    cout<<mini<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
