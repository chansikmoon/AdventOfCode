#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    vector<string> v;

    while (getline(cin, line))
    {
        if (line == "")
            break;
            
        v.push_back(line);
    }
    
    int ret = 0;
    
	for (int r = 1, c = 3; r < v.size(); r++, c += 3)
	{
		int n = v[r].size();
		if (v[r][c % n] == '#')
			ret++;
	}

	cout << ret << endl;
}
