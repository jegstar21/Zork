#pragma once
#include <string>
#include <vector>

class Turnon {   
private:
	std::string print;
	std::string action;

public:
	virtual ~Turnon();
    Turnon();
	void setPrint(std::string print);
	void setAction(std::string action);
	std::string getPrint();
	std::string getAction();
};
