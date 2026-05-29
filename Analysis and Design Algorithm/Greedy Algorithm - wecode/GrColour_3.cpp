#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

int main(){
  int v, e;
  cin >> v >> e;

  vector<string> dinh(v);
  map<string, set<string>> ke; 
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
  

  vector<int> mau(v,-1);

  for (auto x : dinh){
    int vitri = pos[x];
    set<int> cam;

    for (string y : ke[x]) {

        int idx = pos[y];

        if (mau[idx] != -1) {
            cam.insert(mau[idx]);
        }
    }

    int color = 0;
    while(cam.count(color)) color++;
    mau[vitri] = color;
  }
  
  for(auto i : mau){
    cout << i << " ";
  }

  return 0;
}