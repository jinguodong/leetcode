#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
        	return 0;
        int max_fit = 1<<31;
        int lower = 1<<30;
        for(int i=0; i<prices.size(); i++)
        {
        	if(max_fit < prices[i] - lower)
        		max_fit = prices[i] - lower;
        	if(prices[i] < lower){
        		lower = prices[i];
        	}
        }
        if(max_fit < 0)
        	return 0;
        return max_fit;
    }
};

int main()
{
	Solution sol;
	
	int a[] = {2,1};
	vector<int> prices(a, a+2);
	cout << sol.maxProfit(prices);

	return 0;
}
