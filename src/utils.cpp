#include <iostream>
#include <string>

#include "include/Utils.h"

using namespace std;
	
void utils::queryMark(int& var, string text){
	while(true){
	cout << text << endl << "|";
	
	queryVar(var);
	
	cout << var << endl;
	
	if(var<2 || var>5) 
	{
		cout << "Please, enter a INTEGER value from 2 to 5!" << endl;
		continue;
	}
	break;
	}
}
