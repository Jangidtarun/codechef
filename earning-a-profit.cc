#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a;
        cin >> n >> a;
        vector<int> c(n), d(n);
        for (int i = 0; i < n; i++)
            cin >> c[i] >> d[i];

        vector<int> psum_coins(n);
        psum_coins[0] = a;
        vector<int> psum_fuel_price(n);
        psum_fuel_price[0] = c[0];
        vector<int> msum_difficulty(n);
        msum_difficulty[0] = 0;
        vector<int> profit(n);
        for (int i = 1; i < n; i++)
        {
            psum_coins[i] = psum_coins[i - 1] + a;
            psum_fuel_price[i] = psum_fuel_price[i - 1] + c[i];
            int tmp_diff = pow(d[i] - d[i - 1], 2);
            bool isp = tmp_diff > msum_difficulty[i - 1];
            msum_difficulty[i] = isp ? tmp_diff : msum_difficulty[i - 1];
        }
        for (int i = 0; i < n; i++)
            profit[i] = psum_coins[i] - psum_fuel_price[i] - msum_difficulty[i];

        // cout << "psum_coins\n";
        // for (auto val : psum_coins)
        //     cout << val << " ";
        // cout << endl;
        // cout << "psum_fuel_price\n";
        // for (auto val : psum_fuel_price)
        //     cout << val << " ";
        // cout << endl;
        // cout << "msum_difficulty\n";
        // for (auto val : msum_difficulty)
        //     cout << val << " ";
        // cout << endl;
        // cout << "profit\n";
        // for (auto val : profit)
        //     cout << val << " ";
        // cout << endl;
        cout << *max_element(profit.begin(), profit.end()) << endl;
    }
}