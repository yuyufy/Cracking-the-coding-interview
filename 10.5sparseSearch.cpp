#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public : 
  int sparseSearchHelper(vector<string>& array, string& target,int start, int end)
  {
      if(start>end) return -1;
      int mid = start + (end-start)/2;
      string compareVal = array[mid];
      int leftmid = mid;
      int rightmid = mid;
      if(compareVal=="")
      {
          string leftval = compareVal;
          string rightVal = compareVal;
          while((leftmid>start||rightmid<end)&&leftval==""&&rightVal=="")
          {
              if(leftmid>start)
              {
                leftmid--;
                leftval = array[leftmid];
              }
              if(rightmid<end)
              {
                rightmid++;
                rightVal = array[rightmid];
              }
              if(leftVal!="")
              {
                mid = leftmid;
                compareVal = leftVal;
                break;
              }
              if(rightVal!="")
              {
                mid = rightmid;
                compareVal = rightVal;
                break;
              }
          }
         if(leftVal==""&&rightVal=="") return -1;
         if(compareVal==target) return mid;
         else if(start == end) return -1;
         if(target>array[start]&&target<compareVal)
         {
            int pos = leftmid<mid-1?leftmid:mid-1;
            return sparseSearchHelper(array,target,0,pos);
         }
        else
         {
            int pos = rightmid>mid+1? righttmid : mid+1;
            return sparseSearchHelper(array,target,pos,end);
         }
      }
    return -1;
  }
  int sparseSearch(vector<string>& array, string& target)
  {
     return sparseSearchHelper(array,target,0,array.size()-1);
  }
};
