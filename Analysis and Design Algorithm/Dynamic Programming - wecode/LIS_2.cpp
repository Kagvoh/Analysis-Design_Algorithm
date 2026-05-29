#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector <long long> A(n);
  vector <long long> dp(n,1);
  vector <long long> prev(n,-1);
  for (int i = 0; i < n; i++) cin >> A[i];

  for (int i = 1; i < n; i++){
    for (int j = 0; j < i; j++){
      if (A[j] < A[i] && dp[j] + 1 > dp[i]){
        dp[i] = dp[j] + 1;
        prev[i] = j;
      }
    }
  }

  int max = 0;
  for (int i = 1; i < n; i++){
    if (dp[max] < dp[i]) max = i;
  }

  vector<long long> kq;
  for (int i = max; i != -1; i = prev[i]){
    kq.push_back(A[i]);
  }
  reverse(kq.begin(), kq.end());
  
  cout << kq.size() << endl;
  for (long long x : kq) 
    cout << x << " ";

  return 0;
}