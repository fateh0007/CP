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
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int left = -1;
    int right = -1;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]){
            left = i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]!=b[i]){
            right = i;
            break;
        }
    }
    if(left==-1 && right==-1){
        cout<<1<<" "<<n<<endl;
    }
    while(left>0 && b[left]>=b[left-1]){
        left--;
    }
    while(right<n-1 && b[right]<=b[right+1]){
        right++;
    }
    // for(int i=left;i>0;i--){
    //     if(i>0 && b[i]>=b[i-1]){
    //         left = i-1;
    //     }
    // }
    // for(int i=right;i<n-1;i++){
    //     if(i<n-1 && b[i]<=b[i+1]){
    //         right = i+1;
    //     }
    // }
    cout<<left+1<<" "<<right+1<<endl;
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
