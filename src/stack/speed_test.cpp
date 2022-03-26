#include "stack_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	vector;
typedef ft_MutantStack<CURR_TYPE>		container;

int main()
{

	print_time(START);

	ft_MutantStack<int> iterable_stack;

	for (int i = 0; i < 100000; i++)
		iterable_stack.push(i);
	for (ft_MutantStack<int>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	while (!iterable_stack.empty())
		iterable_stack.pop();

	print_time(END);
	return (0);
}