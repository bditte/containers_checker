#ifndef STACK_TESTS_HPP
# define STACK_TESTS_HPP

#include <list>

# include "../../include/containers_checker.hpp"

template<typename T, typename Container = NAMESPACE::vector<T> >
class ft_MutantStack : public NAMESPACE::stack<T, Container>
{
public:
	ft_MutantStack(const Container &cntr = Container() ) { this->c = cntr; }
	ft_MutantStack(const ft_MutantStack<T, Container>& src) { *this = src; }
	ft_MutantStack<T, Container>& operator=(const ft_MutantStack<T, Container>& rhs) 
	{
		this->c = rhs.c;
		return *this;
	}
	~ft_MutantStack() {}

	typedef typename NAMESPACE::stack<T, Container>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

template <class T>
void	print_container(T vec)
{
	typedef	typename T::iterator	t_it;

	std::cout << "SIZE : " << vec.size() << std::endl;
	
	std::cout << "CONTENT : "  << std::endl;
	for (t_it it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << std::endl;
}

#endif