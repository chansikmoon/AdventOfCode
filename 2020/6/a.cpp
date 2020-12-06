#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    unordered_set<char> _set;
    int ret;

    while (getline(cin, line))
    {
    	if (line == "exit")
    		break;
        if (line == "")
        {
        	ret += _set.size();
        	_set.clear();
		}
            
        for (auto c : line)
        {
        	_set.insert(c);
		}
    }

	cout << "result: " << ret << endl;
}
