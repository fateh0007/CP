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
    string s;
    cin>>s;
    int n = s.size();
    // cout<<n<<endl;
    if(n==1){
        cout<<1<<endl;
        return;
    }
    int cnt0= 0;
    int cnt1 = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            cnt0++;
        }else{
            cnt1++;
        }
    }
    int l = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='0' && cnt1>0){
            cnt1--;
            l++;
        }else if(s[i]=='1' && cnt0 >0){
            cnt0--;
            l++;
        }else{
            break;
        }
    }
    cout<<n-l<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
