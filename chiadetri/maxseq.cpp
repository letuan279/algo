#include <bits/stdc++.h>

using namespace std;

int a[1000001];
int n;

int maxLeftSub(int i, int j)
{
    int s = 0;
    int m = 0;
    for (int k = j; k >= i; k--)
    {
        s += a[k];
        m = max(m, s);
    }
    return m;
}

int maxRightSub(int i, int j)
{
    int s = 0;
    int m = 0;
    for (int k = i; k <= j; k++)
    {
        s += a[k];
        m = max(m, s);
    }
    return m;
}

int maxSub(int i, int j)
{
    if (i == j)
    {
        return a[i];
    }
    int mid = (i + j) / 2;
    int wL = maxSub(i, mid);
    int wR = maxSub(mid + 1, j);
    int maxL = maxLeftSub(i, mid);
    int maxR = maxRightSub(mid + 1, j);
    return max(max(wL, wR), (maxL + maxR));
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << maxSub(1, n);

    return 0;
}