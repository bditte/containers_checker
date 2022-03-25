#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

# include "../../include/containers_checker.hpp"


template <class T>
void	print_container(T vec)
{
	typedef	typename T::iterator	t_it;

	std::cout << "SIZE : " << vec.size() << std::endl;
	std::cout << "CAPACITY : " << vec.capacity() << std::endl;
	std::cout << "MAX_SIZE : " << vec.max_size() << std::endl  << std::endl;

	std::cout << "CONTENT : "  << std::endl;
	for (t_it it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}


/*

#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

#define SIZE 15

int		main()
{
	std::cout << "******	PUSH_BACK TESTS		******" << std::endl;
	print_time(START);

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec(tab, tab + SIZE);

	print_time(END);
	return (0);
}

*/
#endif