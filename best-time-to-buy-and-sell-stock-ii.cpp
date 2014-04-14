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
        int buy=-1;
        int sell=-1;
        int fit=0;
        if(prices.size() < 2) return 0;

        
        for(int i=0; (i+1) < prices.size(); i++)
        {
            if(prices[i]>=prices[i+1])
                continue;
            buy = i;
            i++;
            while((i+1)<prices.size())
            {
                if(prices[i+1]<prices[i]) break;
                i++;
            }
            sell=i;
            if(sell > buy)
                fit+=(prices[sell]-prices[buy]);
        }
        return fit;
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
