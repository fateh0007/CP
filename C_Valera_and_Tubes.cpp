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
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;//row,col

    if((k>n && k< m)||(k>m && k<n)){
        if(k>n && k< m){
            for(int i=1;i<=n;i++){
                cout<<n<<" ";
                for(int j=1;j<=n;j++){
                    cout<<j<<" "<<i<<" ";
                }
                cout<<endl;
            }
            int x = abs(n*m - n*n);
            cout<<x<<" ";
            bool flag = false;
            for(int i=n+1;i<=m;i++){
                if(flag==false){
                    for(int j=1;j<=n;j++){
                        cout<<j<<" "<<i<<" ";
                    }
                    flag = true;
                }
                else if(flag==true){
                    for(int j=n;j>=1;j--){
                        cout<<j<<" "<<i<<" ";
                    }
                    flag = false;
                }
                
            }
        }
        if(k>m && k< n){
            for(int i=1;i<=m;i++){
                cout<<m<<" ";
                for(int j=1;j<=m;j++){
                    cout<<i<<" "<<j<<" ";
                }
                cout<<endl;
            }
            int x = abs(n*m - m*m);
            cout<<x<<" ";
            bool flag = false;
            for(int i=m+1;i<=n;i++){
                if(flag==false){
                    for(int j=1;j<=m;j++){
                        cout<<i<<" "<<j<<" ";
                    }
                    flag = true;
                }
                else if(flag==true){
                    for(int j=m;j>=1;j--){
                        cout<<i<<" "<<j<<" ";
                    }
                    flag = false;
                }
            }
        }
    }
    else if(k==n || k==m){
        if(k==n){
            for(int i=1;i<=n;i++){
                cout<<m<<" ";
                for(int j=1;j<=m;j++){
                    cout<<i<<" "<<j<<" ";
                }
                cout<<endl;
            }
        }
        else if(k==m){
            for(int i=1;i<=m;i++){
                cout<<n<<" ";
                for(int j=1;j<=n;j++){
                    cout<<j<<" "<<i<<" ";
                }
                cout<<endl;
            }
        }

    }else if(k<n && k<m){
        for(int i=1;i<k;i++){
            cout<<m<<" ";
            for(int j=1;j<=m;j++){
                cout<<i<<" "<<j<<" ";
            }
            cout<<endl;
        }
        cout<< (n-k+1)*m <<" ";
        bool flag = false;
        for(int i=k;i<=n;i++){
            if(flag==false){
                for(int j=1;j<=m;j++){
                    cout<<i<<" "<<j<<" ";
                }
                flag = true;
            }
            else if(flag==true){
                for(int j=m;j>=1;j--){
                    cout<<i<<" "<<j<<" ";
                }
                flag = false;
            }
        }
        
    }else {
        int total = n * m;
        int cnt = 0;
        bool flag = false;
        int tube = 1;
        int printed = 0;

        for (int i = 1; i <= n; i++) {
            if (!flag) {
                for (int j = 1; j <= m; j++) {
                    if (cnt == 0) {
                        if (tube < k) cout << 2 << " "; 
                        else cout << total - 2*(k-1) << " ";
                    }
                    cout << i << " " << j << " ";
                    cnt++; printed++;
                    if ((tube < k && cnt == 2) || (tube == k && printed == total)) {
                        cout << "\n";
                        cnt = 0;
                        tube++;
                    }
                }
                flag = true;
            } else {
                for (int j = m; j >= 1; j--) {
                    if (cnt == 0) {
                        if (tube < k) cout << 2 << " ";
                        else cout << total - 2*(k-1) << " ";
                    }
                    cout << i << " " << j << " ";
                    cnt++; printed++;
                    if ((tube < k && cnt == 2) || (tube == k && printed == total)) {
                        cout << "\n";
                        cnt = 0;
                        tube++;
                    }
                }
                flag = false;
            }
        }
    } 
}