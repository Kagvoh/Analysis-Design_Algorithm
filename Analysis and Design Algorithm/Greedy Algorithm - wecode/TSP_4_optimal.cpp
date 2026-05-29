#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

void TSP(string curr, string start, map<string, map<string, int>>& A,
         set<string>& dinh, set<string>& visited, vector<string>& currpath,
         vector<string>& bestpath, int currcost, int& bestcost){

  if(currcost >= bestcost) return;

  if(visited.size() == dinh.size()){
    if(A[curr].count(start)){
      int totalcost = currcost + A[curr][start];
      if(totalcost < bestcost){
        bestcost = totalcost;
        bestpath = currpath;
        bestpath.push_back(start);
      }
    }
    return;
  }

  for (auto next : dinh){
    if (visited.count(next) == 0 && A[curr].count(next)){
      visited.insert(next);
      currpath.push_back(next);
      
      TSP(next,start,A,dinh,visited,currpath,bestpath, currcost+A[curr][next],bestcost);

      visited.erase(next);
      currpath.pop_back();
    }
  }
}

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
  vector<string> currpath;
  vector<string> bestpath;

  visited.insert(s);
  currpath.push_back(s);

  int bestcost = 1e9;

  TSP(s,s,A,dinh,visited,currpath,bestpath,0,bestcost);

  for (auto i : bestpath) cout << i << " ";

  return 0;

}