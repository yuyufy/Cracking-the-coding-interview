/*
PROBLEM:
   Given an array of integers, sort the array into one of alternating peaks and valleys
   where a peak is an integer greater than or equal to its neighbors and a valley is an
   integer less than or equal to its neighbors.
 
   TEST CASES:
   {5, 3, 1, 2, 3} --> {5, 1, 3, 2, 3}
   {5, 8, 6, 2, 3, 4, 6} --> {5, 8, 2, 6, 3, 6, 4};
   
   Solution :
   if first <=second <=third
      swap second et third
   else if first >=second >=third
      swap second et third
   else if first <=second >=third ||  first >=second <=third
      do nothing
*/
class Solution{
    void peaksAndValleys(vector<int>& array) 
    {
       if(array.size()<3) return array;
       for(int i = 0; i< array.size()-2; i++)
       {
          if(array[i]<=array[i+1]&&array[i+1]<=array[i+2] ||array[i]>=array[i+1]&&array[i+1]>=array[i+2])
             swap(array[i+1],array[i+2]);
       }
    }
};
