#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x < 10)
            return true;
        int m = 1;
        while((x/m) >= 10)
            m*= 10;
        int k=10;
        int k1 = 1;
        while(m >= k)
        {
            int lhs = x/m;
            lhs = lhs%10;
            m = m/10;
            int rhs = x%k;
            rhs = rhs/k1;
            k *= 10;
            k1 *= 10;
            if(rhs != lhs)
                return false;
        }
        return true;
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