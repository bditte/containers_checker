#include "vector_tests.hpp"

typedef int										CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>			container;
typedef container::iterator						ite;
typedef container::const_iterator				const_ite;
typedef container::reverse_iterator				rev_ite;
typedef container::const_reverse_iterator		const_rev_ite;

template <class Ite>
void	check_iterator(Ite it)
{
	std::cout << "Iterator value : "<< *it << std::endl;
}

template <class Ite>
void	check_two_iterators(Ite a, Ite b)
{
	std::cout << "COMPARING OPERATORS\n";

	print_bool(a==b);
	print_bool(a!=b);
	print_bool(a<=b);
	print_bool(a>=b);
	print_bool(a<b);
	print_bool(a>b);
}

void	iterator_tests()
{
	std::cout << "******	ITERATOR TESTS		******" << std::endl;
	
	int			tab[15];

	for (int i = 0; i < 15; i++)
		tab[i] = i * 6;
	container vec(tab, tab + 15);

	ite first = vec.begin();
	ite last = vec.end();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	first += 5;
	last -= 3;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

	first[0] = 25;
	last[0] = 98;
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
	int			tab[15];

	for (int i = 0; i < 15; i++)
		tab[i] = i * 6;
	container vec(tab, tab + 15);

	const_ite first = vec.begin();
	const_ite last = vec.end();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	first += 5;
	last -= 3;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

/*	first[0] = 25;	Should not compile
	last[0] = 98;
*/
	last = first;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);
}

void		reverse_iterator_tests()
{
	std::cout << "******	REVERSE_ITERATOR TESTS		******" << std::endl;
	
	int			tab[15];

	for (int i = 0; i < 15; i++)
		tab[i] = i * 6;
	container vec(tab, tab + 15);

	rev_ite first = vec.rbegin();
	rev_ite last = vec.rend();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	first += 5;
	last -= 3;
	check_two_iterators(first, last);
	check_iterator(first);
	check_iterator(last);

}

void		const_reverse_iterator_tests()
{
	std::cout << "******	CONST_REVERSE_ITERATOR TESTS		******" << std::endl;
	
	int			tab[15];

	for (int i = 0; i < 15; i++)
		tab[i] = i * 6;
	container vec(tab, tab + 15);

	const_rev_ite first = vec.rbegin();
	const_rev_ite last = vec.rend();

	check_two_iterators(first, last);
	check_iterator(first);
	check_two_iterators(++first, --last);
	check_iterator(first);
	check_iterator(last);

	first += 5;
	last -= 3;
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