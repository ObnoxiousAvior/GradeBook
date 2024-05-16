#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace utils
{
	template <typename T> inline void queryVar(T& var){
		std::cin >> var;
		while(getchar()!='\n');
	}
	
	void queryMark(int& var, std::string text);
	
	template <typename T>
	int acc_log_in(T userList)
	{
		bool accFound = false;
		int accID;

		while(!accFound)
		{
			std::cout << "Enter your login: ";
			
			std::string log;
			queryVar(log);

			for(int i = 0; i < userList.size(); ++i)
			{
				if((userList[i]).getLogin().compare(log) == 0) 
					{
						accFound = true;
						accID = i;
						break;
					}
			}
			if(!accFound) std::cout << "Couldn't find the account. Try again!" << std::endl;
		}
		
		bool passCorrect = false;
		
		while(!passCorrect)
		{
			std::cout << "Enter your password: ";
		
			std::string pass;
			queryVar(pass);
		
			if(userList[accID].getPassword().compare(pass) == 0) 
			{
				passCorrect = true;
				break;
			} 
			else std::cout << "Wrong password. Try again!" << std::endl;
	}
	
	system("clear");
	return accID;
}

}
