#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() < 1 || grid[0].size() < 1)
            return 0;
        for(int i=grid.size()-1; i>=0; --i)
        {
            for(int j=grid[i].size()-1; j>=0; --j)
            {
                if(i+1 >= grid.size())
                {
                    if(j+1 >= grid[i].size())
                        continue;
                    else
                    {
                        grid[i][j] += grid[i][j+1];
                    }
                }
                else if(j+1 >= grid[i].size())
                {
                    if(i+1 >= grid.size())
                    {
                        continue;
                    }
                    else
                    {
                        grid[i][j] += grid[i+1][j];
                    }
                }
                else
                {
                    grid[i][j] += min(grid[i+1][j], grid[i][j+1]);
                }
            }
        }
        return grid[0][0];
    }
};

int main()
{
	Solution sol;

	vector<vector<int> > res;
    int a[] = {1,2,5};
    res.push_back(vector<int>(a, a+3));
    int a1[] = {3,2,1};
    res.push_back(vector<int>(a1, a1+3));

    sol.minPathSum(res);

    for(int i=0; i<res.size(); ++i)
    {
        for(int j=0; j<res[i].size(); ++j)
            cout << res[i][j];
        cout << endl;
    }

	return 0;
}
