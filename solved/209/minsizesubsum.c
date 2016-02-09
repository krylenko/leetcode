#include <stdio.h>
#include <malloc.h>
 
int minSubArrayLen(int s, int* nums, int numsSize) {
    
    int minlength = numsSize + 1;
    int totsum = nums[0];    
    int templen = 1;
    int start = 0;
    
    if( totsum >= s )
      return 1;
    
    for(int i=1;i<numsSize;++i)
    {
      totsum += nums[i];
      ++templen;
      if( totsum >= s )
      {
        while( totsum >= s )
        {
          totsum -= nums[start];
          ++start;
          --templen;
        }
        if( templen + 1 < minlength )
          minlength = templen + 1;
      }
    }
    
    if( minlength == numsSize + 1 )
        return 0;
    else
        return minlength;
    
}

int main(int argc, char* argv[])
{

  // 15, [5,1,3 ,5,10,7,4,9,2,8]

  int size = 6;
  int* nums = (int*) malloc(size*sizeof(int));
  nums[0] = 2; nums[1] = 3; nums[2] = 1; nums[3] = 2; nums[4] = 4;
  nums[5] = 3; //nums[6] = 4; nums[7] = 9; nums[8] = 2; nums[9] = 8;
  int s = 7;
  
  int length = minSubArrayLen(s, nums, size);
  
  printf("\nlength = %d\n",length);

}