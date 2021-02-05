#include<iostream>
#include<fstream>
using namespace std; 

/*

<����� ������ �����ε�>

*/

class Point
{
private:
	double _x, _y, _z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		: _x(x), _y(y), _z(z) {}

	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }

	//void print()
	//{
	//	cout << _x << " " << _y << " " << _z << endl; 
	//}

	// print �Լ� ��� ����� �����ڸ� �����ε��ؼ� ����ϱ� 
	
	// �ƿ�ǲ ��Ʈ�� 
	// �ش� �Լ��� ù ��° �Ķ���Ͱ� ������ Ŭ������ �ƴ� �ƿ�ǲ��Ʈ���̹Ƿ� ����Լ��� ����� ��ƴ�. 
	// ���� friend Ű���带 ����Ͽ� ����.
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		// cout ��� out�� cout �ϵ��� ���
		out << "( " << point._x << ", " << point._y << ", " << point._z << " )";

		// ����Ÿ������ out(�ƿ�ǲ��Ʈ��)�� ����ϴ� ������ Chaining ���·� ������ �� �ֱ� ���� 
		return out; 
	}

	// ��ǲ ��Ʈ�� 
	friend std::istream& operator >> (std::istream &in, Point &point)
	{
		// ����� ���α׷����� �������� ����ó���� �ʿ��ϴٸ� ���� 
		in >> point._x >> point._y >> point._z;

		// ����Ÿ������ out(�ƿ�ǲ��Ʈ��)�� ����ϴ� ������ Chaining ���·� ������ �� �ֱ� ���� 
		return in;
	}
};

int main()
{
	// �ƿ�ǲ ��Ʈ�� 

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	//p1.print();
	//cout << endl; 

	//p2.print();
	//cout << endl; 

	cout << p1 << " " << p2 << endl; 

	// �ƿ�ǲ ������ �����ε��� ������ ���Ͻ�Ʈ�������� �Ȱ��� �۵��Ѵٴ� ��.
	// ���� �����ε� �Լ��� ������ �ʿ� ���� cout ��°� ���������� ���� ��¿� ��밡��. 
	// out.txt ���Ͽ� ����ϴ� ������ �ۼ���. 
	ofstream of("out.txt");

	of << p1 << " " << p2 << endl;
	of.close();


	// ��ǲ ��Ʈ�� 

	Point p3, p4; 

	cin >> p3 >> p4;
	cout << p3 << " " << p4 << endl;

	return 0;
}