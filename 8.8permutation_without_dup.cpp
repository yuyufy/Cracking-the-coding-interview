#include<string>
#include<iostream>
#include<vector>
using namespace std;

void findPermutations(string cur, string s, vector<string>& res)
{
    int len = s.size();
    if(!len)
    {
      res.push_back(cur); return;
    }
  
   for (int i = 0; i<len; i++)
   {
        string first = cur + s.substr(i,1);
        string rem = s.substr(0,i) + s.substr(i+1,len-i-1);
        findPermutations(first,rem,res);
    
   }
}

int main()
{
	string s = "abbc";
	string cur ="";
	vector<string> res;
	findPermutations(cur,s,res);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
