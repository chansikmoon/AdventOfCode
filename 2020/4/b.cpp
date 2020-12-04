#include <bits/stdc++.h>

using namespace std;
vector<string> keys {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
regex hairRegex{"^#([a-f0-9]{6})$"};
regex passportRegex{"^([0-9]{9})$"};
set<string> eyeColor {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

bool CheckNumRange(int num, int min, int max)
{
	return num >= min && num <= max;
}

bool CheckYear(string key, string str, int minYear, int maxYear)
{
	int year = stoi(str);
	return str.size() == 4 && CheckNumRange(stoi(str), minYear, maxYear);
}

bool CheckHeight(string str)
{
	int n = str.size();
	if (n < 4)
		return false;
		
	int height = stoi(str.substr(0, n - 2));
	string unit = str.substr(n - 2, 2);
	
	if (unit != "cm" && unit != "in")
		return false;
	
	return unit == "cm" ? CheckNumRange(height, 150, 193) : CheckNumRange(height, 59, 76);
}

bool CheckHairColor(string str)
{
	return regex_match(str, hairRegex);
}

bool CheckEyeColor(string str)
{
	return eyeColor.find(str) != eyeColor.end();
}

bool CheckPassport(string str)
{
	return regex_match(str, passportRegex);
}

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
    	
    	str += line + " ";
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

bool CheckConditions(string str)
{
	if (str[0] == ' ')
		str = str.substr(1);

	unordered_map<string, string> map;
	
	vector<string> splitBySpace;
	string s;
	
	for (auto c : str)
	{
		if (c == ' ')
		{
			splitBySpace.push_back(s);
			s = "";
		}
		else
		{
			s += c;
		}
	}
	
	s = "";
	
	for (auto field : splitBySpace)
	{
		auto found = field.find(':');
		string key = field.substr(found - 3, 3);
		string value = field.substr(found + 1);
		
		map[key] = value;
	}
	
	return CheckYear("byr", map["byr"], 1920, 2002) && CheckYear("iyr", map["iyr"], 2010, 2020) && 
		CheckYear("eyr", map["eyr"], 2020, 2030) && CheckHeight(map["hgt"]) && CheckHairColor(map["hcl"]) && 
		CheckEyeColor(map["ecl"]) && CheckPassport(map["pid"]);
}


int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
        
    int ret;
	vector<string> inputs = Read();
	
    for (auto input : inputs)
    {
    	if (Search(input) && CheckConditions(input))
    		ret++;
	}

    cout << "\n\nAnswer: " << ret << endl;
}
