#ifndef CONTAINERS_CHECKER_HPP
# define CONTAINERS_CHECKER_HPP

# include <ctime>
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <stdlib.h>

# include <vector>
# include <map>
# include <stack>

# include "vector.hpp"
# include "map.hpp"
# include "stack.hpp"

# define XSTR(x) STR(x)
# define STR(x) #x

# define START 1
# define END 0

std::string	dbl_to_str(const double n)
{
	std::stringstream ss;
	ss << n;
	return (ss.str());
}

void	print_red(std::string str)
{
	std::cerr << "\033[1;31m" << str << "\033[0m";
}

void	print_green(std::string str)
{
	std::cerr << "\033[0;32m" << str << " \033[0m";
}


void	print_time_diffs(double std_time, double ft_time)
{
	double	ratio = ft_time / std_time;

	std::cerr << "TIME ";
	if (ratio > 20.0)
		print_red("[KO] TOO SLOW ");
	else if (ratio > 1.0)
		print_green("[OK] SLOWER ");
	else
		print_green("[GG] FASTER ");
}

void	print_time(int start)
{
	static clock_t 	start_time = clock();

	if (start)
		return ;

	clock_t	end_time = clock();
	double total_time = double(end_time - start_time) / double(CLOCKS_PER_SEC);
	if ( !strcmp(XSTR(NAMESPACE), "std"))
	{
		std::ofstream	output;
		output.open("time");
		output << std::fixed << total_time << std::endl;
		output.close();
	}
	else
	{
		std::ifstream	input;
		input.open("time");
		double std_time;
		input >> std_time;
		input.close();
		print_time_diffs(std_time, total_time);
	}
	
}

void	print_bool(bool a)
{
	std::cout << a << " ";
}

#endif