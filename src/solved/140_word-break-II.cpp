// ACCEPTED

#include<string>
#include<vector>
#include<utility>
#include<unordered_set>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<stack>

#define DEBUG

using namespace std;

// assumptions:
// a "sentence" is all the chars in s, plus add'l spaces, to form a list of discrete words
// empty string returns empty vector
// string with no valid words returns empty vector
 
class Solution {
public:

    struct WordNode{
    
      WordNode* parent;
      string nodeWord;
      string stringToHere;
      string remainder;
      vector<WordNode*> children;
      
      WordNode(string valWord) : nodeWord(valWord), parent(NULL) {}      
    
    };

    string origString;
    unsigned int minLen;
    unordered_map<WordNode*, int> nodeTracker;
    
    void buildWordTree(WordNode* parent, string s, unordered_set<string>& wordDict, vector<string>& sentences) {
    
        string currWord;
        for(auto it=s.begin();it!=s.end();++it){
            currWord.push_back(*it);
            if( wordDict.find(currWord) != wordDict.end() ){
                string remainder = s;    
                remainder.erase(remainder.begin(), remainder.begin()+currWord.size());
                WordNode* currNode = new WordNode(currWord);
                
                if( s!=origString ){
                    currNode->stringToHere += parent->stringToHere + " " + currWord;
                }
                else{
                    currNode->stringToHere = currWord;
                }
                currNode->remainder = remainder;
                //cout << endl << "word: " << currNode->nodeWord;
                //cout << endl << "str: " << currNode->stringToHere;
                //cout << endl << "rem: " << currNode->remainder << endl;
                    
                parent->children.push_back(currNode);
                currNode->parent = parent;
            }
        }

        for(auto itC=parent->children.begin();itC!=parent->children.end();++itC){
            unsigned int size = (*itC)->remainder.size();
            if( size == 0 ){
                currWord.clear();
                sentences.push_back((*itC)->stringToHere);
            }
            else if( !(*itC)->remainder.empty() ){
                buildWordTree(*itC, (*itC)->remainder, wordDict, sentences);
            }
        }
        
    }
    
    void destroyTree(WordNode* currNode){
    
        if( nodeTracker.empty() ){
            return;
        }
        
        //unordered_set<WordNode*> nodeTracker;
        stack<WordNode*> s;
        if( currNode ){
        s.push(currNode);
        while( !s.empty() )
            currNode = s.top();
            s.pop();
            if( nodeTracker.find(currNode) == nodeTracker.end() ){
                nodeTracker.insert({currNode,1});
                for(auto it=currNode->children.begin();it!=currNode->children.end();++it){
                    s.push(*it);
                }
            }
        }
        if( !nodeTracker.empty() ){
            for(auto it=nodeTracker.begin();it!=nodeTracker.end();++it){
                delete (*it).first;
            }
        }
            
    }
    
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    
        // create empty string
        vector<string> sentences;    
        
        // if input is empty, return empty string
        if( s.empty() || wordDict.empty() ){
            return sentences;
        }       

        // check end for words not in dict
        bool notFound = true;
        for(int i=s.size()-1;i>=0;--i){
            if(wordDict.find(s.substr(i)) != wordDict.end()){
                notFound = false;
                break;
            }
        }
        if( notFound ){
            return sentences;
        }
        
        origString = s;    
        WordNode* root = new WordNode(s);

        // find and save min length word in dict
        unordered_set<string>::iterator it = wordDict.begin();
        minLen = (*it).size();
        for(auto it=wordDict.begin();it!=wordDict.end();++it){
            if( (*it).size() < minLen ){
                minLen = (*it).size();
            }
        }
        
        buildWordTree(root, s, wordDict, sentences);
        destroyTree(root);
        
        return sentences;
    
    }   
    
};

void printList(vector<string>& list){

    cout << endl;
    for(auto it=list.begin();it!=list.end();++it){
        cout << *it << ", ";
    }
    cout << endl;

}

int main(int argc, char** argv){

    Solution sol;
    vector<string> list;
    cout << endl;

    cout << "BASIC TEST";
    unordered_set<string> wordDict1 = {"cat","cats","and","sand","dog"};
    string s1 = "catsanddog";
    list = sol.wordBreak(s1,wordDict1);    
    printList( list );
    cout << endl;
    
    // empty string
    cout << "EMPTY STRING";
    unordered_set<string> wordDict2 = {"cat","cats","and","sand","dog"};
    string s2;
    list = sol.wordBreak(s2,wordDict2);    
    printList( list );
    cout << endl;
    
    // repeated chars and not all in a word
    cout << "AAA TEST 1";
    unordered_set<string> wordDict3 = {"aaaa","aaa"};
    string s3 = "aaaaaaa";
    list = sol.wordBreak(s3,wordDict3);    
    printList( list );
    cout << endl;  
    
    cout << "AB TEST";
    unordered_set<string> wordDict5 = {"b"};
    string s5 = "a";
    list = sol.wordBreak(s5,wordDict5);    
    printList( list );
    cout << endl;
    
    // s/b ["b b"]
    cout << "BB TEST";
    unordered_set<string> wordDict6 = {"a","b","bbb","bbbb"};
    string s6 = "bb";
    list = sol.wordBreak(s6,wordDict6);    
    printList( list );
    cout << endl;
    
    cout << "A TEST";
    unordered_set<string> wordDict7 = {"a"};
    string s7 = "a";
    list = sol.wordBreak(s7,wordDict7);    
    printList( list );
    cout << endl;
    
    cout << "ABCD TEST";
    unordered_set<string> wordDict8 = {"a","abc","b","cd"};
    string s8 = "abcd";
    list = sol.wordBreak(s8,wordDict8);    
    printList( list );
    cout << endl;
    
    cout << "AAA... TEST";
    unordered_set<string> wordDict9 = {"aaaa","aa","a"};
    string s9 = "aaaaaaa";
    list = sol.wordBreak(s9,wordDict9);    
    printList( list );
    cout << endl;

    // repeated chars and not all in a word
    cout << "AAA TEST 2";
    unordered_set<string> wordDict4 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    string s4 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    //string s4 = "aaaaab";
    list = sol.wordBreak(s4,wordDict4);    
    printList( list );
    cout << endl;  
    
    return 0;
}