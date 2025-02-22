#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string x;
        for (char c : s) {
            if (c != ' ') {
                x += c;
            }
        }
        sort(x.begin(), x.end());
        cout << x << endl;
    }
    return 0;
}
