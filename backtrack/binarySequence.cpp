#include <bits/stdc++.h>

using namespace std;

int n = 3;
int x[4];
int sum = 5;

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

bool check()
{
    int newSum = 0;
    for (int i = 1; i <= n; i++)
    {
        newSum += x[i];
    }
    return sum == newSum;
}

void Try(int i)
{
    for (int j = 1; j <= 3; ++j)
    {
        x[i] = j;
        if (i == n)
        {
            if (check())
                solution();
        }
        else
        {
            Try(i + 1);
        }
        x[i] = 0;
    }
}

int main()
{
    Try(1);
    return 0;
}