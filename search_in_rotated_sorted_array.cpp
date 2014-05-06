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
    int search(int A[], int n, int target) {
        if(A==NULL || n<1)
            return -1;
        int lhs = 0;
        int rhs = n;
        while(lhs < rhs)
        {
            int mid = lhs + ((rhs-lhs)>>1);
            if(A[mid] == target)
                return mid;
            if(A[lhs] < A[mid])
            {
                if(A[lhs] <= target && A[mid]>target)
                    rhs = mid;
                else
                    lhs = mid+1;
            }else
            {
                if(A[mid] < target && A[rhs-1] >= target)
                    lhs = mid + 1;
                else
                    rhs = mid;
            }
        }
        return -1;
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