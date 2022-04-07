#include "map_tests.hpp"

typedef int													CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>				container;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::iterator		iterator;

#define COUNT 300000

int main()
{

	print_time(START);
	srand(65);

	container map;

	for (int i = 0; i < COUNT; i++)
		map.insert(NAMESPACE::make_pair(rand(), rand()));


	while (!map.empty())
		map.erase(map.begin());

	print_container(map);

	print_time(END);
	return (0);
}