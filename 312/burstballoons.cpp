#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stack>
#include<vector>

/*

 Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 = n = 500, 0 = nums[i] = 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

*/

// for each number, build a tree with that number as the node, try traversing all paths and preserve the max path -- dynamic programming?
// if a subsequent tree (path) has a higher value, save that one
// recurse until there are no nodes left to try

using namespace std;

// definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void addChildren(TreeNode* node, TreeNode* left, TreeNode* right){
    node->left = left;
    node->right = right;
}

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int result = 0;
        if( nums.size() < 0 || nums.size() > 500 )
            return result;
        
        int left = 1, right = 1;
        
        // check whether any ballon has a value greater than 100 and return 0 if so
        
        return result;
        
    }
};

void unitTest(int output, int target)
{
    if( output != target )
        std::cout << "---> FAIL: " << output << " s/b " << target << " <---" << std::endl;
    else
        std::cout << "PASS: " << output << " s/b " << target << std::endl;
}

int main(int argc, char ** argv)
{

    Solution s;

    std::vector< std::pair<std::vector<int>, int> > tests = {
        { {3,1,5,8},167 }, { {},0 }       
     };

    std::cout << std::endl;
    for( auto i=tests.begin(); i!=tests.end(); ++i )
        unitTest(s.maxCoins(i->first),i->second);

    return 0;

}
