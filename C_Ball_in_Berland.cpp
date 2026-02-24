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

bool comp(pair<int,int> &a, pair<int,int> &b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}

void solve(){
    int a,b,k;
    cin>>a>>b>>k;
    vector<int> count1(a),count2(b);
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        count1[temp-1]++;
    }
    for(int i=0;i<k;i++){
        int temp;
        cin>>temp;
        count2[temp-1]++;
    }
    int ans = 1LL*k*(k-1)/2;
    for(int x:count1){
        ans-=x*(x-1)/2;
    }
    for(int x:count2){
        ans-=x*(x-1)/2;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
