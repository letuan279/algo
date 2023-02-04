#include <bits/stdc++.h>

using namespace std;

long long n;
vector<pair<long long, long long>> d;

bool comparePairs(const pair<long long, long long> a, const pair<long long, long long> b)
{
    return a.first < b.first ? true : (a.first == b.first ? a.second > b.second : false);
}

int main()
{
    cin >> n;
    long long ans = 0;
    for (long long i = 0; i < n; ++i)
    {
        long long p, q;
        cin >> p >> q;
        pair<long long, long long> PAIR1;
        PAIR1.first = p;
        PAIR1.second = q;
        d.push_back(PAIR1);
    }

    sort(d.begin(), d.end(), comparePairs);
    long long m = 0;
    long long size = d.size();
    long long last_time = d.at(size - 1).first;
    for (long long i = 0; i <= last_time && d.size() != 0; ++i)
    {
        // cout << d.at(0).first << " " << d.at(0).second << endl;
        if (i <= d.at(0).first)
        {
            ans += d.at(0).second;
            d.erase(d.begin());
        }
        else
        {
            while (i > d.at(0).first)
                d.erase(d.begin());
            ans += d.at(0).second;
            d.erase(d.begin());
        }
    }

    cout << ans;
    return 0;
}