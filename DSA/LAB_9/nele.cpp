#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        int k, q;
        cin >> k>>q;
        int a1;
        cin >> a1;
        for (int i = 1; i < k; i++) 
        {
            int dummy;
            cin >> dummy;
        }
        for (int i = 0; i < q; i++) 
        {
            int n;
            cin >> n;
            cout << (n < a1 ? n : a1 - 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}
