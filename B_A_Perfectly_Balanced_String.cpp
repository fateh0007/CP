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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

void solve() {
    string s;
    cin>>s;
    set<int> st;
    for(int i=0;i<s.length();i++){
        st.insert(s[i]);
    }
    int unique_chars = st.size();
    st.clear();
    int i=0;
    int j=0;
    while(j<unique_chars && i<s.length()){
        st.insert(s[j]);
        j++;
    }
    bool flag = true;
    while(j<=s.size()){
        if(st.size()<unique_chars){
            flag = false;
            break;
        }
        st.erase(s[i]);
        st.insert(s[j]);
        i++;
        j++;
    }
    if(flag==false){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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
