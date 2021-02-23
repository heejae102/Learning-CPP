#include<iostream>
#include"MyConstants.h"

extern int a = 123;

void test()
{
	//std::cout << "Hello " << std::endl; 

	std::cout << "In test.cpp file " << Constants::pi << " " << &Constants::pi << std::endl; 
}