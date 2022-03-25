#include "vector_tests.hpp"
typedef int												CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>					container;
typedef NAMESPACE::vector<CURR_TYPE>::iterator			iterator;

#define SIZE 15

void		equal_tests()
{
	std::cout << "******	EQUAL TESTS		******" << std::endl;
	
	container 	vec1;
	container 	vec2;

	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;

	vec1.push_back(1);
	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;

	vec2.push_back(1);
	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;


	vec1.reserve(10);
	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;

	vec1.clear();
	vec2.clear();
	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;

	for (int i = 0; i < SIZE; i++)
	{
		vec1.push_back(i);
		vec2.push_back(i);
	}

	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;
	
	vec1.resize(2);
	std::cout << std::boolalpha << "== : " << (vec1 == vec2) << std::endl;
	std::cout << std::boolalpha << "!= : " << (vec1 != vec2) << std::endl;

}

void		inferior_superior_tests()
{
	std::cout << "******	INFERIOR SUPERIOR TESTS		******" << std::endl;
	
	container 	vec1(5, 5);
	container 	vec2(5, 5);

	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;

	vec1[4] = 6;
	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;


	vec1[4] = 4;
	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;

	vec1.clear();
	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;

	for (int i = 0; i < SIZE; i++)
		vec1[i] = i;
	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;

	vec2.resize(1);
	std::cout << std::boolalpha << "<  : " << (vec1 < vec2) << std::endl;
	std::cout << std::boolalpha << "<= : " << (vec1 <= vec2) << std::endl;
	std::cout << std::boolalpha << "> : " << (vec1 > vec2) << std::endl;
	std::cout << std::boolalpha << ">= : " << (vec1 >= vec2) << std::endl;


}

int main()
{
	print_time(START);

	equal_tests();
	inferior_superior_tests();

	print_time(END);
	return (0);
}