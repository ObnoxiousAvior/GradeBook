#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include "include/Platform.h"
#include "include/Utils.h"

using namespace std;
	
void utils::queryInt(int& var)
	{
	while(true)
	{
		int tempI;
		char temp;
		string tempSTR; 
		
		bool wrongFlag = false;
		
		while(temp){
		std::cin >> tempSTR;
		std::cout << temp << std::endl;
		
		for(int i = 0; i<tempSTR.size(); i++)
		{
			if (!isdigit(tempSTR[i])) wrongFlag = true;
		}
		}
		if (wrongFlag)	
		{
			std::cout << "It has to be an INTEGER NUMBER!" << std::endl;
			std::cout << "=========================================" << std::endl;
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
