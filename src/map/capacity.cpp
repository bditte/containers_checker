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

	container 		empty_map;
	container 		map(tab, tab + SIZE);


	std::cout << std::boolalpha << empty_map.empty() << " " << map.empty() << std::endl;
	print_container(empty_map);
	print_container(map);

	map.erase(45);
	map.erase(map.begin());

	std::cout << std::boolalpha << empty_map.empty() << " " << map.empty() << std::endl;
	print_container(empty_map);
	print_container(map);

	map.insert(NAMESPACE::make_pair(0, 35));
	map.erase(map.begin(), map.end());

	std::cout << std::boolalpha << empty_map.empty() << " " << map.empty() << std::endl;
	print_container(empty_map);
	print_container(map);

	print_time(END);

	return (0);
}