#include "vector_tests.hpp"
typedef int												CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>					container;
typedef NAMESPACE::vector<CURR_TYPE>::iterator			iterator;

#define SIZE 15

void		bracket_tests()
{
	std::cout << "******	BRACKET TESTS	******" << std::endl;

	int				tab[SIZE];
	for (int i = 0; i < SIZE; i++)
		tab[i] = i * i;

	container 		vec(tab, tab + SIZE);
	const int&	 	ref = vec[1];

	std::cout << ref << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	print_container(vec);

	for (int i = 0; i < SIZE; i++)
		vec[i] = i + i;
	print_container(vec);

	vec.resize(5);
	for (int i = 0; i < 5; i++)
		std::cout << vec[i] << " ";
}

void		at_tests()
{
	std::cout << "******	AT TESTS	******" << std::endl;

	int				tab[SIZE];
	for (int i = 0; i < SIZE; i++)
		tab[i] = i * i;

	container 		vec(tab, tab + SIZE);
	const int&	 	ref = vec.at(1);

	std::cout << ref << std::endl;

	

	for (int i = 0; i < SIZE; i++)
		std::cout << vec.at(i) << " ";
	std::cout << std::endl;
	print_container(vec);

	for (int i = 0; i < SIZE; i++)
		vec.at(i) = i + i;
	print_container(vec);

	vec.resize(5);
	for (int i = 0; i < 5; i++)
		std::cout << vec.at(i) << " ";

	try
	{
		vec.at(200);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}

void		front_tests()
{
	std::cout << "******	FRONT TESTS	******" << std::endl;

	int				tab[SIZE];
	for (int i = 0; i < SIZE; i++)
		tab[i] = i * i;

	container 		vec(tab, tab + SIZE);
	const int&	 	ref = vec.front();

	std::cout << ref << std::endl;
	print_container(vec);

	vec[0] = 5;
	std::cout << vec.front() << std::endl;
	print_container(vec);
	
	vec.clear();
	std::cout << vec.front() << std::endl;
	print_container(vec);

	vec.assign(iterator(tab), iterator(tab + SIZE));
	std::cout << vec.front() << std::endl;
	print_container(vec);

	vec.resize(1);
	std::cout << vec.front() << std::endl;
	print_container(vec);
	
}

void		back_tests()
{
	std::cout << "******	BACK TESTS		******" << std::endl;

	int				tab[SIZE];
	for (int i = 0; i < SIZE; i++)
		tab[i] = i * i;

	container 		vec(tab, tab + SIZE);
	const int&	 	ref = vec.back();

	std::cout << ref << std::endl;
	print_container(vec);

	vec[SIZE - 1] = 5;
	std::cout << vec.back() << std::endl;
	print_container(vec);
	
	vec.clear();
	std::cout << vec.back() << std::endl;
	print_container(vec);

	vec.assign(iterator(tab), iterator(tab + SIZE));
	std::cout << vec.back() << std::endl;
	print_container(vec);

	vec.resize(1);
	std::cout << vec.back() << std::endl;
	print_container(vec);
	
}

int main()
{
	print_time(START);

	bracket_tests();
	at_tests();
	front_tests();
	back_tests();

	print_time(END);

	return (0);
}