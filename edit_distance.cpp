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
    int minDistance(string word1, string word2) {
        if(word1.size() < 1 || word2.size() < 1)
            return max(word1.size(), word2.size());

        vector<vector<int> > ml1(word1.size()+1, vector<int>(word2.size()+1, 0));
        for(int i=0; i<ml1.size(); i++)
        {
            ml1[i][0] = i;
        }
        for(int j=0; j<ml1[0].size(); j++)
        {
            ml1[0][j] = j;
        }
        for(int i=1; i<ml1.size(); i++)
        {
            for(int j=1; j<ml1[i].size(); j++)
            {
                if(word1[i-1] == word2[j-1])
                    ml1[i][j] = ml1[i-1][j-1];
                else
                {
                    int tem = min(ml1[i-1][j-1], ml1[i-1][j]);
                    tem = min(tem, ml1[i][j-1]);
                    ml1[i][j] = tem+1;
                }
            }
        }
        return ml1[word1.size()][word2.size()];
    }
};

int main()
{
    Solution sol;
    int a[] = {1,2,3,4,5,6,7,8,9};
    vector<int> inp(a, a+9);
    sol.nextPermutation(inp);
    for(int i=0; i<inp.size(); i++)
        cout << inp[i] << " " ;
    cout << endl;
	return 0;
}