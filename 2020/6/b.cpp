#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    unordered_map<char, int> map;
    int ret, numOfLine;

    while (getline(cin, line))
    {
    	if (line == "exit")
    		break;
        if (line == "")
        {
        	for (auto it = map.begin(); it != map.end(); it++)
        	{
        		if (it -> second == numOfLine)
        			ret++;
			}
			
			numOfLine = -1;
        	map.clear();
		}
		
		numOfLine++;
        for (auto c : line)
        	map[c]++;
    }

	cout << "result: " << ret << endl;
}
