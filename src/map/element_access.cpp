#include "map_tests.hpp"

typedef int										CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>	container;

#define SIZE 15

int main()
{
	std::cout << "******	CAPACITY TESTS		******" << std::endl;

	print_time(START);

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 		map(tab, tab + SIZE);

	print_container(map);

	std::cout << map[0] << std::endl;
	print_container(map);

	std::cout << map[50] << std::endl;
	print_container(map);

	std::cout << map[3] << std::endl;
	print_container(map);

	map[3] = 45;
	print_container(map);

	print_time(END);

	return (0);
}