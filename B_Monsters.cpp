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
    int n,k;
    cin>>n>>k;
    vector<pair<int,int> >a(n);
    map<int,vector<int> > mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i+1);
        x = x%k;
        if(x==0){
            x = k;
        }
        a[i] = make_pair(x,i+1);
    }
    
    sort(a.begin(),a.end(),[&](pair<long long, long long> a, pair<long long, long long> b) {
			if (a.first != b.first)
				return a.first > b.first;
			return a.second < b.second;
	});
    for(int i=0;i<n;i++){
        cout<<a[i].second<<" ";
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
