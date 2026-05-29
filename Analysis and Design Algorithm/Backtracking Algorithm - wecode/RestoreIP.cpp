  #include <iostream>
  #include <string>
  #include <vector>

  using namespace std;
  
    bool check(string tmp){
        if(tmp.size()>3 || tmp.size()==0) return false; 
        if(tmp.size()>1 && tmp[0]=='0')   return false; 
        if(tmp.size() && stoi(tmp)>255) return false; 
        return true;
    }

    void RestoreIP(vector<string>& store, string output, int ind, string s, int dots){
        if(dots == 3){
            if(check(s.substr(ind)))
                store.push_back(output + s.substr(ind));
            return;
        }
        int n = s.size();
        for(int i = ind; i < min(ind+3, n); i++){
            if(check(s.substr(ind, i-ind+1))){
                output.push_back(s[i]);
                output.push_back('.');
                RestoreIP(store, output, i+1, s, dots+1);
                output.pop_back();
            }
        }
    }

    int main(){
        string s;
        cin >> s;
        vector<string> store;
        string res;
        RestoreIP(store, res, 0, s, 0);
        for(string i : store) cout << i << endl;
        return 0;
    }