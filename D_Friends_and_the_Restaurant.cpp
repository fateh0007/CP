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
    cin >> n;
    vector<int> x(n),y(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    vector<int> diff(n);
    for(int i=0;i<n;i++){
        diff[i] = y[i] - x[i];
    }
    sort(diff.begin(),diff.end());
    int cnt =0;
    int i=0;
    int j = n-1;
    while(i<j){
        int sum = diff[i] + diff[j];
        if(sum>=0){
            cnt++;
            i++;
            j--;
        }else{
            i++;
        }
    }
    cout<<cnt<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
