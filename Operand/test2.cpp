#include <iostream>
#include <cfenv>
#include <cmath>
#include <cerrno>
#include <cstring>
/* #pragma STDC FENV_ACCESS ON */
int main()
{

	std::cout << "MATH_ERRNO is "
		<< (math_errhandling & MATH_ERRNO ? "set" : "not set") << '\n'
		<< "MATH_ERREXCEPT is "
		<< (math_errhandling & MATH_ERREXCEPT ? "set" : "not set") << '\n';
	std::feclearexcept(FE_ALL_EXCEPT);
	errno = 0;
	/* std::cout <<  "log(0) = " << std::log(0) << '\n'; */
	std::cout << "sqrt(-1) = " << std::numeric_limits<double>::min() + static_cast<double>(3.4) << '\n';
	if(std::fetestexcept(FE_INEXACT)) {
		std::cout << "invalid result reported\n";
	} else {
		std::cout << "invalid result not reported\n";
	}
	std::cout << "errno = ERANGE (" << std::strerror(errno) << ")\n";
}
