#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> gia(n);
  vector<int> trang(n);

  for(int i = 0 ; i < n ; i++) cin >> gia[i];
  for(int i = 0 ; i < n ; i++) cin >> trang[i];

  vector<int> dp(x+1, 0);
  for(int i = 0 ; i < n ; i++){
    for( int j = x ; j >= gia[i]; j--){
      dp[j] = max (dp[j], dp[j - gia[i]] + trang[i]);
    }
  }

  cout << dp[x];

  return 0;
}