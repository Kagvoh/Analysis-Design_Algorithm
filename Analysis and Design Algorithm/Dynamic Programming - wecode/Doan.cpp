#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct do_an {
    int start, end;
    long long tinchi;
    
    bool operator < (const do_an& other) const {
        return end < other.end;
    }
};

int search(const vector<do_an>& da, int curr) {
    int l = 0, r = curr - 1, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (da[mid].end < da[curr].start) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector <do_an> da(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> da[i].start >> da[i].end >> da[i].tinchi;
    }
    
    sort(da.begin(), da.end());
    
    vector <long long> dp(n);

    for (int i = 0; i < n; ++i) {
        int prev = search(da, i);
        long long include = da[i].tinchi;
        if (prev != -1) include += dp[prev];
        long long exclude = (i > 0) ? dp[i - 1] : 0;
        dp[i] = max(include, exclude);
    }

    cout << dp[n - 1] << endl;
    
    return 0;
}