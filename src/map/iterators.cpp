#include "map_tests.hpp"

typedef int										CURR_TYPE;
typedef NAMESPACE::map<CURR_TYPE, CURR_TYPE>	container;
typedef container::iterator						ite;
typedef container::const_iterator				const_ite;
typedef container::reverse_iterator				rev_ite;
typedef container::const_reverse_iterator		const_rev_ite;

#define SIZE 15


template <class Ite>
void	check_iterator(Ite it)
{
	std::cout << "Iterator value : "<< (*it).first << std::endl;
}

template <class Ite>
void	check_two_iterators(Ite a, Ite b)
{
	std::cout << "COMPARING OPERATORS\n";

	print_bool(a==b);
	print_bool(a!=b);
	/*print_bool(a<=b);
	print_bool(a>=b);
	print_bool(a<b);	Should not compile
	print_bool(a>b);
	*/
}

void	iterator_tests()
{
	std::cout << "******	ITERATOR TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}

	container map(tab, tab + 15);

	ite first = map.begin();
	ite last = map.end();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

//	first += 5;	Should not compile (because map uses bidirectional iterators)
//	last -= 3;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

	last = first;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

}

void	const_iterator_tests()
{
	std::cout << "******	CONST_ITERATOR TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}
	container map(tab, tab + 15);

	const_ite first = map.begin();
	const_ite last = map.end();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

	last = first;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);
}

void		reverse_iterator_tests()
{
	std::cout << "******	REVERSE_ITERATOR TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}
	
	container map(tab, tab + 15);

	rev_ite first = map.rbegin();
	rev_ite last = map.rend();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

}

void		const_reverse_iterator_tests()
{
	std::cout << "******	CONST_REVERSE_ITERATOR TESTS		******" << std::endl;
	
	NAMESPACE::pair<CURR_TYPE, CURR_TYPE> 	tab[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		tab[i] = NAMESPACE::make_pair(SIZE - i, i * i);
	}
	container map(tab, tab + 15);

	const_rev_ite first = map.rbegin();
	const_rev_ite last = map.rend();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

}

int main()
{
	print_time(START);
	
	iterator_tests();
	const_iterator_tests();
	reverse_iterator_tests();
	const_reverse_iterator_tests();

	print_time(END);

	return (0);
}