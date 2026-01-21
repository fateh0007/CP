#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
#define int long long

void solve(){
    int n, task;
    cin >> n >> task;

    vector<int> server_finish_time(n, 0);
    vector<int> res(task, -1);

    for(int i = 0; i < task; ++i){
        int t, k, d;
        cin >> t >> k >> d;

        vector<int> available_servers_indices;
        for(int j = 0; j < n; ++j){
            if(server_finish_time[j] <= t){
                available_servers_indices.push_back(j);
                if(available_servers_indices.size() == k){
                    break;
                }
            }
        }

        if(available_servers_indices.size() < k){
            continue;
        }

        int sum = 0;
        int finish_time = t + d;
        
        for(int idx : available_servers_indices){
            sum += (idx + 1);
            server_finish_time[idx] = finish_time;
        }

        res[i] = sum;
    }

    for(int i = 0; i < task; ++i){
        cout << res[i] << endl;
    }
}
  
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t=1;
    while(t--){
        solve();
    }
}