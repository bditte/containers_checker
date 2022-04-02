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

	NAMESPACE::map<CURR_TYPE, CURR_TYPE>::key_compare 	mycomp = map.key_comp();

	int highest = map.rbegin()->first;

	iterator ite = map.begin();
	do
	{
		std::cout << ite->first << " " << ite->second << std::endl;
	} while (mycomp((*ite++).first, highest));
	

}

void 		value_comp_tests()
{
	std::cout << "******	VALUE_COMP TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}
	container 	map(tab, tab + SIZE);

	NAMESPACE::pair<int, int> highest = *map.rbegin();

	iterator ite = map.begin();
	do
	{
		std::cout << ite->first << " " << ite->second << std::endl;
	} while (map.value_comp()(*ite++, highest));
}

int main()
{

	print_time(START);

	key_comp_tests();
	value_comp_tests();

	print_time(END);
	return (0);
}