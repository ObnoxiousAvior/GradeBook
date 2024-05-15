#include <iostream>
#include <string>
#include <vector>

namespace utils
{
	template <typename T> void queryVar(T& var){
		std::cin >> var;
		while(getchar()!='\n');
	}
	
	template <typename T> bool checkInt(T var)
	{
		std::cout << "Please" << std::endl;
		if (std::is_same<T, int>::value)
		{
			if (var < 0) return false;
		}
		else
		{
			return false;
		}
		
		return true;
	}
	
	void queryInt(int& var, std::string text){
		while(true){
		std::cout << text << std::endl << "|";
		
		queryVar(var);
		
		if(!checkInt(var)) 
		{
			std::cout << "Please, enter the NON-NEGATIVE INTEGER value! (0,1,2,3....)" << std::endl;
			continue;
		}
		break;
		}
	}
	
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
		
	return accID;
}

}
