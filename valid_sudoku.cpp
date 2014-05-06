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
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<bool> flag(board.size(), false);
        for(int i=0; i<board.size(); i++)
        {
        	for(int k=0; k<flag.size(); k++)
        		flag[k] = false;
        	for(int j=0; j<board[i].size(); j++)
        	{
        		if(board[i][j] != '.' && flag[board[i][j]-'1']==false)
        			flag[board[i][j] - '1'] = true;
        		else if(board[i][j] != '.')
        			return false;
        	}
        	for(int k=0; k<flag.size(); k++)
        		flag[k] = false;
        	for(int j=0; j<board[i].size(); j++)
        	{
        		int x = (i/3)*3 + j/3;
        		int y = (i%3)*3 + j%3;
        		if(board[x][y] != '.' && flag[board[x][y]-'1']==false)
        			flag[board[x][y] - '1'] = true;
        		else if(board[x][y] != '.')
        			return false;
        	}
        	for(int k=0; k<flag.size(); k++)
        		flag[k] = false;
        	for(int j=0; j<board[i].size(); j++)
        	{
        		if(board[j][i] != '.' && flag[board[j][i]-'1']==false)
        			flag[board[j][i] - '1'] = true;
        		else if(board[j][i] != '.')
        			return false;
        	}
        	
        }

	    return true;
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