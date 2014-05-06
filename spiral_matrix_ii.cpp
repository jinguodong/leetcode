#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n, 0));
        if(n < 1)
            return res;
        int rtime = (n+1)>>1;
        int m=1;
        for(int i=0; i<rtime; i++)
        {
            for(int j=i; j<(n-i); j++)
            {
                res[i][j] = m++;
            }
            for(int j=i+1; j<(n-i); j++)
            {
                res[j][n-1-i] = m++;
            }
            for(int j=(n-2-i); j>=i; j--)
            {
                res[n-1-i][j] = m++;
            }
            for(int j=(n-2-i); j>i; j--)
            {
                res[j][i] = m++;
            }
        }
        return res;
    }
};

int main()
{
	Solution sol;
    vector<vector<int> > res;
    res = sol.generateMatrix(3);
    for(int i=0; i<res.size(); i++)
    {
        for(int j=0; j<res[i].size(); j++)
        {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }
	return 0;
}