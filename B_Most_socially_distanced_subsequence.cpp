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
    vector<int> p(n);
    int maxi = 0;
    int idx = -1;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(p[i]>maxi){
            maxi = p[i];
            idx = i;
        }
    }
    int i=0;
    int j=1;
    vector<int> temp;
    temp.push_back(p[i]);
    while(j<n){
        while(p[j]>p[j-1]){
            j++;
        }
        if(j<n&&j-1!=i)temp.push_back(p[j-1]);
        while(p[j]<p[j-1]){
            j++;
        }
        if(j<n)temp.push_back(p[j-1]);
    }
    if(temp.back()!=p[n-1])temp.push_back(p[n-1]);
    cout<<temp.size()<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
