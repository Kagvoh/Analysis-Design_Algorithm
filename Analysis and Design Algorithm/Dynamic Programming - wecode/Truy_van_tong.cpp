#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, q;
  cin >> n >> q;
  vector<long long> tmp(n+1,0);
  vector<long long> A(n);

  for (int i = 0 ; i < n; i++){
    cin >> A[i];
    tmp[i+1] = tmp[i] + A[i];
  }

  while(q--){
    int a,b;
    cin >> a >> b;
    cout << tmp[b] - tmp[a-1] << endl;
  }
  
  return 0;
}