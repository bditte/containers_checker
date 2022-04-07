#include "map_tests.hpp"

typedef int															CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>						container;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::iterator				iterator;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>::const_iterator		const_iterator;

#define SIZE 15

template <class Ite>
void	print_iterator(Ite it)
{
	std::cout << "Ite : "<< (*it).first << " " << (*it).second << std::endl;
}
template <class Ite>
void 	print_ite_pair(NAMESPACE::pair<Ite, Ite> it_pair)
{
	if (it_pair.first == it_pair.second)
	{
		std::cout << "RANGE IS NULL" << std::endl;
		return ;
	}
	print_iterator(it_pair.first);
	print_iterator(it_pair.second);
}

void 		find_tests()
{
	std::cout << "******	FIND TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);

	iterator	it = map.find(3);
	print_iterator(it);
	print_container(map);

	(*it).second = -9;
	print_iterator(it);
	print_container(map);

	it = map.find(8456);
	print_iterator(--it); // Checks if it correctly returns end
	print_container(map);

	const_iterator	c_it = map.find(6);
	print_iterator(c_it);
	print_container(map);

	c_it = map.find(615123);
	print_iterator(--c_it);
	print_container(map);

}

void 		count_tests()
{
	std::cout << "******	COUNT TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);

	int res = map.count(5);
	std::cout << res << std::endl;

	print_container(map);

	map.erase(5);
	res = map.count(5);
	std::cout << res << std::endl;
	print_container(map);

	res = map.count(500);
	std::cout << res << std::endl;
	print_container(map);

	map.erase(map.begin(), --map.end());
	for (int i = 0; i < SIZE; i++)
	{
		res = map.count(i);
		std::cout << res << std::endl;
	}
	print_container(map);
}

void 		lower_bound_tests()
{
	std::cout << "******	LOWER_BOUNDS TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);

	iterator 		it = map.lower_bound(8);
	const_iterator 	c_it = map.lower_bound(8);

	print_iterator(it);
	print_iterator(c_it);

	it = map.lower_bound(800);
	c_it = map.lower_bound(800);

	print_iterator(--it);	// Checks if it correctly returns end
	print_iterator(--c_it);

	it = map.lower_bound(1);
	c_it = map.lower_bound(1);

	print_iterator(it);
	print_iterator(c_it);
}

void 		upper_bound_tests()
{
	std::cout << "******	UPPER_BOUNDS TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);

	iterator 		it = map.upper_bound(8);
	const_iterator 	c_it = map.upper_bound(8);

	print_iterator(it);
	print_iterator(c_it);

	it = map.upper_bound(800);
	c_it = map.upper_bound(800);

	print_iterator(--it);	// Checks if it correctly returns end
	print_iterator(--c_it);

	it = map.upper_bound(1);
	c_it = map.upper_bound(1);

	print_iterator(it);
	print_iterator(c_it);
}


void 		equal_range_tests()
{
	std::cout << "******	EQUAL_RANGE TESTS		******" << std::endl;

	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container 	map(tab, tab + SIZE);
	
	NAMESPACE::pair<iterator, iterator>					it_pair;
	NAMESPACE::pair<const_iterator, const_iterator>		c_it_pair;
	
	it_pair = map.equal_range(8);
	c_it_pair = map.equal_range(8);

	print_ite_pair(it_pair);
	print_ite_pair(c_it_pair);

	it_pair = map.equal_range(800);
	c_it_pair = map.equal_range(800);

	print_ite_pair(it_pair);
	print_ite_pair(c_it_pair);

	it_pair = map.equal_range(1);
	c_it_pair = map.equal_range(1);

	print_ite_pair(it_pair);
	print_ite_pair(c_it_pair);

}

int main()
{

	print_time(START);

	find_tests();
	count_tests();
	lower_bound_tests();
	upper_bound_tests();
	equal_range_tests();
	
	print_time(END);
	return (0);
}