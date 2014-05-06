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
    int longestConsecutive(vector<int> &num) {
        map<int, bool> mapping;
        for(int i=0; i<num.size(); i++)
        {
            mapping[num[i]] = false;
        }
        int mlen = 0;
        int tlen = 0;
        for(int i=0; i<num.size(); i++) if(!mapping[num[i]])
        {
            tlen = 1;
            mapping[num[i]] = true;
            int lnum = num[i];
            int rnum = num[i];
            while(mapping.find(--lnum) != mapping.end())
            {
                mapping[lnum] = true;
                tlen ++;
            }
            while(mapping.find(++rnum) != mapping.end())
            {
                mapping[rnum] = true;
                tlen ++;
            }
            if(mlen < tlen)
                mlen = tlen;
        }
        return mlen;
    }
};

int main()
{
	Solution sol;
	char b[] = ".87654321";
	vector<char> a(b, b+9);
    vector<vector<char> > res;
    res.push_back(a);
    char b2[] = "2........";
    vector<char> a2(b2, b2+9);
    res.push_back(a2);
    char b3[] = "3........";
    vector<char> a3(b3, b3+9);
    res.push_back(a3);
    char b4[] = "4........";
    vector<char> a4(b4, b4+9);
    res.push_back(a4);
    char b5[] = "5........";
    vector<char> a5(b5, b5+9);
    res.push_back(a5);
    char b6[] = "6........";
    vector<char> a6(b6, b6+9);
    res.push_back(a6);
    char b7[] = "7........";
    vector<char> a7(b7, b7+9);
    res.push_back(a7);
    char b8[] = "8........";
    vector<char> a8(b8, b8+9);
    res.push_back(a8);
    char b9[] = "9........";
    vector<char> a9(b9, b9+9);
    res.push_back(a9);
    
    cout << sol.isValidSudoku(res) << endl;
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