#include <iostream>
#include <string>
#include <variant>
#include <vector>

struct MyVisitor
{
	template<class T>
		void operator()(T& _in){_in += _in;}
};

int main()
{    
	auto lambdaPrintVisitor = [](auto&& _in){std::cout << _in;};   
	std::vector<std::variant<int, double, std::string>> variantCollection;
	variantCollection.emplace_back(1);
	variantCollection.emplace_back(2.2);
	variantCollection.emplace_back("foo");

	// print them
	for (const auto& nextVariant : variantCollection)
	{
		std::visit(lambdaPrintVisitor, nextVariant);
		std::cout << " ";
	}
	std::cout << std::endl;

	// double them
	for(auto& nextVariant : variantCollection)
	{
		std::visit(MyVisitor{}, nextVariant);
	}

	// print again
	for (const auto& nextVariant : variantCollection)
	{
		std::visit(lambdaPrintVisitor, nextVariant);
		std::cout << " ";
	}
	std::cout << std::endl;

}
