#include "map_tests.hpp"

typedef int										CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>	container;

#define COUNT 100000

int main()
{
	print_time(START);
	container 	map_int;

	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(NAMESPACE::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < COUNT; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	print_container(map_int);
	
	print_time(END);

	return (0);
}