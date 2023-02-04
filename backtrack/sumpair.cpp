#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int n, M;
int x[3];
int y[3];
int ans = 0;

void Try(int k)
{
    for (int i = 1; i <= n; ++i)
    {
        if (y[k - 1] < i)
        {
            x[k] = a[i];
            y[k] = i;
            if (k == 2)
            {
                if (x[1] + x[2] == M)
                    ans++;
            }
            else
                Try(k + 1);
            x[k] = 0;
            y[k] = 0;
        }
    }
}

int main()
{
    cin >> n >> M;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    Try(1);
    cout << ans;
    return 0;
}