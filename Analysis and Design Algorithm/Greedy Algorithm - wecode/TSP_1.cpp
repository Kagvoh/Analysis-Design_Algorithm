#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int e;
    cin >> e;

    set<pair<string, string>> canh; 
    set<string> dinh;            

    for (int i = 0; i < e; i++) {
        string u, v;
        cin >> u >> v;

        canh.insert({u, v});  
        dinh.insert(u);
        dinh.insert(v);
    }

    int n = dinh.size();

    if ((int)canh.size() != n * (n - 1)) {
        cout << "FALSE";
        return 0;
    }

    for (auto u : dinh) {
        for (auto v : dinh) {
            if (u != v) {
                if (canh.count({u, v}) == 0) {
                    cout << "FALSE";
                    return 0;                
                }
            }
        }
    }

    cout << "TRUE";
    return 0;
}