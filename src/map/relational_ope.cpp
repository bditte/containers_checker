#include "map_tests.hpp"

typedef int															CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>						container;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::iterator				iterator;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::const_iterator		const_iterator;

#define SIZE 15

template <class Map>
void 		operator_tests(Map& a, Map& b)
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

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 		map1(tab, tab + SIZE);
	container 		map2;

	operator_tests(map1, map2);

	map2.insert(map1.begin(), map1.end());
	operator_tests(map1, map2);

	map1.erase(map1.begin());

	operator_tests(map1, map2);

	map1.erase(map1.begin(), map1.end());
	operator_tests(map1, map2);

	map1.insert(map2.begin(), map2.end()--);
	operator_tests(map1, map2);

	map1.erase(map1.begin(), map1.end());
	map2.erase(map2.begin(), map2.end());
	operator_tests(map1, map2);

	print_time(END);
	return (0);
}