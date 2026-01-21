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

vector<int> primeFactors(int x) {
    vector<int> f;
    for (int i=2;i*i<=x;i++) {
        if(x%i==0) {
            f.push_back(i);
            while(x%i==0)x/=i;
        }
    }
    if(x>1)f.push_back(x);
    return f;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    map<int,int> mp;
    int res = LLONG_MAX;
    for(int i=0;i<n;i++){
        int j=0;
        while(j<=2){
            int val = a[i]+j;
            int amt = j*1;
            vector<int> fact = primeFactors(val);
            for(int k=0;k<fact.size();k++){
                if(mp.find(fact[k])==mp.end()){
                    mp[fact[k]] = amt;
                }
                else if( mp[fact[k]] > amt){
                    mp[fact[k]] = amt;
                }
                else{
                    if(mp[fact[k]]+amt<res){
                        res = mp[fact[k]]+amt;
                    }
                }
            }
            j++;
        }
    }
    vector<int> p;
    for(auto &it:mp){
        p.push_back(it.first);
    }
    cout<<res<<endl;
}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}