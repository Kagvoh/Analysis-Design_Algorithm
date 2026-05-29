#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main(){
  int e;
  string s;
  cin >> e >> s;
  map<string, map<string, int>> A;
  set<string> dinh;

  for (int i = 0; i < e; i++){
    string u, v;
    int x;
    cin >> u >> v >> x;
    A[u][v] = x;
    dinh.insert(u);
    dinh.insert(v);
  }

  set<string> visited;
  vector<string> bestpath;

  string curr = s;
  visited.insert(curr);
  bestpath.push_back(curr);

  while(visited.size() < dinh.size()){
    string next = "";
    int minPath = 1e9;
    
    for(auto i : dinh){
      if(visited.count(i) == 0 && A[curr].count(i)){
        if (minPath > A[curr][i]){
          minPath = A[curr][i];
          next = i;
        }
      }
    }

    visited.insert(next);
    bestpath.push_back(next);
    curr = next; 
  }

  bestpath.push_back(s);

  for (auto i : bestpath) cout << i << " ";

  return 0;

}