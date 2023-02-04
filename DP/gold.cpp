#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1000001;

int n;
int a[N], b[N];
int L1, L2;
int dp[N];
int ans = 0;
int prevChoice = 0;

void Try(int k)
{
    for (int i = 0; i <= 1; ++i)
    {
        b[k] = i;
        if (i == 1)
        {
            if (prevChoice && k - prevChoice >= L1 && k - prevChoice <= L2)
            {
            }
            else
            {
            }
        }
        if (k == n)
        {
            for (int i = 1; i <= n; ++i)
            {
                cout << b[i] << " ";
            }
            cout << endl;
        }
        else
        {
            Try(k + 1);
        }
        b[k] = 0;
    }
}

int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    Try(1);
    return 0;
}
