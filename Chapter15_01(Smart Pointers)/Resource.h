#pragma once
#include<iostream>

class Resource
{
private:

public:
	int _data[100];

public:
	Resource()
	{
		std::cout << "Resource constructed" << std::endl;
	}

	~Resource()
	{
		std::cout << "Resource destroyed" << std::endl;
	}
};
