#include "map_tests.hpp"

typedef int													CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>				container;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::iterator		iterator;

#define SIZE 15

void 		clear_tests()
{
	std::cout << "******	CLEAR TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map1(tab, tab + SIZE);
	container 	map2;

	print_container(map1);
	print_container(map2);

	map1.clear();
	map2.clear();
	print_container(map1);
	print_container(map2);
}

void		swap_tests()
{
	std::cout << "******	SWAP TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container	map(tab, tab + SIZE);
	container 	cpy_map(map);
	container 	empty_map;

	print_container(map);
	print_container(cpy_map);
	print_container(empty_map);

	map.swap(cpy_map);
	print_container(map);
	print_container(cpy_map);

	map.swap(empty_map);
	print_container(map);
	print_container(cpy_map);
	print_container(empty_map);

	map.insert(NAMESPACE::make_pair(1, 5));
	map.swap(empty_map);
	print_container(map);
	print_container(cpy_map);
	print_container(empty_map);

	map.erase(map.begin(), map.end());
	empty_map.erase(empty_map.begin());
	print_container(map);
	print_container(cpy_map);
	print_container(empty_map);

}

void		erase_tests()
{
	std::cout << "******	INSERT TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container	map(tab, tab + SIZE);
	print_container(map);

	map.erase(map.begin());
	print_container(map);

	map.erase(1);
	print_container(map);

	map.erase(8000);
	map.erase(1);
	print_container(map);

	map.erase(++map.begin(), --map.end());
	print_container(map);

	map.erase(map.begin(), map.end());
	print_container(map);

}

void		insert_tests()
{
	std::cout << "******	INSERT TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container	map(tab, tab + SIZE);
	container 	cpy_map;

	print_container(map);

	cpy_map.insert(map.begin(), map.end());
	print_container(map);

	map.insert(cpy_map.begin(), cpy_map.end());
	print_container(map);
	print_container(cpy_map);

	map.insert((map.end()--)--, NAMESPACE::make_pair(5, 5));
	print_container(map);

	iterator ite = map.begin();
	for (size_t i = 0; i < map.size(); i += 2)
	{
		map.insert((ite++)++, NAMESPACE::make_pair(i, 100));
	}

	print_container(map);
}

int main()
{

	print_time(START);

	insert_tests();
	erase_tests();
	swap_tests();
	clear_tests();

	print_time(END);

	return (0);
}