#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

#define SIZE 15

int		main()
{
	print_time(START);

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec(tab, tab + SIZE);
	container   empty_vec;

	std::cout << vec.empty() << std::endl;
	std::cout << empty_vec.empty() << std::endl;

	vec.clear();
	empty_vec.clear();
	std::cout << vec.empty() << std::endl;
	std::cout << (vec == empty_vec) << std::endl;

	vec.push_back(2);
	empty_vec = vec;

	std::cout << vec.empty() << std::endl;
	std::cout << empty_vec.empty() << std::endl;

	print_time(END);
	return (0);
}