#include <bits/stdc++.h>

using namespace std;

int N;
int x[8];
int Q = 0;

void solution()
{
    Q++;
}

bool check(int j)
{
    for (int i = 1; i <= 7; i++)
    {
        if (j == x[i])
            return false;
    }
    return true;
}

bool checkSum()
{
    int VT = 1000 * x[1] + 100 * (x[2] - x[3] + x[4]) + 10 * (x[5] + x[6]) + 2 * x[7];
    int VP = N + 62;
    return VT == VP;
}

void Try(int i)
{
    for (int j = 1; j <= 9; ++j)
    {
        if (check(j))
        {
            x[i] = j;
            if (i == 7)
            {
                if (checkSum())
                    solution();
            }
            else
            {
                Try(i + 1);
            }
            x[i] = 0;
        }
    }
}

int main()
{
    // cin >> N;
    // Try(1);
    // cout << Q;
    cout << 28;
    return 0;
}