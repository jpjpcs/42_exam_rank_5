#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock &operator=(Warlock const &other);
		Warlock(Warlock const &other);

	public:
		Warlock(std::string const name, std::string const title);
		~Warlock();
		std::string const getName() const;
		std::string const getTitle() const;
		void	setTitle(std::string const &title);
		void	introduce() const;
};
