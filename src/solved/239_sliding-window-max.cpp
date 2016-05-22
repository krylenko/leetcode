// ACCEPTED

#include<iostream>
#include<vector>

// assume vector is not empty
// assume vector length is >= k

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if( nums.empty() ) {
            vector<int> noyn = {0};
            noyn.pop_back();
            return noyn;
        }
        
        int wEnd = k-1;
        int len = nums.size() - wEnd;
        int max = nums[0];
        
        vector<int> maxes;
        maxes.reserve(len);
        
        for(int i=0;i<len;++i){
            max = nums[i];
            for(int j=i+wEnd;j>i;--j)
                if( nums[j] >= max ){
                    max = nums[j];
                }
                maxes.push_back(max);
        }
        
        return maxes;
    }
};

int main(int argc, char * argv[]){

    Solution s;
    //vector<int> list = {-3,2,1,6,-3,10,2,19};
    //vector<int> list;
    vector<int> list = {1,-1};
    int k = 1;

    vector<int> result = s.maxSlidingWindow(list,k);
    cout << endl;
    for(auto it=result.begin();it!=result.end();++it)
        cout << *it << " ";
    
    cout << endl;
    
    return 0;

}