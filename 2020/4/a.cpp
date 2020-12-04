#include <bits/stdc++.h>

using namespace std;
vector<string> keys {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};

vector<string> Read()
{
	string line, str;
	vector<string> ret;
	
	while (getline(cin, line))
    {
    	if (line == "exit")
    		break;
    	if (line == "")
    	{
    		ret.push_back(str);
    		str = "";
		}
    		
    	str.append(line);
    }
    
    return ret;
}

bool Search (string line)
{
	for (string key : keys)
	{
		auto found = line.find(key);
		
		if (found == string::npos)
			return false;
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
        
    int ret;
	vector<string> inputs = Read();
	
    for (auto input : inputs)
    {	
    	if (Search(input))
    		ret++;
	}

    cout << ret << endl;
}
