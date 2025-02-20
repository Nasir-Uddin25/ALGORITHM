#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        
        unordered_map<int, int> pearl_count;
        int pearl;
        
        for (int i = 0; i < n; i++) {
            cin >> pearl;
            pearl_count[pearl]++; // Toggle count using XOR operation
        }
        
        for (const auto& pair : pearl_count) {
            if (pair.second == 1) { // If count is odd, it's the thief's pearl
                cout << pair.first << endl;
                break;
            }
        }
    }

    
    return 0;
}