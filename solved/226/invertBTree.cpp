// ACCEPTED

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
 
class SolutionPaths {
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
            
            static stringstream ss;
            
            // recursive implementation
            
            // label current node as discovered (i.e., add it to the map)
            string pathToHere;
            if( parent ){
                ss << nodeTracker[parent].first << "->" << currNode->val;
                //pathToHere = nodeTracker[parent].first + "->" + to_string(currNode->val);
                pathToHere = ss.str();
                ss.str("");
                ss.clear();                
            }
            else{
                ss << currNode->val;
                //pathToHere = to_string(currNode->val);
                pathToHere = ss.str();
                ss.str("");
                ss.clear();
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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if( root==NULL )
            return root;
            
        map<TreeNode*,TreeNode* > nodeTracker;
        TreeNode* currNode = root;
        TreeNode* parent = NULL;
        
        DFS(parent,currNode,nodeTracker);
        return root;
    }
    
    void DFS(TreeNode* parent, TreeNode* currNode, map<TreeNode*,TreeNode* >& nodeTracker){
        
        // recursive implementation
        
        // label current node as discovered (i.e., add it to the map)
        nodeTracker[currNode] = {parent};
        
        // if we're at a leaf, save the current path
        if( currNode->left || currNode->right ){
            TreeNode * temp = currNode->left;
            currNode->left = currNode->right;
            currNode->right = temp;
        }
        
        // if we're not at a leaf, recurse on child(ren) of currNode

        if( currNode->left ){
            if( nodeTracker.find(currNode->left) == nodeTracker.end() ){
                DFS(currNode,currNode->left,nodeTracker);
            }
        }            
        
        if( currNode->right ){
            if( nodeTracker.find(currNode->right) == nodeTracker.end() ){
                DFS(currNode,currNode->right,nodeTracker);
            }
        }
    }
    
};

int main(int argc, char** argv){

    TreeNode four(4);
    TreeNode two(2);
    TreeNode seven(7);
    TreeNode one(1);
    TreeNode three(3);
    TreeNode six(6);
    TreeNode nine(9);

    // root, left, right
    addChildren(&four,&two,&seven);
    addChildren(&two,&one,&three);   
    addChildren(&seven,&six,&nine);
    
    SolutionPaths s;
    vector<string> paths = s.binaryTreePaths(&four);
    s.printPaths(paths);
    
    cout << endl << endl << "INVERTED" << endl;
    
    Solution s1;
    TreeNode * newTree = s1.invertTree(&four);
    paths = s.binaryTreePaths(newTree);
    s.printPaths(paths);
    
}