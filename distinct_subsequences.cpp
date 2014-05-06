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
    int numDistinct1(string S, string T) {
        if(T.size() < 1)
            return 1;
        if(S.size() < 1)
            return 0;
        vector<vector<int> > flag(T.size()+1, vector<int>(S.size()+1, 0));
        for(int j=0; j<flag[0].size(); j++)
            flag[0][j] = 1;
        for(int i=1; i<flag.size(); i++)
        {
            for(int j=i; j<flag[i].size(); j++)
            {
                flag[i][j] = flag[i][j-1] + (T[i-1]==S[j-1]?flag[i-1][j-1] : 0);
            }
        }
        return flag[T.size()][S.size()];
    }

    int numDistinct(string S, string T) {
        if(T.size() < 1)
            return 1;
        if(S.size() < 1)
            return 0;
        vector<int> flag(T.size()+1, 0);
        flag[0] = 1;

        for(int i=0; i<S.size(); i++)
        {
            for(int j=T.size()-1; j>=0; j--)
            {
                flag[j+1] += (S[i] == T[j] ? flag[j] : 0);
            }
        }

        return flag[T.size()];
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