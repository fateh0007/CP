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
    cin>>n;
    string s;
    cin>>s;
    set<char> st;
    vector<int> left(n);
    for(int i=0;i<n;i++){
        st.insert(s[i]);
        left[i] = st.size();
    }
    vector<int> right(n);
    st.clear();
    for(int i=n-1;i>=0;i--){
        st.insert(s[i]);
        right[i] = st.size();
    }
    int maxi = 0;
    for(int i=0;i<n-1;i++){
        maxi = max(maxi,left[i]+right[i+1]);
    }
    cout<<maxi<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
