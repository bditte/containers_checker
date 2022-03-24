#ifndef MAP_TESTS_HPP
# define MAP_TESTS_HPP
# include "../../include/containers_checker.hpp"

template <class T>
void	print_container(T map)
{
	typedef	typename T::iterator	t_it;

	std::cout << "SIZE : " << map.size() << std::endl;
//	Not testing max_size on map because it doesn't have to be the same
//	std::cout << "MAX_SIZE : " << map.max_size() << std::endl  << std::endl;

	std::cout << "CONTENT : "  << std::endl;
	for (t_it it = map.begin(); it != map.end(); it++)
		std::cout << it->first << std::endl;
	std::cout << std::endl;
}
#endif 