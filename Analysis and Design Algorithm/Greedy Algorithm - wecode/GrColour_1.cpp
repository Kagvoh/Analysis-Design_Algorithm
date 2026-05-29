#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

// int main(){
//   int v, e;
//   cin >> v >> e;
//   vector<string> dinh(v);
//   map<string,int> idx;

//   for (int i = 0; i < v; i++){
//     cin >> dinh[i];
//     idx[dinh[i]] = i;
//   } 

//   vector<vector<int>> matrix(v,vector<int>(v,0));

//   for (int j = 0; j < e; j++){
//     string u, i;
//     cin >> u >> i;
//     int x = idx[u];
//     int y = idx[i];

//     matrix[x][y] = 1;
//     matrix[y][x] = 1;
//   }

//   for (int j = 0; j < v; j++){
//     int deg = 0;
//     for (int k = 0 ; k < v; k++){
//       deg += matrix[j][k];
//     }
//     cout << deg << " ";
//   }

//   return 0;
// }

int main(){
    int v, e;
    cin >> v >> e;

    map<string, set<string>> A;
    vector<string> dinh; 

    for (int i = 0; i < v; i++){
        string u;
        cin >> u;
        A[u];
        dinh.push_back(u);
    }

    for (int j = 0; j < e; j++){
        string u, i;
        cin >> u >> i;
        A[u].insert(i);
        A[i].insert(u);
    }

    for (auto u : dinh){
        cout << A[u].size() << " ";
    }

    return 0;
}
