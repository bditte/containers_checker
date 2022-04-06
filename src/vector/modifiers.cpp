#include "vector_tests.hpp"
typedef int												CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>					container;
typedef NAMESPACE::vector<CURR_TYPE>::iterator			iterator;

#define SIZE 15

void	assign_tests()
{

	std::cout << "******	ASSIGN TESTS	******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec;
	container 	empty_vec;

	vec.assign(1, 1);
	print_container(vec);

	vec.assign(iterator(tab), iterator(tab + SIZE));
	print_container(vec);

	vec.assign(1, 1);
	print_container(vec);

	vec.assign(empty_vec.begin(), empty_vec.end());
	print_container(vec);
	print_container(empty_vec);

	vec.assign(100, 5);
	print_container(vec);

	vec.assign(200, 5);
	print_container(vec);

	vec.assign(201, 5);
	print_container(vec);

	vec.assign(0, 5);
	print_container(vec);

}

void		push_back_tests()
{
	std::cout << "******	PUSH_BACK TESTS		******" << std::endl;

	container 	vec1;
	container 	vec2;

	vec1.push_back(1);
	print_container(vec1);


	vec1.push_back(2);
	print_container(vec1);

	vec1.push_back(3);
	print_container(vec1);

	vec1.clear();
	vec1.push_back(4);
	print_container(vec1);

	vec2.reserve(10);
	vec2.push_back(1);
	print_container(vec2);
}

void		pop_back_tests()
{
	std::cout << "******	POP_BACK TESTS		******" << std::endl;
	
	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec(tab, tab + SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		print_container(vec);
		vec.pop_back();
	}
}

void		insert_tests()
{
	std::cout << "******	INSERT TESTS		******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec;
	container 	cpy_vec;

	vec.insert(vec.begin(), iterator(tab), iterator(tab + SIZE));
	print_container(vec);

	cpy_vec.insert(cpy_vec.begin(), vec.begin(), vec.end());
	print_container(vec);

	vec.insert(vec.begin() + 3, cpy_vec.begin(), cpy_vec.end());
	print_container(vec);
	print_container(cpy_vec);

	vec.insert(vec.end() - 2, 5, 5);
	print_container(vec);

	for (size_t i = 0; i < vec.size(); i += 2)
	{
		vec.insert(vec.begin() + i, 100);
	}

	print_container(vec);

	vec.insert(vec.begin() + vec.size() / 2, 1000, 5);
	print_container(vec);

	vec.insert(vec.begin() + vec.size() / 2, 1003, 5);
	print_container(vec);

	vec.insert(vec.begin() + vec.size() / 2, 1005, 5);
	print_container(vec);

	vec.insert(vec.begin() + vec.size() / 2, 5005, 5);
	print_container(vec);
}

void		erase_tests()
{
	std::cout << "******	ERASE TESTS		******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec(tab, tab + SIZE);

	vec.erase(vec.begin() + 5); 
	print_container(vec);

	vec.erase(vec.begin(), vec.end());
	print_container(vec);

	vec.assign(iterator(tab), iterator(tab + SIZE));

	while (!vec.empty())
		vec.erase(vec.begin());
	print_container(vec);
}

void		swap_tests()
{
	std::cout << "******	SWAP TESTS		******" << std::endl;

	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec1(tab, tab + SIZE);
	container 	vec2(5, 5);

	vec1.swap(vec2);
	print_container(vec1);
	print_container(vec2);
	
	vec2.swap(vec1);
	print_container(vec1);
	print_container(vec2);

	vec2.erase(vec2.begin(), vec2.end());
	vec1.swap(vec2);
	print_container(vec1);
	print_container(vec2);

}

void		clear_tests()
{
	std::cout << "******	CLEAR TESTS		******" << std::endl;
	
	int			tab[SIZE];

	for (int i = 0; i < SIZE; i++)
		tab[i] = i * 6;

	container	vec1(tab, tab + SIZE);
	container 	vec2(1, 1);

	vec1.clear();
	vec2.clear();
	print_container(vec1);
	print_container(vec2);
}

int main()
{

	print_time(START);

	assign_tests();
	push_back_tests();
	pop_back_tests();
	insert_tests();
	erase_tests();
	swap_tests();
	clear_tests();

	print_time(END);
	return (0);
}