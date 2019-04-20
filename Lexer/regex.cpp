//Example 1
#include <iostream>
#include <regex>
#include <string>
using namespace std;
#define S INSTRUCTION "(" SEP INSTRUCTION ")*"

#define VALUE \
		"("\
	"int8\\("   N "\\)|"\
	"int16\\("  N "\\)|"\
	"int32\\("  N "\\)|"\
	"double\\(" Z "\\)|"\
	"float\\("  Z "\\)"\
	")"

#define INSTRUCTION \
			"push" " " VALUE\
	"|" "pop"\
	"|" "dump"\
	"|" "assert" " " VALUE\
	"|" "add"\
	"|" "sub"\
	"|" "mul"\
	"|" "div"\
	"|" "mod"\
	"|" "print"\
	"|" "exit"

#define N "[-]?[[:digit:]]+"

#define Z "[-]?[[:digit:]]+.[[:digit:]]+"

#define SEP "[\\n]+"
int main()
{
	string input;
	std::cout <<S<<std::endl;
	regex integer(S);
	//As long as the input is correct ask for another number
	/* while(true) */
	/* { */
		/* cout<<"Give me an integer!"<<endl; */
	/* 	cin>>input; */
	/* 	if(!cin) break; */
	/* 	//Exit when the user inputs q */
	/* 	if(input=="q") */
	/* 		break; */
		if(regex_match("push int32(42)\nprint", integer))
		{
			cout<<"integer"<<endl;
		}
		/* else */
		/* { */
		/* 	cout<<"Invalid input"<<endl; */
		/* } */
	/* } */
}
