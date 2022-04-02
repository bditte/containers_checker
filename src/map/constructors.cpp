#include "map_tests.hpp"

typedef int										CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>	container;

#define SIZE 15

int main()
{
	print_time(START);

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}
	container		empty_map;
	container 		range_map(tab, tab + SIZE);
	container 		cpy_map(range_map);
	
	print_container(empty_map);
	print_container(range_map);
	print_container(cpy_map);

	print_time(END);

	return (0);
}