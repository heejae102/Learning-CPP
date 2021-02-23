#include<iostream>
#include<string>
#include<vector>
#include<cstdint>
using namespace std;

int main()
{
	/*
	
	자료형의 이름을 직접 선언해서 사용 가능 
	
	1) typedef
	2) using 
	 
	- 긴 자료형의 이름을 짧게 줄일 수 있어서 가독성이 높아짐. 
	- 같은 문맥 상에서 읽기가 편리함. 
	- 유지보수적인 측면에서 능률이 올라감. 
	
	*/

	//distance_t라는 이름의 자료형을 double 형태로 선언(이름만 새롭게 명칭한 것)
	typedef double distance_t;

	//고정너비 정수의 int8_t 새로운 자료형이 아니라 이름만 새롭게 지어준 것. 
	std::int8_t i(97);

	//컴파일러의 입장에서는 완전히 동일. 프로그래머의 편의성을 위한 기능. 
	double my_distance;
	distance_t home2work;
	distance_t home2school; 

	//사용하다보면 거리를 구하는 데이터 형식을 바꾸거나 할 필요가 있을 수 있는데
	//그럴 때는 distance_t의 자료형만 바꾸면 되기 때문에 유지관리에 도움. 
	//추후 템플릿 및 STL과 함께 사용하면 편리. 

	//1) type definition
	typedef vector<pair<string, int>> pairlist_t;

	//vector<pair<string, int>> pairlist1;
	//vector<pair<string, int>> pairlist2;

	pairlist_t pairlist1;
	pairlist_t pairlist2;

	
	//2)using 키워드 
	//대입 연산자는 assignment의 의미는 X 
	//연산자 뒤에 오는 자료형을 선언하는 자료형의 이름으로 사용한다는 의미 
	using pairlist_t = vector<pair<string, int>>;

	return 0; 
}