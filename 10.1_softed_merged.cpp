/*
Problem Statement:
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
Write a method to merge B into A in sorted order.

Solution : 
*/
class Solution{
 public : 
  void mergeTwoarrays(vector<int>& A, vector<int>& B, int lastAIndex, int lastBIndex) {
     /* Index of last location of merged array */
      int mergeIndex = lastAIndex + lastBIndex-1;
      while(lastBIndex>0)
      {
        if (lastindexA >= 0 && A[lastindexA] > B[lastindexB]) 
        {
            A[mergeIndex] = A[lastindexA];
            lastAindex--;
        }
        else
        {
            A[mergeIndex] = B[lastindexA];
            lastBindex--;
        }
        mergeIndex--;
      }
  }
}
