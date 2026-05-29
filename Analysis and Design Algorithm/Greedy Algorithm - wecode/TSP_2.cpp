#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){
  int e, n;
  cin >> e >> n;
  map<string, map<string, int>> A;

  for (int j = 0; j < e; j++){
    string u, i;
    int x;
    cin >> u >> i >> x;
    A[u][i] = x;
  }

  for (int k = 0; k < n; k++){
    string first , next;
    cin >> first;
    int sum = 0; 

    bool check = true;
    while(true){
      cin >> next;
      if (next == ".") break;
      if (A[first].count(next)) sum += A[first][next];
      else check = false;

      first = next;
    }

  if(check) cout << sum << endl;
  else cout << "FALSE\n"; 
  }

  return 0;
}