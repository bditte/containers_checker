#ifndef VECTOR_TESTS_HPP
# define VECTOR_TESTS_HPP

#include "../../include/containers_checker.hpp"
/*

*/
template <class T>
void	print_container(T vec)
{
	typedef	typename T::iterator	t_it;

	std::cout << "SIZE : " << vec.size() << std::endl;
	std::cout << "CAPACITY : " << vec.capacity() << std::endl;
	std::cout << "MAX_SIZE : " << vec.max_size() << std::endl  << std::endl;

	std::cout << "CONTENT : "  << std::endl;
	for (t_it it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;
}

#endif