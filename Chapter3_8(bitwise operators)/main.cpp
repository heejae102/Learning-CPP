#include<iostream>
#include<bitset>
using namespace std; 

int main()
{
	// <<, >> 연산자는 기본적으로 비트 연산자로 사용
	// cin, cout 에서는 해당 연산자의 의미를 달리하도록 C++ 내에서 오버로딩이 되어있음. 

	// 비트 연산자 
	// << left shift 
	// >> right shift 
	// ~, &, |, ^ 

	/*
	
	비트 연산을 하는 경우 unsigned 변수를 사용하는 것이 일반적. 
	(부호로 인해서 계산이 복잡해질 수 있기 때문)
	
	쉬프트 연산 <<, >> 

	해당 물결 방향으로 입력되는 숫자의 수(칸)만큼 수평이동 
	2의 n제곱수만큼 곱하거나 나누는 연산을 할 때 비트 연산을 이용하면 
	데이터 타입 단위의 계산방식보다 훨씬 빠르게 할 수 있다. 


	1) << 연산 (Left Shift)
	
	변수 << n 
	
	결과 : 변수 * 2^n
	
	2의 제곱을 곱하는 구조에서는 쉬프트 연산을 사용하면 연산 속도를 높일 수 있다. 


	2) >> 연산 (Right Shift)

	변수 >> n 
	
	결과 : 변수 / 2^n 

	2의 제곱을 나누는 구조에서 사용하면 일반 나누기 연산에 비해 월등히 높은 속도로 처리 가능. 


	3) ~ 연산 (Bitwise Not)

	~변수 

	1001 1110 

	결과 : 0110 0001 

	기존의 값을 전부 반대로 처리 


	4) & 연산 (Bitwise And)

	and 연산과 비슷함. (비교 대상에서 둘 다 1이면 1) 
	
	1100
	0110

	0100


	5) | 연산 (Bitwise Or)

	or 연산과 비슷함. (비교 대상에서 둘 중 하나만 1이라도 1)

	1100
	0110
	
	1110


	6) ^ 연산 (Bitwise XOr)

	비교 대상 둘의 값이 서로 같지 않으면 1, 같으면 0.
	즉, 두 입력 중 하나만이 배타적으로 참일 경우에만 1.

	1100
	0110
	
	1010

	*/

	unsigned int a = 3; 
	unsigned int b = 1024;	//2의 10제곱 

	unsigned int x = 0b1100;
	unsigned int y = 0b0110;

	//a가 내부적으로 어떻게 저장되는지 <>안에 들어간 숫자의 비트 수만큼 출력  
	//cout << std::bitset<4>(a) << endl; 
	//cout << std::bitset<4>(b) << endl; 

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << std::bitset<12>(a << i) << " " << (a << i) << endl; 
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout << std::bitset<12>(b >> i) << " " << (b >> i) << endl;
	//}

	//cout << std::bitset<12>(~a) << " " << (~a) << endl;

	cout << std::bitset<4>(a & b) << endl; 
	cout << std::bitset<4>(a | b) << endl; 
	cout << std::bitset<4>(a ^ b) << endl; 

	//operator 사용법도 다양 
	//a = a & b;
	//a &= b;

	cout << (0b0110 >> 2) << endl;
	cout << (5 | 12) << endl; 
	cout << (5 & 12) << endl; 
	cout << (5 ^ 12) << endl; 

	return 0; 
}