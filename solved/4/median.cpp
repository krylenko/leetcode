#include <iostream>
#include <vector>

class Solution {
public:

    int binarySearch(int key, std::vector<int>& vec, int left, int right)
    {
        if( (right-left) <= 1 )
        {
            if( key <= vec[left] )
                return left;
            else if( key <= vec[right] )
                return right;
            else
                return right + 1;
        }
        
        int searchidx = (int)( (right-left)/2.0 + left );
        if( key <= vec[searchidx] )
            binarySearch(key,vec,left,searchidx);
        else
            binarySearch(key,vec,searchidx,right);
        
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        int mtemp = m;
        int ntemp = n;
        double med = 0.0;
        if(m<n)
        {
            for(int i=0;i<m;++i)
            {
                ntemp = nums2.size();
                int idx = binarySearch(nums1[i],nums2,0,ntemp-1);
                auto it = nums2.begin();
                if( idx == ntemp )
                  nums2.push_back(nums1[i]);
                else
                  nums2.insert(it+idx,nums1[i]);
            }
            if( nums2.size() % 2 != 0 )
            {
                ntemp = nums2.size();
                int idx = (int)( ntemp-1)/2;
                med = nums2[idx];
            }
            else
            {
                ntemp = nums2.size();
                int idx1 = (int)( ntemp/2 - 1 );
                int idx2 = (int)( ntemp/2 );
                med = (nums2[idx2] + nums2[idx1]) / 2.0;
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                mtemp = nums1.size();
                int idx = binarySearch(nums2[i],nums1,0,mtemp-1);
                auto it = nums1.begin();
                if( idx == mtemp )
                  nums1.push_back(nums2[i]);
                else
                  nums1.insert(it+idx,nums2[i]);
            }
            if( nums1.size() % 2 != 0 )
            {
                mtemp = nums1.size();
                int idx = (int)( mtemp-1)/2;
                med = nums1[idx];
            }
            else
            { 
                mtemp = nums1.size();
                int idx1 = (int)( mtemp/2 - 1 );
                int idx2 = (int)( mtemp/2 );
                med = (nums1[idx2] + nums1[idx1]) / 2.0;
            }
        }
        return med;
    }
};

int main() {
	// your code goes here
	
	Solution s;
	//std::vector<int> nums1 = {-36,-35,-23};
	//std::vector<int> nums2 = {2,3,4000,60000,90000,100000};
	//std::vector<int> nums2 = {-36,5,23};
	
  std::vector<int> nums1 = {1};
  std::vector<int> nums2 = {1};
  
	double med = s.findMedianSortedArrays(nums1,nums2);
	
	std::cout << med << std::endl;
	
	return 0;
}