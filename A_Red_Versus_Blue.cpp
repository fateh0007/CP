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
    int n,r,b;
    cin>>n>>r>>b;
    string res = "";
    int x = b+1;
    // cout<<x<<endl;
    int extra = r%x;
    int cl = ceil((double)r/x);
    int fl = r/x;
    // cout<<extra<<endl;
    // cout<<cl<<" "<<fl<<endl;
    string t = "";
    string t2 = "";
    for(int i=0;i<cl;i++){
        t+="R";
    }
    for(int i=0;i<fl;i++){
        t2+="R";
    }
    while(extra>0){
        res+=t;
        res+="B";
        extra--;
        b--;
    }
    while(b>0){
        res+=t2;
        res+="B";
        b--;
    }
    res+=t2;
    cout<<res<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
