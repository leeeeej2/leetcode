#pragma once
#include <iostream>
#include <string>

class Solution {
public:
    static bool backspaceCompare(std::string S, std::string T) {
        const char* s = S.c_str();
        const char* t = T.c_str();
        
    	for(int i = 0; (s[i] != '\0'); i++)
    	{
    		if(s[i] == '#')
    		{
                S.erase(S.begin() + i);
    			if(i >0)
    			{
                    --i;
    			}
                
                S.erase(S.begin() + i);
                if (i > 0)
                {
                    --i;
                }
    		}
    	}

    	for(int j = 0; t[j] != '\0'; j++)
    	{
    		if(t[j] == '#')
    		{
                T.erase(T.begin() + j);
                if (j > 0)
                {
                    --j;
                }
                T.erase(T.begin() + j);
                if (j > 0)
                {
                    --j;
                }
    		}
    	}

        std::cout << "check " << std::endl;
        std::cout << S << std::endl;
        std::cout << T << std::endl;

        return S == T;
    }
};
