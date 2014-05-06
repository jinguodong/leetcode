#include <iostream>
#include <list>
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(s==NULL && p==NULL)
            return true;
        if(s==NULL || p==NULL)
            return false;
        if((*s)=='\0' && (*p)=='\0')
            return true;
        if((*p)=='\0')
            return false;
        if((*(p+1)) != '*')
        {
            if((*s) == (*p) || ((*p)=='.' && (*s)!='\0'))
            {
                if(isMatch(s+1, p+1))
                    return true;
            }
        }
        else
        {
            if(isMatch(s, p+2))
                return true;
            if((*s) == (*p) || ((*p)=='.' && (*s)!='\0'))
            {
                if(isMatch(s+1, p))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
	Solution sol;
    char a[] = "aaa";
    char b[] = "a*a";
    cout << sol.isMatch(a, b) << endl;
	return 0;
}