#pragma once
#include<string>
#include "Position2D.h"

class Monster
{
private:
	std::string _name;
	Position2D _location;
	//int _x;		
	//int _y; 

public:
	Monster(const std::string name_in, const Position2D &pos_in)
		: _name(name_in), _location(pos_in) {}

	void moveTo(const Position2D &pos_target)
	{
		_location.set(pos_target);
	}

	friend std::ostream &operator << (std::ostream &out, Monster &monster)
	{
		out << monster._name << " " << monster._location;
		return out;
	}
};

