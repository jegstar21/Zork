#pragma once
#include <string>
#include <vector>

class Border {   
private:
	std::string direction;
	std::string name;

public:
	virtual ~Border();
    Border();
	void setDirection(std::string direction);
	void setName(std::string name);
	std::string getDirection();
	std::string getName();
};

