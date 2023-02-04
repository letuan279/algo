#include <bits/stdc++.h>

using namespace std;
int n;
int c[30][30];
int visited[30];
int x[30];
int fo = 1000000;
int f = 0;
int cmin = 10000000;

void Try(int k)
{
    for (int v = 1; v <= n; ++v)
    {
        if (!visited[v] && !visited[v + n])
        {
            x[k] = v;         // x[1] = 1 x[3] = 2
            x[k + 1] = v + n; // x[2] = 3 x[4] = 4
            visited[v] = 1;
            visited[v + n] = 1;
            f = f + c[x[k - 1]][v] + c[v][v + n]; // c[0][1] + c[1][3] + c[3][2] + c[2][4]
            if (k == 2 * n - 1)
            {
                if (fo > f + c[v + n][0]) // c[0][1] + c[1][3] + c[3][0]
                {
                    fo = f + c[v + n][0];
                }
            }
            else
            {
                int g = f + ((2 * n - 1 - k) / 2 + 1) * cmin;
                if (g < fo)
                    Try(k + 2);
            }
            f = f - c[x[k - 1]][v] - c[v][v + n];
            x[k] = 0;
            x[k + 1] = 0;
            visited[v] = 0;
            visited[v + n] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < 2 * n + 1; ++i)
    {
        for (int j = 0; j < 2 * n + 1; ++j)
        {
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }

    Try(1);

    cout << fo;

    return 0;
}