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
const int INF = LLONG_MAX;

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int i=0;int j = n-1;
    vector<int> res;
    while(i<=j){
        res.push_back(v[i]);
        res.push_back(v[j]);
        i++;
        j--;
    }
    bool check = true;
    int sum = res[0];
    for(int i=1;i<n;i++){
        if(res[i]==sum){
            check = false;
            break;
        }
        sum += res[i];
    }
    if(!check){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
