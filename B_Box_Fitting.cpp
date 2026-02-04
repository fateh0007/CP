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
    int n,w;
    cin>>n>>w;
    vector<int> cnt(21,0);
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        cnt[log2(x)]++;
    }
    int used = 0;
    int height = 0;
    while(used<n) {
        int rem=w;
        for(int i=20;i>=0;i--) {
            while(cnt[i]>0&&(1LL<<i)<=rem) {
                rem-=(1LL<<i);
                cnt[i]--;
                used++;
            }
        }
        height++;
    }
    cout<<height<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
