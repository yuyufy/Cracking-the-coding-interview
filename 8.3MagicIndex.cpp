#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;

class Solution{
  //Solution 1
  int helper(vector<int>& array,int start, int end)
  {
     if(start<0||end>array.size()) return -1;
     if(start>end) return -1;
     int mid = start + (end - start) /2;
     if(mid == array[mid]) return mid;
     else
     {
        if(array[mid]>mid) return helper(array,start,mid-1);
        else return helper(array,mid+1,end);
     }
  }
    //Solution 2
  int helper(vector<int>& array,int start, int end)
  {
     if(start<0||end>array.size()) return -1;
     if(start>end) return -1;
     int mid = start + (end - start) /2;
     if(mid == array[mid]) return mid;
     else
     {
        // search left
        int left =  helper(array,start,min(mid-1,array[mid]));
        if(left>0) return left;
        return helper(array,max(mid+1,array[mid]),end);
     }
  }
  int magicIndex(vector<int>& array)
  {
      if(array.size() == 0) return -1;
      return helper(array,0,array.size()-1);
  };
}
