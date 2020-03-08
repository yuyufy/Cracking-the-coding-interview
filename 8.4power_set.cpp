/*
Probleme : Given a set of distinct integers, nums, return all possible subsets (the power set).
There are 2^n subsets for a given set S of N size
Example : S = {0,1,2}
*/
class Solution {
public:
    //Solution 1 backtrack
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(nums,res, subset,0);
        return res;
    }
    void backtrack(vector<int>& nums,  vector<vector<int>>& res, vector<int>& tmp, int start)
    {
        res.emplace_back(tmp);
        for(int i = start; i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            backtrack(nums,res,tmp,i+1);
            tmp.pop_back();
        }
    }
    
    /*
    Solution 2 : bitmask: The idea is that we map each subset to a bitmask of length n,
    where 1 on the ith position in bitmask means the presence of nums[i] in the subset, and 0 means its absence.
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int bit_nums = nums.size();
        int ans_num = 1<<bit_nums;
        for(int i = 0; i<ans_num;i++)
        {
            vector<int>tmp;
            int bit_array = i;
            while(bit_array)
            {
                tmp.push_back(nums[log2(bit_array & ~(bit_array-1))]);
                bit_array &= bit_array-1 ;
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
