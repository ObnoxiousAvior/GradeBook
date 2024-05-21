#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "include/Platform.h"
#include "include/Utils.h"
#include "include/interface.h"

using namespace std;
	
void utils::queryInt(int& var)
	{
	while(true)
	{
        int tempI{};
        char temp{};
		string tempSTR; 
		
		bool wrongFlag = false;
		
		while(temp){
		std::cin >> tempSTR;
		std::cout << temp << std::endl;
		
        for(unsigned int i = 0; i<tempSTR.size(); i++)
		{
			if (!isdigit(tempSTR[i])) wrongFlag = true;
		}
		}
		if (wrongFlag)	
		{
            // wrong flag image
            interface::wrongFlag();
			tempSTR.clear();
			continue;
		}
		else 
		{
			var = std::stoi(tempSTR);
			break;
		}
		}
	}
