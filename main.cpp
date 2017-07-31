#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//66% 9ms
//O(n)
class Solution {
public:
    string minWindow(string s, string t) {


        int tFreq[256]  ={0};
        for(int i=0;i<t.size();i++) {
            tFreq[t[i]]++;
        }
        int sFreq[256] = {0};
        int sCnt = 0;

        int minLength = int(s.size() + 1);
        int startIndex = -1;

        int l = 0,r = -1; //slide window [l...r]
        while(l<s.size()){
            if(r+1<s.size() && sCnt < t.size()){
                r++;
                sFreq[s[r]]++;
                if(sFreq[s[r]]<=tFreq[s[r]])
                    sCnt++;
            }else{
                assert(sCnt<=t.size());
                if(sCnt==t.size() && r-l+1<minLength){
                    minLength = r-l+1;
                    startIndex = l;
                }
                sFreq[s[l]]--;
                if(sFreq[s[l]]<tFreq[s[l]])
                    sCnt--;
                l++;
            }

        }
        if(startIndex!=-1)
            return s.substr(startIndex,minLength);
        return "";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << Solution().minWindow( "ADOBECODEBANC" , "ABC" )<<endl;
    cout << Solution().minWindow( "a" , "aa" )<<endl;
    cout << Solution().minWindow( "aa" , "aa" )<<endl;
    cout << Solution().minWindow( "bba" , "ab" )<<endl;
    return 0;
}