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
    string s;
    cin>>s;
    int i=0,j=n-1;
    int cnt =0;
    while(i<=j){
        if(s[i]!=s[j]){
            i++;
            j--;
            cnt+=2;
        }else {
            break;
        }
    }
    cout<<n-cnt<<endl;
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
