#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
  int v, e, n;
  cin >> v >> e >> n;

  vector<string> dinh(v);
  map<string, set<string>> ke; 
  vector<int> mau(v);
  vector<string> check(n);
  map<string,int> pos;

  for(int j = 0; j < v; j++){
    cin >> dinh[j];
    pos[dinh[j]] = j;
  }

  for (int j = 0 ; j < e; j++){
    string u,i;
    cin >> u >> i;
    ke[u].insert(i); 
    ke[i].insert(u);
  }

  for (int j = 0; j < v; j++){
    cin >> mau[j];
  }

  for(int j = 0 ; j < n; j++){
    cin >> check[j];
  }
  
  for (string u : check){
    int vitri= pos[u];
    int color = mau[vitri];
    set<int> maucam;

    for (string x : ke[u]){
      int id = pos[x];
      if(mau[id] != -1) maucam.insert(mau[id]);
    }

    if (color != -1 && maucam.count(color) == 0){
      cout << "TRUE\n";
      continue;
    }

    set<int> colorused;
    for (int x : mau){
      if(x != - 1) colorused.insert(x);
    }

    bool find = false;

    for (int x : colorused){
      if (maucam.count(x) == 0){
        cout << x << endl;
        find = true;
        break;
      }
    }

    if (!find){
      int m = 0;
      while (colorused.count(m)) m++;
      cout << m << endl;
    }
  }

  return 0;
}