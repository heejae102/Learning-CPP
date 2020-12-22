#include<iostream>
using namespace std; 

/*

<접근지정자> 

public   : 클래스의 외부에서 클래스 내 멤버에 접근 가능 
private  : 클래스의 외부에서 클래스 내 멤버에 접근 불가능 
protected: 자식 클래스에서는 클래스 내 멤버에 접근 가능 

private 접근지정자로 설정된 멤버들은 클래스 외부에서 
접근이 불가능하기 때문에 해당 멤버들에 접근하고 수정할 수 있는 
access function을 개별적으로 구현해주어야 한다. 

멤버 함수에서는 접근지정자와 상관없이 같은 클래스의 
멤버 변수들에 접근할 수 있으므로, access function을 통해 
private 멤버들에 접근하는 방식으로 구현해야 한다. 
따라서 access function이 멤버 변수들을 대신해서 외부와
소통할 수 있어야하기 때문에 접근 지정자는 public으로 설정되어야 한다. 

이렇게 캡슐화하여 클래스를 관리할 경우 문제가 생겼을 때 
수정해야 할 범위가 많이 축소되어 유지보수가 쉬워진다. 
반대로 캡슐화가 이루어지지 않았을 때는 프로그램을 통제하기가 그만큼 어려워진다. 

ex) 클래스 내 멤버변수를 public으로 선언해놓고, 추후 해당 변수의 이름을 
수정한다고 할 때, 클래스의 외부에서 해당 변수를 호출한 곳을 찾아서 
일일이 수정해야 한다. 하지만 캡슐화가 되어있는 경우 클래스 내부에서만 수정하면 됨. 


※ 같은 클래스로 여러 개의 인스턴스로 만들었을 때, 
해당 인스턴스끼리는 private 멤버에 대해서도 접근이 가능하다. 

*/

class Date
{
//access specifier : 클래스 외부에서 멤버에 접근할 수 있는 접근 범위를 설정하는 지정자
//클래스에서 접근지정자는 private이 디폴트값. 
private:
	int _month;
	int _day;
	int _year;

public:
	void setDate(const int &month_input, const int &day_input, const int &year_input)
	{
		_month = month_input;
		_day = day_input;
		_year = year_input;
	}

	void setMonth(const int &month_input)	//setters
	{
		_month = month_input;
	}

	const int& getMonth()	//getters
	{
		return _day; 
	}

	//같은 클래스의 서로 다른 인스턴스끼리는 멤버에 접근이 가능하다. 
	void copyFrom(const Date &original)
	{
		_month = original._month;
		_day = original._day;
		_year = original._year;
	}
};

int main()
{
	Date today;	// {8, 4, 2025};
	today.setDate(8, 4, 2025);
	today.setMonth(10);

	Date copy;
	copy.copyFrom(today);

	return 0;
}