/*
Problem Statement:
Write a method to compute all permutations of a string of unique characters.
Solution:
First, we show the definition of permutations by example:
'a'    -> 'a'                                        # 1! = 1
'al'   -> 'al' , 'la'                                # 2! = 2
'ale'  -> 'ale', 'ael', 'lae', 'lea', 'eal', 'ela'   # 3! = 6
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

void findPermutations(string cur, unordered_map <char, int>& map, vector<string>& res, int len)
{
    int cur_len = curr.size();
    if(cur_len==len)
    {
      res.push_back(cur); return;
    }
  
   for (unordered_map<char,int>::iterator i = map.begin(); i!=map.end(); i++)
   {
     if(i->second!=0)
     {
        string tmp = cur + i->first;
        i->second--;
        findPermutations(tmp,map,res,len);
        i->second++;
     }
   }
}

int main()
{
	string s = "abbc";
	string cur ="";
	unordered_map <char, int> map;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (map.find(s[i])!=map.end())
			map.find(s[i])->second++;
		else
			map[s[i]]++;
	}
	vector<string> res;
	findPermutations(cur,map,res,len);
	for (int i = 0; i < res.size(); i++)
	{
		cout<<res[i]<<endl;
	}
	return 0;
}
