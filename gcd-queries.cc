#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            int gcd = 0;
            for (int j = 0; j < l - 1; j++)
                gcd = __gcd(gcd, v[j]);
            for (int j = r; j < n; j++)
                gcd = __gcd(gcd, v[j]);
            cout << gcd << endl;
        }
    }
}
