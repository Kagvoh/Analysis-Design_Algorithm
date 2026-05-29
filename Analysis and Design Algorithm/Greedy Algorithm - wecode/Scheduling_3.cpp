#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, m;
  cin >> n >> m;

  vector<vector<int>> Jobs(m, vector<int>(n));
  for (int i = 0 ; i < m; i++){
    for(int j = 0; j < n; j++){
        cin >> Jobs[i][j];
    }
  }
  vector<long long> Timesum(m, 0);
  vector<int> y(n);

  for(int i = 0; i < n; i++){
    int mintime = 1e9;
    int selection;
    for(int j = 0 ; j < m; j++){
      if(Jobs[j][i] < 0) continue;
      if(mintime > Timesum[j] + Jobs[j][i]){ 
        mintime = Timesum[j] + Jobs[j][i];
        selection = j;
      }
    }

    y[i] = selection;
    Timesum[selection] += Jobs[selection][i];
  } 

  for(int x : y){
    cout << x << " ";
  }
  return 0;
}
