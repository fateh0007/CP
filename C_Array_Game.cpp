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
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(k>=3){
        cout<<0<<endl;
        return;
    }
    // sort(a.begin(),a.end());
    int mini = LLONG_MAX;
    for(int i=0;i<n;i++){
        mini = min(mini,a[i]);
    }
    vector<int> differences;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            differences.push_back(abs(a[i]-a[j]));
        }
    }
    sort(differences.begin(),differences.end());
    for(int i=0;i<n;i++){
        mini = min(mini,a[i]);
    }
    mini = min(mini,differences[0]);
    if(k==2){
        for(int i=0;i<n;i++){
            auto it = lower_bound(differences.begin(),differences.end(),a[i]);
            if(it!=differences.end()){
                mini = min(mini,abs(*it - a[i]));
            }
            if(it!=differences.begin()){
                --it;
                mini = min(mini,abs(*it-a[i]));
            }
        }
    }
    cout<<mini<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
