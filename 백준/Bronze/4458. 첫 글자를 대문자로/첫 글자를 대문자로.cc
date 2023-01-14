#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
void
toUpper(string &str)
{
    if (str.length() == 0)
        return;
    str[0] = toupper(str[0]);
}
 
int
main(void)
{
    int n;
    string str;
    
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++)
    {
        getline(cin, str);
        toUpper(str);
        cout << str << "\n";
    }
    return 0;
}