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
bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(isPalindrome(s)){
        cout<<0<<endl;
        return;
    }
    map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    } 
    map<char,int> possible;
    int mini = INT_MAX;
    int ans = INT_MAX;
    for(char ch = 'a';ch<='z';ch++){
        int i=0;
        int j = n-1;
        string t = s;
        int cnt =0;
        bool isPoss = true;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
                continue;
            }
            if(s[i]==ch){
                i++;
                cnt++;
            }
            else if(s[j]==ch){
                j--;
                cnt++;
            }else {
                isPoss = false;
                break;
            }
        }
        if(!isPoss){
            cnt = INT_MAX;
        }
        ans = min(ans,cnt);
    }
    if(ans==INT_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
