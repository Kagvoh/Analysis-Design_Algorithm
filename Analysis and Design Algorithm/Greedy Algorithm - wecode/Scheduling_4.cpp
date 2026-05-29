#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void PhanCong(int i, vector<long long> &TimeSum, vector<pair<long long, int>> &jobs, vector<long long> &CurrSelect,
              vector<long long> &BestSelect, long long &bestsum){
  int n = jobs.size();
  int m = TimeSum.size();

  if (i == n){
    long long maxsum = 0;
    for (int j = 0; j < m; j++){
      maxsum = max(maxsum, TimeSum[j]);
    }

    if (maxsum < bestsum){
      bestsum = maxsum;
      BestSelect = CurrSelect;
    }
    return;
  }

  for (int j = 0; j < m; j++){

    if (TimeSum[j] + jobs[i].first >= bestsum) continue;
      bool duplicated = false;
      for (int k = 0; k < j; k++) {
          if (TimeSum[k] == TimeSum[j]) {
              duplicated = true;
              break;
          }
      }
      if (duplicated) continue;
      
    TimeSum[j] += jobs[i].first;
    CurrSelect[jobs[i].second] = j;
    PhanCong(i+1,TimeSum,jobs,CurrSelect,BestSelect,bestsum);

    TimeSum[j] -= jobs[i].first;
  }
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<long long> x(n);
    vector<pair<long long,int>> jobs;

    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        cin >> x[i];
        jobs.push_back({x[i],i});
        sum += x[i];
    }

    sort(jobs.rbegin(),jobs.rend());
    vector<long long> Timesum(m, 0);
    vector<long long> CurrSelect(n);
    vector<long long> BestSelect(n);
    long long bestsum = LLONG_MAX; 

    vector<long long> tempTime(m, 0);
    for (int i = 0; i < n; i++) {
        int targetMachine = 0;
        for (int j = 1; j < m; j++) {
            if (tempTime[j] < tempTime[targetMachine]) targetMachine = j;
        }
        tempTime[targetMachine] += jobs[i].first;
        BestSelect[jobs[i].second] = targetMachine;
    }
    for (int j = 0; j < m; j++) {
        if (tempTime[j] > (bestsum == LLONG_MAX ? 0 : bestsum)) {} 
    }

    long long initialMax = 0;
    for(int j = 0; j < m; j++) if(tempTime[j] > initialMax) initialMax = tempTime[j];
    bestsum = initialMax;
    
    PhanCong(0, Timesum, jobs, CurrSelect, BestSelect, bestsum);

    for (long long i = 0; i < n; i++) {
        cout << BestSelect[i] << " ";
    }

    return 0;
}
