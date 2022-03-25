#include "vector_tests.hpp"
typedef int								CURR_TYPE;
typedef NAMESPACE::vector<CURR_TYPE>	container;

#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT 300000

int main()
{
	print_time(START);

	srand(215);

	NAMESPACE::vector<std::string> vector_str;
	NAMESPACE::vector<int> vector_int;
	NAMESPACE::vector<Buffer> vector_buffer;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}

	NAMESPACE::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}

	print_time(END);
}