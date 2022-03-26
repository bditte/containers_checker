#include "stack_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	vector;
typedef ft_MutantStack<CURR_TYPE>		container;

#define  SIZE 15

template <class Stack>
void 		operator_tests(Stack& a, Stack& b)
{
	std::cout << std::boolalpha << (a == b) << std::endl;
	std::cout << std::boolalpha << (a != b) << std::endl;
	std::cout << std::boolalpha << (a <= b) << std::endl;
	std::cout << std::boolalpha << (a < b) << std::endl;
	std::cout << std::boolalpha << (a >= b) << std::endl;
	std::cout << std::boolalpha << (a > b) << std::endl << std::endl;
}

int main()
{
	print_time(START);

	std::list<int>		lst1(10, 1);
	std::list<int>		lst2;
	vector 				vec1(10, 1);
	vector 				vec2;

	ft_MutantStack<int, vector> 			vec_stack1(vec1);
	ft_MutantStack<int, vector> 			vec_stack2(vec2);
	ft_MutantStack<int, std::list<int> > 	lst_stack1(lst1);
	ft_MutantStack<int, std::list<int> > 	lst_stack2(lst2);

	operator_tests(vec_stack1, vec_stack2);
	operator_tests(lst_stack1, lst_stack2);

	for (int i = 0; i < 10; i++)
		vec_stack2.push(1);
	for (int i = 0; i < 10; i++)
		lst_stack2.push(1);

	operator_tests(vec_stack1, vec_stack2);
	operator_tests(lst_stack1, lst_stack2);

	vec_stack1.pop();
	lst_stack1.pop();

	operator_tests(vec_stack1, vec_stack2);
	operator_tests(lst_stack1, lst_stack2);

	while (!vec_stack1.empty())
		vec_stack1.pop();
	while (!lst_stack1.empty())
		lst_stack1.pop();

	operator_tests(vec_stack1, vec_stack2);
	operator_tests(lst_stack1, lst_stack2);

	while (!vec_stack2.empty())
		vec_stack2.pop();
	while (!lst_stack2.empty())
		lst_stack2.pop();
		
	operator_tests(vec_stack1, vec_stack2);
	operator_tests(lst_stack1, lst_stack2);


	print_time(END);
	return (0);
}