#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if(len < 1)
            return 0;
        int res = 0;
        while(len>0 && s[len-1]==' ')
            len--;
        while(len>0 && s[len-1]!=' ')
        {
            len--;
            res++;
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