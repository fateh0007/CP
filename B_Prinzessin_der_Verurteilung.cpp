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
#define int long long 
const int mod = 1e9 + 7;

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    queue<string> q;
    for(char ch = 'a';ch<='z';ch++){
        string t = "";
        t+=ch;
        q.push(t);
    }
    while(!q.empty()){
        string curr = q.front();
        q.pop();
        if(s.find(curr)==string::npos){
            cout<<curr<<endl;
            return;
        }
        for(char c='a';c<='z';c++){
            string next = curr + c;
            q.push(next);
        }
    }
}



signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
