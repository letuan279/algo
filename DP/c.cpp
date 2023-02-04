#include <bits/stdc++.h>

using namespace std;

unsigned long long k, n;
unsigned long long X[1000][1000];

unsigned long long C(unsigned long long k, unsigned long long n)
{
    if (k == 0)
        return 1;
    if (k == 1)
        return n;
    if (k == n)
        return 1;

    if (X[k][n])
        return X[k][n];

    X[k][n] = (C(k, n - 1) + C(k - 1, n - 1)) % (unsigned long long)1000000007;

    return X[k][n];
}

int main()
{
    cin >> k >> n;
    cout << C(k, n);
    return 0;
}