#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

#define SIZE 15

void swap_tests()
{
	std::cout << "******	SWAP TESTS		******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec1(tab, tab + SIZE);
	container 	vec2(5, 5);

	swap(vec1, vec2);
	print_container(vec1);
	print_container(vec2);
	
	swap(vec1, vec2);
	print_container(vec1);
	print_container(vec2);

	vec2.erase(vec2.begin(), vec2.end());
	swap(vec1, vec2);
	print_container(vec1);
	print_container(vec2);
}


int main()
{

	print_time(START);

	swap_tests();

	print_time(END);
	return (0);
}
