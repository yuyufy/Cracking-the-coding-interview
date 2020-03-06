/*
Given an array of strings, group anagrams together.
Solution 1 : sort letters
Solution 2 : prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103}, every letter can change to be a value
*/

#include<isotream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(auto str : strs)
        {
           string tmp = str;
           sort(tmp.begin(),tmp.end());
           map[tmp].push_back(str);
        }
         for(auto val : map)
        {
          res.push_back(val.second);
        }
        return res;
    }
};
