#include <bits/stdc++.h>

using namespace std;

bool solve(string input)
{
	// https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c
	// \\s space and , -
	regex re{"[\\s,-]"};
	sregex_token_iterator it {input.begin(), input.end(), re, -1};
	vector<string> parts {it, {}};
	unordered_map<char, int> map;
	
	for (auto c : parts[3])
	{
		map[c]++;
	}
	
	return map[parts[2][0]] >= stoi(parts[0]) && map[parts[2][0]] <= stoi(parts[1]);
}


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    int ret;

    while (getline(cin, line))
    {
        if (line == "")
            break;
            
        if (solve(line))
        	ret++;
    }
    
    cout << ret << endl;
}
