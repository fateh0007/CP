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
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void solve() {
    string s;
    cin>>s;
    int n =s.size();
    bool doubleStar = false;
    for(int i=0;i<n-1;i++){
        if(s[i]!='<' && s[i+1]!='>'){
            doubleStar = true;
        }
    }
    if(doubleStar){
        cout<<-1<<endl;
        return;
    }
    int cntR = 0;
    int cntL = 0;
    for(int i=0;i<n;i++){
        if(s[i]=='>'){
            cntR++;
        }else if(s[i]=='<'){
            cntL++;
        }
    }
    cout<<n-min(cntR,cntL)<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
