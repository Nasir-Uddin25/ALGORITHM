#include <bits/stdc++.h>
using namespace std;

bool pile_of_word(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;

    string sorteds1 = s1;
    string sorteds2 = s2;

    sort(sorteds1.begin(), sorteds1.end());
    sort(sorteds2.begin(), sorteds2.end());

    return sorteds1 == sorteds2;
}
int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
    
        if (pile_of_word(s1, s2))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


   
    return 0;
}