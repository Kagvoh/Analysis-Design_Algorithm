#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int pos , int i, int j, string &word, vector<vector<char>> &A, vector<vector<bool>> &visited){
  char c = A[i][j];
  if(visited[i][j]) return false;
  if(pos >= word.size() || c != word[pos]) return false;
  if(pos == word.size() - 1 && c == word[pos]) return true;

  pos++;
  visited[i][j] = true;
  if( i + 1 < A.size() && check(pos, i + 1, j , word, A , visited)) return true;
  if( i - 1 >= 0 && check(pos, i - 1, j , word, A , visited)) return true;
  if( j + 1 < A[0].size() && check(pos, i, j + 1, word, A , visited)) return true;
  if( j - 1 >= 0 && check(pos, i, j - 1 , word, A , visited)) return true;
  if (i + 1 < A.size() && j + 1 < A[0].size() && check(pos, i+1, j+1, word, A, visited)) return true;
  if (i + 1 < A.size() && j - 1 >= 0 && check(pos, i+1, j-1, word, A, visited)) return true;
  if (i - 1 >= 0 && j + 1 < A[0].size() && check(pos, i-1, j+1, word, A, visited)) return true;
  if (i - 1 >= 0 && j - 1 >= 0 && check(pos, i-1, j-1, word, A, visited)) return true;

  visited[i][j] = false;
  return false;
}

bool TimTu(string &word, vector<vector<char>> &A){
  vector<vector<bool>> visited (A.size(), vector<bool>(A[0].size(), false));
  for (int i = 0; i < A.size(); i++){
    for(int j = 0; j < A[0].size(); j++){
      if(check(0, i, j, word, A, visited)) return true;
    }
  }
  return false;
}

int main(){
  string word;
  cin >> word;
  vector<vector<char>> A; 
  string line;
  while (cin >> line) {
    if (line == ".") break;
    A.push_back(vector<char>(line.begin(), line.end()));
  }

  if (TimTu(word, A)) cout << "true";
  else cout << "false"; 

  return 0;
}