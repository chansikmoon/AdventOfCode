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
    
    // 0101100   
    // FBFBBFF
    // 0 32 0 8 4 0 0 = 44
    
    // RLR
    // 101
    
    int ret = 0;
    for (string str : v)
    {
    	int row = 0 , col = 0;
    	
    	for (auto c : str)
    	{
    		if (c == 'F' || c == 'B')	
    		{
    			row <<= 1;
    			
    			if (c == 'B')
    				row += 1;
			}
			
			if (c == 'L' || c == 'R')	
    		{
    			col <<= 1;
    			
    			if (c == 'R')
    				col += 1;
			}
		}
    	
    	ret = max(ret, row * 8 + col);
	}

	cout << "result: " << ret << endl;
}
