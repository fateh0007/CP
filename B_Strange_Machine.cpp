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
const int mod = 1e9+7;

int apply_op(char type, int x) {
    if (type == 'A') return x - 1;
    return x / 2;
}

void solve() {
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    bool hasB = false;
    int cntA = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            hasB = true;
        }else{
            cntA++;
        }
    }
    for (int i=0;i<q;i++){
        int a;
        cin>>a;
        int step = 0;
        int pos = 0;
        if(hasB==false){
            int res = a/(cntA);
            int rem = a%(cntA);
            int total_steps = (res * cntA)+rem;
            cout<<total_steps<<endl;
            continue;
        }
        while(a>0){
            if(s[pos]=='A'){
                a = a-1;
            }else{
                a = floor((double)a/2.0);
            }
            step++;
            pos = (pos+1)%(n);
        }
        cout<<step<<endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solve();
}