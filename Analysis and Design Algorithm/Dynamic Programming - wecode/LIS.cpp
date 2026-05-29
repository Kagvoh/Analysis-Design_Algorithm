#include <iostream>
#include <vector>

using namespace std;

// int main(){
//   int n;
//   cin >> n;
//   vector <long long> A(n);
//   vector <long long> list(n,1);
//   for (int i = 0; i < n; i++) cin >> A[i];
//   long long kq = 1;

//   for (int i = 1; i < n; i++){
//     for (int j = 0; j < i; j++){
//       if (A[j] < A[i]){
//         list[i] = max (list[i], list[j] + 1);
//       }
//     }
//     kq = max(kq,list[i]);
//   }
//   cout << kq;

//   return 0;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<long long> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    
    vector<long long> kq; 
    
    for (int x : A) {
      auto it = lower_bound(kq.begin(), kq.end(), x);
      if (it == kq.end()) kq.push_back(x);
      else *it = x;         
    }

    cout << kq.size() << "\n";
    return 0;
}