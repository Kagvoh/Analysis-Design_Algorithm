#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

bool check (string u, int currcolor, map<string, set<string>>& ke, map<string,int> & pos, vector<int> &color){
  for(auto v : ke[u]){
    int idx = pos[v];
    if(color[idx] == currcolor) return 0;
  }
  return 1;
}

void Tomau(int k, vector<string> &dinh, map<string, set<string>> &ke, 
           map<string,int> &pos, vector<int> &color, vector<int> &bestselect,
           int totalcolor, int &bestcolor){

  if (totalcolor >= bestcolor) return;
  if (k == dinh.size()){
    bestcolor = totalcolor;
    bestselect = color;
    return;
  }

  string u = dinh[k];

  for(int h = 0; h <= totalcolor; h++){
    if(check(u,h,ke,pos,color)){
      color[k] = h;
      Tomau(k+1,dinh,ke,pos,color,bestselect,max(totalcolor, h + 1),bestcolor);
    }

    color[k] = -1;
  }
}

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
    string u, i;
    cin >> u >> i;
    ke[u].insert(i); 
    ke[i].insert(u);
  }
  

  vector<int> color(v,-1);
  vector<int> bestselect(v, -1);
  int bestcolor = 1e9;

  Tomau(0,dinh,ke,pos,color,bestselect,0,bestcolor);
  
  for(auto i : bestselect){
    cout << i << " ";
  }

  return 0;
}