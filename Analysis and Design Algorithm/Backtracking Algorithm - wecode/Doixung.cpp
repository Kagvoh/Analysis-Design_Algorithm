#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check(string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void Tachchuoi(int i, int n, string &s, vector<string> &A) {
    for (int j = i; j < n; j++) 
    {
        if (check(s, i, j))        
        {
            A.push_back(s.substr(i, j - i + 1));

            if (j < n - 1)
                Tachchuoi(j + 1, n, s, A);      
            else
            {
                for (string x : A) cout << x << " ";
                cout << endl;
            }

            A.pop_back();
        }
    }
}

int main() {
    string s;
    vector<string> A; 
    cin >> s;
    int n = s.length();
    Tachchuoi(0, n , s, A);
    return 0;
}