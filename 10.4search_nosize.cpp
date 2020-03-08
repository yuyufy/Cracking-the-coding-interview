/*
probleme : Given an integer array sorted in ascending order, write a function to search target in nums.  If target exists, then return 
its index, otherwise return -1. However, the array size is unknown to you. You may only access the array using an ArrayReader interface, 
where ArrayReader.get(k) returns the element of the array at index k (0-indexed).
You may assume all integers in the array are less than 10000, and if you access the array out of bounds, ArrayReader.get will return 2147483647.
class ArrayReader {
    public:
      int get(int index);
 };

*/

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int pivot = 0, left = 0, right = 1;
        if(reader.get(0)==target) return 0;
        while(reader.get(right)<target)
        {
            left = right;
            right<<=1;
        }
        while(left<=right)
        {
            pivot = left + ((right-left)>>1);
            int num = reader.get(pivot);
            if(num==target) return pivot;
            else if(num<target)
                left = pivot+1;
            else
                right = pivot-1;
            
        }
        return -1;
    }
};
