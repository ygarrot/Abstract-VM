#include <iostream>
int main()
{
	int *n = {1};
	int & test = *n;
	int b = test;
	(void)b;
}
