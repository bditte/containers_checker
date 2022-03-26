#include "stack_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	vector;
typedef ft_MutantStack<CURR_TYPE>		container;

#define  SIZE 15

int main()
{
	print_time(START);

	container 		stack;

	std::cout << std::boolalpha << stack.empty() << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		stack.push(i);
		std::cout << "SIZE : " << stack.size();
		std::cout << " TOP : " << stack.top();
	}
	std::cout << std::boolalpha << stack.empty() << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "SIZE : " << stack.size();
		std::cout << " TOP : " << stack.top() << std::endl;;
		stack.pop();
	}
	std::cout << std::boolalpha << stack.empty() << std::endl;

	print_time(END);
	return (0);
}