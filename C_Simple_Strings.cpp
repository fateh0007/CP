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
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            for(char ch = 'a';ch<='z';ch++){
                if(s[i]!=ch){
                    if(i+2<n && ch!=s[i+2]){
                        s[i+1] = ch;
                        break;
                    }
                    else if(i+2==n){
                        s[i+1] = ch;
                        break;
                    }
                }
            }
        }
    }
    cout<<s<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--) solve();
}
