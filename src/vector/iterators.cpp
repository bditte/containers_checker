#include "vector_tests.hpp"

typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;
typedef container::iterator				ite;
typedef container::const_iterator		const_ite;

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

void	check_const_iterators()
{
	std::cout << std::endl << "NOW CHECKING CONST_ITERATORS" << std::endl;
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

int main()
{
	print_time(START);
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

	check_const_iterators();

	print_time(0);
	return (0);
}