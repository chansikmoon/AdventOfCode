#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    
    string line;
    vector<int> v;
    while (getline(cin, line))
    {
    	if (line == "")
    		break;
    	
    	v.push_back(stoi(line));
	}
	
	sort(v.begin(), v.end());
	
	for (int x = 0; x < v.size(); x++)
	{
		if (x > 0 && v[x - 1] == v[x])
			continue;
			
		int y = x + 1, z = v.size() - 1;
		
		while (y < z)
		{
			int sum = v[x] + v[y] + v[z];
			
			if (sum == 2020)
			{
				cout << v[x] << " * " << v[y] << " * " << v[z] << " = " << v[x] * v[y] * v[z] << endl;
				break;
			}
			
			if (sum > 2020)
				z--;
			else if (sum < 2020)
				y++;
		}
	}
}
