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
    char c;
    cin>>n>>c;
    string s;
    cin>>s;
    if(c=='g'){
        if(s.find('g')!=string::npos){
            cout<<0<<endl;
            return;
        }
    }
    s += s;
    int i=0;
    int len = 0;
    int idx1 = -1;
    while(i<2*n){
        if(s[i]==c){
            idx1 = i;
            while(i<2*n && s[i]!= 'g'){
                i++;
            }
            len = max(len,i-idx1);
        }
        i++;
    }
    cout<<len<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
