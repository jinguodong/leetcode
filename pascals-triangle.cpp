#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
private:
    int getNum(int i, int j, const vector<vector<int> > &res)
    {
        if(i-1 <= 0 || j-1 <= 0 || j>i-1)
            return 1;
        return res[i-1-1][j-1-1] + res[i-1-1][j-1];
    }
public:
    vector<vector<int> > generate(int numRows) {
        if(numRows < 1)
            return vector<vector<int> >(0, vector<int>(0, 0));
        vector<vector<int> > res(numRows);
        for(int i=1; i<=numRows; ++i)
        {
            for(int j=1; j<=i; ++j)
            {
                res[i-1].push_back(getNum(i, j, res));
            }
        }
        return res;
    }
};

int main()
{
	Solution sol;

	vector<vector<int> > res = sol.generate(0);
    for(int i=0; i<res.size(); ++i)
    {
        for(int j=0; j<res[i].size(); ++j)
            cout << res[i][j];
        cout << endl;
    }

	return 0;
}
