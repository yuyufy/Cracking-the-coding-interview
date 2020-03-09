/*
Probleme : Given a string, find the length of the longest substring without repeating characters.
Input: "abcabcbb"
Output: 3 
*/

class Solution {
public:
  //Solution 1 : sliding window : hashmap , O(n)
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0, end = 0;
        int len = s.size();
        if(len <2) return len;
        unordered_map<char,int> map;
        while(start<=end&&end<len)
        {
           if(map.find(s[end])==map.end())
           {
               map[s[end]]++;
               end++;
               
               res = max(res,end-start);
           }
           else
           {
               if( map[s[start]]==1) map.erase(s[start]);
               else
                    map[s[start]]--;
               start++;
              
           }
            
        }
       return res; 
    }
  
  //Solution 2 
   int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0, end = 0;
        int len = s.size();
        if(len <2) return len;
        unordered_map<char,int> map;
        for(end = 0; end <len; end++)
        {
           if(map.find(s[end])!=map.end())
           {
               start = max(start,map[s[end]]);
           }
           res = max(res,end-start+1);
           map[s[end]]=end+1;
        }
       return res; 
    }
  
  //Solution 3:
   int lengthOfLongestSubstring(string s) {
        int res = 0;
        int start = 0;
        int len = s.size();
        if(len <2) return len;
        vector<int> dict(256,-1);
        
        for(int i = 0; i<s.size(); i++)
        {
            start = max(dict[s[i]],start);
            res= max(res,i-start+1);
            dict[s[i]] = i+1;
        }
       return res; 
    }
};
