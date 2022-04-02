#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

#define SIZE 15

void	empty_tests()
{
	std::cout << "******	EMPTY TESTS	******" << std::endl;

	container 	vec;
	
	std::cout << "Empty : " << vec.empty() << std::endl;
	print_container(vec);

	vec.push_back(5);
	std::cout << "Empty : " << vec.empty() << std::endl;
	print_container(vec);

	vec.erase(vec.begin());
	std::cout << "Empty : " << vec.empty() << std::endl;
	print_container(vec);

	vec.reserve(50);
	std::cout << "Empty : " << vec.empty() << std::endl;
	print_container(vec);

	vec.resize(10);
	std::cout << "Empty : " << vec.empty() << std::endl;
	print_container(vec);
}

void	resize_tests()
{
	std::cout << "******	RESIZE TESTS	******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec(tab, tab + SIZE);
	print_container(vec);

	vec.resize(2);
	print_container(vec);

	vec.resize(100);
	print_container(vec);

	try
	{
		std::cout << "EXPECTING AN EXCEPTION TO BE THROWN : \n";
		vec.resize(vec.max_size() + 3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	print_container(vec);

}

void	reserve_tests()
{
	std::cout << "******	RESERVE TESTS	******" << std::endl;

	container 	empty_vec;
	container 	vec(5);

	empty_vec.reserve(1);
	vec.reserve(1);

	print_container(empty_vec);
	print_container(vec);

	empty_vec.reserve(5);
	vec.reserve(5);

	print_container(empty_vec);
	print_container(vec);

	empty_vec.reserve(6);
	vec.reserve(6);

	print_container(empty_vec);
	print_container(vec);

	vec.push_back(5);
	print_container(vec);

	for (int i = 0; i < 5; i++)
		vec.push_back(i);
	
	empty_vec.reserve(2);
	vec.reserve(2);

	print_container(empty_vec);
	print_container(vec);

	try
	{
		vec.reserve(vec.max_size() + 10);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int		main()
{
	print_time(START);

	//There is no size/capacity test since they are checked in every test

	resize_tests();
	reserve_tests();
	empty_tests();

	print_time(END);
	return (0);
}
