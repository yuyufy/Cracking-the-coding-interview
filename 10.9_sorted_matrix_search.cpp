/* 
   PROBLEM:
   Given an M x N matrix in which each row and each column is sorted in ascending order,
   write a method to find an element.
 */
class Solution {
public:
   // Solution 1  O(M+N)
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
       if( matrix.size() == 0) return false;
       int row = matrix.size()-1;
       int col = 0;
       while(row>=0 && col<matrix[0].size())
       {
          if(target == matrix[row][col]) return true;
          else if(target < matrix[row][col]) col++;
          else row--;
       }
       return false;
    };
}
       
