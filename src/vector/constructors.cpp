#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

int		main()
{
	print_time(START);
	int			tab[15];

	for (int i = 0; i < 15; i++)
		tab[i] = i * 6;
	
	//Testing all 4 constructors
	container	vec(5);
	container	empty_vec;
	container	copy_vec(vec);
	container 	range_vec(tab, tab + 15);

	print_container(vec);
	print_container(empty_vec);
	print_container(copy_vec);
	print_container(range_vec);

	//Testing assignement operator
	vec = range_vec; 

	print_container(vec);
	print_container(range_vec);

	print_time(END);
	return (0);
}
