#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0)
            return 0;
        
        long long a = dividend < 0 ? -(long long)dividend : dividend;
        long long b = divisor < 0 ? -(long long)divisor : divisor;
            
        long long res = 0;
        while(a >= b)
        {
            long long c = b;
            for(int i=0; a>=c; ++i, c<<=1)
            {
                a = a-c;
                res += 1<<i;
            }
        }
        return ((dividend^divisor)>>31) ? (-res) : res;
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
