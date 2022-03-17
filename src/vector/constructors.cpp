#include "vector_tests.hpp"
#include "vector.hpp"

typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

int		constructors()
{
	container	vec(5);
	container	empty_vec;
	container	copy_vec(vec);

	print_container(vec);
	print_container(empty_vec);
	print_container(copy_vec);

	return (0);
}

int main()
{
	return (constructors());
}