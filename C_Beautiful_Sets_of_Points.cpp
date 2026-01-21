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
// #define int long long
const int mod = 1e9+7;
long long factorial(int n) {
    if (n < 0) {
        return -1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result = (result*i)%mod;
    }
    return result%mod;
}

vector<bool> generatePrimeSieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false; 

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}
long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b); 
}

string divide_with_ndigits(long long a, long long b, int n) {
    if (b == 0) throw runtime_error("division by zero");
    bool neg = ( (a < 0) ^ (b < 0) );
    a = llabs(a);
    b = llabs(b);

    long long intpart = a / b;
    long long rem = a % b;

    string res = (neg && (intpart != 0 || rem != 0)) ? "-" : "";
    res += to_string(intpart);
    if (n == 0) return res;

    res.push_back('.');
    for (int i = 0; i < n; ++i) {
        rem *= 10;
        int digit = rem / b;
        res.push_back(char('0' + digit));
        rem %= b;
    }
    return res;
}
  
int v[14] = {1,4,9,16,25,36,49,64,81,100,121,144,169,196};
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    int k = min(n, m) +1;
    cout<<k<<endl;
    for (int i=0;i<k;i++) {
        cout<<i<<" "<<(m-i)<<endl;
    }
    return 0;
    
    // vector<pair<int,int> > points;
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         points.push_back(make_pair(i,j));
    //     }
    // }
    // set<int> st;
    // for(int i=0;i<=13;i++){
    //     st.insert(v[i]);
    // }
    // set<pair<int,int> > ans;
    // for(int i=0;i<points.size();i++){
    //     for(int j=i+1;j<points.size();j++){
    //         int d = (points[i].first - points[j].first)*(points[i].first - points[j].first) + (points[i].second - points[j].second)*(points[i].second - points[j].second);
    //         if(st.find(d)!=st.end() && i+j>0){
    //             ans.insert(make_pair(points[i].first,points[i].second));
    //             ans.insert(make_pair(points[j].first,points[j].second));
    //         }
    //     }
    // }

    // cout<<ans.size()<<endl;
    // for(auto p:ans){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    // return 0;
}