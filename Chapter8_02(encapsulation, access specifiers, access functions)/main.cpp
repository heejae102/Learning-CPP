#include<iostream>
using namespace std; 

/*

<����������> 

public   : Ŭ������ �ܺο��� Ŭ���� �� ����� ���� ���� 
private  : Ŭ������ �ܺο��� Ŭ���� �� ����� ���� �Ұ��� 
protected: �ڽ� Ŭ���������� Ŭ���� �� ����� ���� ���� 

private ���������ڷ� ������ ������� Ŭ���� �ܺο��� 
������ �Ұ����ϱ� ������ �ش� ����鿡 �����ϰ� ������ �� �ִ� 
access function�� ���������� �������־�� �Ѵ�. 

��� �Լ������� ���������ڿ� ������� ���� Ŭ������ 
��� �����鿡 ������ �� �����Ƿ�, access function�� ���� 
private ����鿡 �����ϴ� ������� �����ؾ� �Ѵ�. 
���� access function�� ��� �������� ����ؼ� �ܺο�
������ �� �־���ϱ� ������ ���� �����ڴ� public���� �����Ǿ�� �Ѵ�. 

�̷��� ĸ��ȭ�Ͽ� Ŭ������ ������ ��� ������ ������ �� 
�����ؾ� �� ������ ���� ��ҵǾ� ���������� ��������. 
�ݴ�� ĸ��ȭ�� �̷������ �ʾ��� ���� ���α׷��� �����ϱⰡ �׸�ŭ ���������. 

ex) Ŭ���� �� ��������� public���� �����س���, ���� �ش� ������ �̸��� 
�����Ѵٰ� �� ��, Ŭ������ �ܺο��� �ش� ������ ȣ���� ���� ã�Ƽ� 
������ �����ؾ� �Ѵ�. ������ ĸ��ȭ�� �Ǿ��ִ� ��� Ŭ���� ���ο����� �����ϸ� ��. 


�� ���� Ŭ������ ���� ���� �ν��Ͻ��� ������� ��, 
�ش� �ν��Ͻ������� private ����� ���ؼ��� ������ �����ϴ�. 

*/

class Date
{
//access specifier : Ŭ���� �ܺο��� ����� ������ �� �ִ� ���� ������ �����ϴ� ������
//Ŭ�������� ���������ڴ� private�� ����Ʈ��. 
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

	//���� Ŭ������ ���� �ٸ� �ν��Ͻ������� ����� ������ �����ϴ�. 
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