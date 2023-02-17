https://leetcode.com/problems/longest-common-prefix/submissions/786420979/
class Solution {
public:
void solve(string &str,vector<string>& strs,int i)
        {
             int j=0;
            while(j<=strs[i].size())
            {
                if(str[j]==strs[i][j])
                {  j++;
                 
                }
                else
                { 
                   str=str.substr(0,j);
                 break;
                }
            
                }

        }
    string longestCommonPrefix(vector<string>& strs) {
            string str=strs[0];
       
        for(int i=1;i<strs.size();i++)
        {
           solve(str,strs,i);
           cout<<str<<endl;
        }
        return str;
        
    }
};
