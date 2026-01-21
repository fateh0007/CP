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

void solve() {
    int n; 
    cin >> n;
    vector<int> b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    // sort(b.begin(),b.end());
    set<int> st;
    for(int i=0;i<n;i++){
        st.insert(b[i]);
    }
    cout<<st.size()<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
