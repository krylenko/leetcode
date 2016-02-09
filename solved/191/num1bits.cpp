class Solution {

public:

    int hammingWeight(uint32_t n) {

        int count = 0;

        for(uint8_t i=0;i<32;++i){

            if( 1 & n ){

                ++count;

            }

            n>>=1;

        }

        return count;

    }

};
