#include<iostream>
#include<fstream>
using namespace std; 

/*

<입출력 연산자 오버로딩>

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

	// print 함수 대신 입출력 연산자를 오버로딩해서 사용하기 
	
	// 아웃풋 스트림 
	// 해당 함수는 첫 번째 파라미터가 포인터 클래스가 아닌 아웃풋스트림이므로 멤버함수로 만들기 어렵다. 
	// 따라서 friend 키워드를 사용하여 구현.
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		// cout 대신 out에 cout 하듯이 사용
		out << "( " << point._x << ", " << point._y << ", " << point._z << " )";

		// 리턴타입으로 out(아웃풋스트림)을 사용하는 이유는 Chaining 형태로 구현할 수 있기 때문 
		return out; 
	}

	// 인풋 스트림 
	friend std::istream& operator >> (std::istream &in, Point &point)
	{
		// 방어적 프로그래밍의 개념으로 예외처리가 필요하다면 실행 
		in >> point._x >> point._y >> point._z;

		// 리턴타입으로 out(아웃풋스트림)을 사용하는 이유는 Chaining 형태로 구현할 수 있기 때문 
		return in;
	}
};

int main()
{
	// 아웃풋 스트림 

	Point p1(0.0, 0.1, 0.2), p2(3.4, 1.5, 2.0);

	//p1.print();
	//cout << endl; 

	//p2.print();
	//cout << endl; 

	cout << p1 << " " << p2 << endl; 

	// 아웃풋 연산자 오버로딩의 장점은 파일스트림에서도 똑같이 작동한다는 것.
	// 따라서 오버로딩 함수를 수정할 필요 없이 cout 출력과 마찬가지로 파일 출력에 사용가능. 
	// out.txt 파일에 출력하는 내용이 작성됨. 
	ofstream of("out.txt");

	of << p1 << " " << p2 << endl;
	of.close();


	// 인풋 스트림 

	Point p3, p4; 

	cin >> p3 >> p4;
	cout << p3 << " " << p4 << endl;

	return 0;
}