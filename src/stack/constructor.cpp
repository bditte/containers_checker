#include "stack_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	vector;
typedef ft_MutantStack<CURR_TYPE>		container;

int main()
{
	print_time(START);

	vector 		vec(5, 5);
	std::list<int> 			lst(5, 5);
	ft_MutantStack<CURR_TYPE, std::list<int> >		lst_stack(lst);
	ft_MutantStack<int, vector >				vec_stack(vec);
	container 	empty_stack;


	std::cout << std::boolalpha << empty_stack.empty() << std::endl;
	print_container(empty_stack);
	print_container(vec_stack);
	print_container(lst_stack);

	print_time(END);
	return (0);
}