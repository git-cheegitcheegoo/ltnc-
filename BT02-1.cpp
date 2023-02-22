#include <iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    for (int i=2; i<x; i++)
    {
        if (x%i==0) break;
        cout << "yes"; return 0;
    }
    cout << "no";
    return 0;
}
