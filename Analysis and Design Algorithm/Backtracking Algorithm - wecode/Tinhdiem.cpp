// #include <iostream>
// #include <cmath>
// #include <vector>

// using namespace std;

// void Tinhdiem(int i, double sum, double X, vector<int> A, vector<double> &S){
//   for(double j = 0.25; j <= 10; j += 0.25){
//     if (round(sum) > X) break;
//     S[i] = j;
//     double newSum = sum + j*A[i]/100.0;
//     if(i == A.size() - 1){
//        if(round(newSum * 10) / 10 == X){
//           for(int k = 0; k < S.size(); k++){
//               if(S[k] == (int)S[k]) cout << (int)S[k] << " ";
//               else cout << S[k] << " ";
//           }
//           cout << endl;
//         }
//     }

//     else{
//       Tinhdiem(i+1,newSum,X,A,S);
//     }
//   }
// }

// int main(){
//   int n;
//   cin >> n;

//   vector<int> A(n);
//   for (int i = 0; i < n; i++) cin >> A[i];
  
//   double X; cin >> X;

//   double sum = 0;
//   vector<double> S(n);

//   Tinhdiem(0, sum, X, A, S);
//   return 0;
// }



#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void Tinhdiem(int i, long long sum, long long X, const vector<int>& A, vector<double>& S) {
    int n = A.size();
    int remain = 0;
    for(int k = i+1; k < n; k++)
        remain += A[k];

    for(int j = 25; j <= 1000; j += 25){

        long long newSum = sum + 1LL * j * A[i];

        if(newSum + 1LL * remain * 1000 < X - 500)
            continue;
            
        if(newSum + 1LL * remain * 25 >= X + 500)
            break;

        S[i] = j / 100.0;

        if(i == n - 1){

            if(newSum >= X - 500 && newSum < X + 500){

                for(int k = 0; k < n; k++){
                    if(S[k] == (int)S[k])
                        cout << (int)S[k];
                    else
                        cout << S[k];

                    if(k != n-1) cout << " ";
                }

                cout << endl;
            }
        }
        else{
            Tinhdiem(i+1, newSum, X, A, S);
        }
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> A(n);

    for(int i = 0; i < n; i++)
        cin >> A[i];

    double x;
    cin >> x;

    long long X = round(x * 10000);

    vector<double> S(n);

    Tinhdiem(0, 0, X, A, S);

    return 0;
}