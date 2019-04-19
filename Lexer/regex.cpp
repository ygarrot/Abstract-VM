//Example 1
#include <iostream>
#include <regex>
#include <string>
using namespace std;
#define N "[-]?[[:digit:]]+"

#define Z "[-]?[[:digit:]]+.[[:digit:]]+"

#define SEP "'\n'+"
int main()
{
	string input;
	regex integer("int8\\(" N  "\\)|int1\\(" N  "\\)");
	//As long as the input is correct ask for another number
	while(true)
	{
		cout<<"Give me an integer!"<<endl;
		cin>>input;
		if(!cin) break;
		//Exit when the user inputs q
		if(input=="q")
			break;
		if(regex_match(input, integer))
			cout<<"integer"<<endl;
		else
		{
			cout<<"Invalid input"<<endl;
		}
	}
}
