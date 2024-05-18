#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Platform.h"
#include "interface.h"

namespace utils
{
	template <typename T> 
	void queryVar(T& var){
		std::cin >> var;
		while(getchar()!='\n');
	}

	
	void queryInt(int& var);
	
	template <typename T>
	int acc_log_in(T userList)
	{
		bool accFound = false;
        int accID;

		while(!accFound)
		{
            std::cout << "| Enter your login: ";
			std::string log;
			std::getline(std::cin,log);

			for(int i = 0; i < userList.size(); ++i)
			{
				if((userList[i]).getLogin().compare(log) == 0) 
					{
						accFound = true;
						accID = i;
						break;
					}
			}
            if(!accFound) interface::wrongLogin();
		}
		
		bool passCorrect = false;
		
		while(!passCorrect)
		{
            std::cout << "| Enter your password: ";
		
			std::string pass;
			std::getline(std::cin,pass);
		
			if(userList[accID].getPassword().compare(pass) == 0) 
			{
				passCorrect = true;
				break;
			} 
            else interface::wrongPassword();
	}
	
	system(CLEARSCR);
	return accID;
}

}
