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
    string a,b;
    cin>>a>>b;
    if(a==b){
        cout<<0<<endl;
        return;
    }
    int n = a.size();
    int m = b.size();
    int maxLenOfb = 0;
    for(int i=0;i<m;i++){
        string temp = "";
        for(int j=i;j<m;j++){
            temp+=b[j];
            if(a.find(temp)!=string::npos){
                int tempLen = temp.size();
                maxLenOfb = max(maxLenOfb,tempLen);
            }
        }
    }
    
    int ans1 = n-maxLenOfb + m-maxLenOfb;
    cout<<ans1<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
