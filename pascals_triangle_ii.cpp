#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        long long f1 = 1;
        long long k1 = 1;
        for(int i=0; i<=rowIndex; ++i)
        {
            res.push_back((int)f1);
            f1 = f1 * (rowIndex+1 - k1) / k1;
            ++k1;
        }
        return res;
    }
};

int main()
{
	Solution sol;

	vector<int> res = sol.getRow(30);

    for(int i=0; i<res.size(); ++i)
    {
        cout << res[i];
    }
    cout << endl;

	return 0;
}
