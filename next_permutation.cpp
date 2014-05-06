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
    void nextPermutation(vector<int> &num) {
        if(num.size() < 1)
            return;
        int ii=num.size()-1;
        int jj=ii;
        bool flag = false;
        for(; ii>0; ii--)
        {
            if(num[ii-1] < num[ii])
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            reverse(num.begin(), num.end());
            return ;
        }
        else
        {
            ii--;
            for(; jj>ii; jj--)
            {
                if(num[jj] > num[ii])
                {
                    swap(num[jj], num[ii]);
                    reverse(num.begin()+ii+1, num.end());
                    return;
                }
            }
        }
        return;
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