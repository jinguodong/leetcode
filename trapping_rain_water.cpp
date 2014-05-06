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
    int trap(int A[], int n) {
        int res = 0;
        if(A==NULL || n<1)
            return res;
        vector<int> temp(n, 0);
        int lhs=0, rhs=0;
        for(int i=0; i<n; i++)
        {
            if(lhs < A[i])
                lhs = A[i];
            temp[i] = lhs;
        }
        for(int i=n-1; i>=0; i--)
        {
            if(rhs < A[i])
                rhs = A[i];
            if(temp[i] > rhs)
                temp[i] = rhs;
            res += temp[i] - A[i];
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