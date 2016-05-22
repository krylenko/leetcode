// ACCEPTED

// iterative solution is 8-12 ms, recursive is ~4 ms
// C++11 version with to_string() instead of stringstream, running time is about the same

#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <sstream>
#include <stack>

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
    
        vector<string> binaryTreePaths(TreeNode* root) {

            vector<string> paths;
            if( root==NULL )
                return paths;
                
            map<TreeNode*,pair<string,TreeNode*> > nodeTracker;
            TreeNode* currNode = root;
            TreeNode* parent = NULL;
            
            DFS(parent,currNode,nodeTracker,paths);
            return paths;
        }
        
        void DFS(TreeNode* parent, TreeNode* currNode, map<TreeNode*,pair<string,TreeNode*> >& nodeTracker, vector<string>& paths){
            
            // recursive implementation
            
            // label current node as discovered (i.e., add it to the map)
            string pathToHere;
            if( parent ){
                pathToHere = nodeTracker[parent].first + "->" + to_string(currNode->val);
            }
            else{
                pathToHere = to_string(currNode->val);
            }
            nodeTracker[currNode] = {pathToHere,parent};
            
            // if we're at a leaf, save the current path
            if( !currNode->left && !currNode->right ){
                paths.push_back(nodeTracker[currNode].first);
            }
            
            // if we're not at a leaf, recurse on child(ren) of currNode

            if( currNode->left ){
                if( nodeTracker.find(currNode->left) == nodeTracker.end() ){
                    DFS(currNode,currNode->left,nodeTracker,paths);
                }
            }            
            
            if( currNode->right ){
                if( nodeTracker.find(currNode->right) == nodeTracker.end() ){
                    DFS(currNode,currNode->right,nodeTracker,paths);
                }
            }
        }
        
        void printPaths(const vector<string>& rawInput){
            for(auto it=rawInput.begin();it!=rawInput.end();++it){
                cout << endl << *it << ",";
            }
        }                
};

int main(int argc, char** argv){

    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(5);
    TreeNode e(7);

    // root, left, right
    addChildren(&a,&b,&c);          //  1->2, 1->3 
    addChildren(&b,&d,&e);          //  2->5, 2->7
    
    //addChildren(&b,&e,NULL);        //  2->7, 5->NULL
    
    Solution s;
    vector<string> paths = s.binaryTreePaths(&a);
    s.printPaths(paths);
    
}