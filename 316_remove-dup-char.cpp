#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        std::map<char,int> counter;
        std::string result;

        if( s.size() == 0 )
            return result;

        // build hash map
        char min=*(s.begin());
        char max = min;
        std::string::iterator minpos;
        for(auto c=s.begin(); c!=s.end(); ++c)
        {
            if( counter.find(*c) == counter.end() )
            {                
                counter[*c] = 1;
                if( *c < min ) { min = *c; minpos = c; }
                if( *c > max ) max = *c;
            }    
            else
                counter[*c] += 1;
        }
        
        
        // check string against hash map
        bool minReached = false;
        for(auto i=s.begin();i!=s.end();++i)    
        {   
            counter[*i] -= 1;
            
            if( minReached )
            {
                if( counter[*i] == 0 || ( counter[*i] > 0 && *i < max ) )
                {
                    result.push_back(*i);
                    counter[*i] = -1;
                }
            }
            else
            {
                if( *i == min )
                {
                    result.push_back(*i);
                    counter[*i] = -1;
                    minReached = true;
                }   
                else if( counter[*i] == 0 || ( ( counter[*i] > 0 && counter[*(i+1)] == 1 ) && *i < *(i+1) ) )    
                {
                    result.push_back(*i);
                    counter[*i] = -1;                    
                }
            }
            
        }
        
        return result;
    }

};

void unitTest(std::string result, std::string target)
{
    if( result.compare(target) )
        std::cout << "---> FAIL: " << result << " s/b " << target << " <---" << std::endl;
    else
        std::cout << "PASS: " << result << " s/b " << target << std::endl;
}

int main(int argc, char ** argv)
{

    Solution s;

    std::vector< std::pair<std::string, std::string> > tests = {
        {"cbacdcbc","acdb"},    {"bcabc", "abc"},   {"cbac", "bac"},
        {"baa", "ba"},          {"baab", "ab"},     {"ccacbaba", "acb"},
        {"bbcaac", "bac"},      {"abacb", "abc"},   {"bddbccd", "bcd"},
        {"bbcab", "bca"},       {"bccab", "bca"}         
     };

    std::cout << std::endl;
    //for( auto i : tests )
    for( auto i=tests.begin(); i!=tests.end(); ++i )
        unitTest(s.removeDuplicateLetters(i->first),i->second);
    std::cout << std::endl;

    return 0;

}

// start with: the first unique char OR the min, whichever is first
// continue with: adding each unique character
