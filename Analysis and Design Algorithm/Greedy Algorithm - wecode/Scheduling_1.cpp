#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> x(n);
    vector<pair<long long,int>> jobs;

    for (long long i = 0; i < n; i++) {
        cin >> x[i];
        jobs.push_back({x[i],i});
    }

    sort(jobs.rbegin(),jobs.rend());
    vector<long long> Timesum(m, 0);
    vector<long long> y(n);

    for (long long i = 0; i < n; i++) {

        long long selection = 0;

        for (long long j = 1; j < m; j++) {
            if (Timesum[j] < Timesum[selection]) {
                selection = j;
            }
        }

        y[jobs[i].second] = selection;

        Timesum[selection] += jobs[i].first;
    }

    for (long long i = 0; i < n; i++) {
        cout << y[i] << " ";
    }

    return 0;
}
