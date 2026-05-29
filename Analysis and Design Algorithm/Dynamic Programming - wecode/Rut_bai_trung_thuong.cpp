#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string n, m;
  cin >> n >> m;
  int a = n.size();
  int b = m.size();
  vector<vector<int>> dp(a+1,vector<int>(b+1,0));

  for (int i = 0; i <= a; ++i) dp[i][0] = i;
  for (int j = 0; j <= b; ++j) dp[0][j] = j;

  for (int i = 1 ; i <= a; i++){
    for(int j = 1; j <= b; j++){
      if (n[i-1] == m[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    }
  }
  cout << dp[a][b];
  return 0;
}