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
 
class Solution {
    public:
        vector<string> binaryTreePaths(TreeNode* root) {

            vector<string> paths;
            if( root==NULL )
                return paths;
                
            map<TreeNode*,pair<string,TreeNode*> > nodeTracker;
            TreeNode* currNode = root;
            
            DFS(root,nodeTracker,paths);
            return paths;
        }

        void DFS(TreeNode* currNode, map<TreeNode*,pair<string,TreeNode*> >& nodeTracker, vector<string>& paths){
            
            static stringstream ss;
            
            stack<TreeNode*> s;         // create stack and push current node (starts from root)
            s.push(currNode);       
            TreeNode* parent = NULL;    // b/c we're starting with the root   
            while(!s.empty()){
                currNode = s.top();
                s.pop();
                if( nodeTracker.find(currNode) == nodeTracker.end() ){      // if not yet in map, create empty path and fill it out                   
                    ss << currNode->val;
                    //cout << endl << currNode->val << ", " << ss.str() << endl;
                    nodeTracker[currNode] = {ss.str(),parent};                   
                    ss.str("");
                    ss.clear(); 
                    if( !currNode->left && !currNode->right ){
                        paths.push_back(nodeTracker[currNode].first);
                    }
                }
                else{       // if it's already in the map, which means it has a parent
                    ss << nodeTracker[currNode].first << "->" << currNode->val;
                    nodeTracker[currNode].first = ss.str();
                    //cout << endl << currNode->val << ", " << nodeTracker[currNode].first << ", visited" << endl;
                    ss.str("");
                    ss.clear();
                    if( !currNode->left && !currNode->right ){
                        paths.push_back(nodeTracker[currNode].first);
                    }                    
                }                    
                string& pathToHere = nodeTracker[currNode].first;
                if( currNode->right ){
                    nodeTracker[currNode->right] = {pathToHere,currNode};
                    s.push(currNode->right);
                }
                if( currNode->left ){
                    nodeTracker[currNode->left] = {pathToHere,currNode};
                    s.push(currNode->left);
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