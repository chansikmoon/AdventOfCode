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
    
    vector<int> slope {1,1,3,1,5,1,7,1,1,2};
    
    int ret = 1;
    
    for (int i = 1; i < slope.size(); i += 2)
    {
    	int right = slope[i-1], down = slope[i], tree = 0;
    	
    	for (int r = down, c = right; r < v.size(); r += down, c += right)
		{
			int n = v[r].size();
			if (v[r][c % n] == '#')
				tree++;
		}
		
		cout << "right: " << right << " down: " << down << " : " << tree << endl;
		ret *= tree;
	}
	
	cout << "\nTotal:" << ret << endl;
}
