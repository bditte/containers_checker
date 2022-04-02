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
		std::cout << it->first << it->second << std::endl;
	std::cout << std::endl;
}
/*
#include "map_tests.hpp"

typedef int													CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>				container;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::iterator		iterator;

#define SIZE 15

void 		key_comp_tests()
{
	std::cout << "******	KEY_COMP TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);

}

int main()
{

	print_time(START);

	key_comp_tests();

	print_time(END);
	return (0);
}
*/
#endif 