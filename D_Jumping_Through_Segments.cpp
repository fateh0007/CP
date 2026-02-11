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

bool possible(int n,int k,vector<int> &segmentStart,vector<int> &segmentEnd){
    int currMinPos = 0;
    int currMaxPos = 0;
    for(int i=0;i<n;i++){
        currMaxPos += k;
        currMinPos -= k;

        int reachableStart= max(currMinPos,segmentStart[i]);
        int reachableEnd = min(currMaxPos,segmentEnd[i]);
        if(reachableStart>reachableEnd){
            return false;
        }
        currMaxPos = reachableEnd;
        currMinPos = reachableStart;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> segmentStart(n),segmentEnd(n);
    for(int i=0;i<n;i++){
        cin>>segmentStart[i]>>segmentEnd[i];
    }
    int lo = 0;
    int hi = 1e9;
    int ans = 0;
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(possible(n,mid,segmentStart, segmentEnd)){
            ans=mid;
            hi = mid-1;
        }else{
            lo= mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
}
