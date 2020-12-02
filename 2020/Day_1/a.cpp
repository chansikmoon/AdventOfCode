#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    unordered_set<int> _set;

    while (getline(cin, line))
    {
        if (line == "")
            break;

        _set.insert(stoi(line));
    }

    for (auto x : _set)
    {
        auto got = _set.find(2020 - x);
        if (got != _set.end())
        {
            auto ret = x * *got;
            cout << x << " * " << *got << " : " << ret << endl;
            break;
        }
    }
}
