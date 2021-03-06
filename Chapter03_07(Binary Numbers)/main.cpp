#include<iostream>
using namespace std; 

int main()
{
	/*
	
	10진수 

	0
	1
	2
	3
	4
	5
	6
	7
	8
	9
	10 = 10^1 + 0
	11 = 10^1 + 1
	12 
	12
	.
	.
	337 = 300 + 30 + 7 = (10^2 * 3) + (10^1 * 3) + (10^0 * 7)
	
	*/

	/*
	
	2진수 

	0
	1
	10 = (2^1 * 1) + (2^0 * 0) = 2
	11 = (2^1 * 1) + (2^0 * 1) = 3
	

		11
	+	 1
	-------
	   100
	
	11(3) + 1 = 100(4)

	*/

	/*
	
	2진수를 10진수로 변환하기 (binary to decimal)

	7654 3210 (2의 제곱자리)
	0101 1110
	
	(2^7 * 0) + (2^6 * 1) + (2^5 * 0) + (2^4 * 1) + (2^3 * 1) + (2^2 * 1) + (2^1 * 1) + (2^0 * 0)
	
	= 128*0 + 64*1 + 32*0 + 16*1 + 8*1 + 4*1 + 2*1 + 1*0
	= 0 + 64 + 0 + 16 + 8 + 4 + 2 + 0 
	= 94

	*/

	/*
	
	1) 10진수를 2진수로 변환하기  (decimal to binary)

	148

	148 / 2 = 74 r0 (r = remainder)
	74  / 2 = 37 r0 
	37  / 2 = 18 r1
	18  / 2 = 9  r0
	9   / 2 = 4  r1
	4   / 2 = 2  r0
	2   / 2 = 1  r0
	1   / 2 = 0  r1

	여기서 r 값을 마지막부터 처음까지 거슬러올라 작성하면 2진수 값

	= 1001 0100
	
	*/

	/*
	
	2) 10진수를 2진수로 변환하기 (decimal to binary)
	
	2의 제곱 수 중에서 148보다 작은 것들을 찾기 

	148보다 작은 것들 중에서 가장 큰 숫자 찾아서 계산 

	1 2 4 8 16 32 64 128 256 512 1024 . . .

	148 

	148 >= 128					Yes -> 128 = 2^7, 8번째 자리가 1
	148 - 128 = 20, 20 >= 64	No  -> 64  = 2^6, 7번째 자리가 0
					20 >= 32	No  -> 32  = 2^5, 6번째 자리가 0 
					20 >= 16	Yes -> 16  = 2^4, 5번째 자리가 1

	20 - 16 = 4,	 4 >= 8		No  -> 8   = 2^3, 4번째 자리가 0 
					 4 >= 4		Yes -> 4   = 2^2, 3번째 자리가 1
	4 - 4 = 0.
	
	1001 0100
	
	*/

	/*
	
	2진수의 덧셈 

	11
	0110 (6 in decimal)
	0111 (7 in decimal)
	------
	1101 = 13 in decimal
	
	*/

	/*
	
	1) 음수를 2진수로 표현하기 
	
	-5
	
	양수 5를 먼저 만들고 보수(complement) 취하기  
	0000 0101
	1111 1010 -> 여기서 마지막에 1을 더하기  
	1111 1011 == -5


	2) 2진수로 표현된 음수를 10진수로 바꾸기 

	보수를 취해 양수로 바꾼 뒤 -부호 붙이기 

	1001 1110 
	0110 0001 -> 1 더하기  
	0110 0010 -> 98 -> -98
	

	3) signed 변수 vs unsigned 변수 

	맨 앞에 있는 2진수 값은 signed 변수일 때 부호를 의미(0일 때 양수, 1일 때 음수)
	따라서 같은 2진수 값이라도 signed 변수냐 unsigned 변수이냐에 따라 값이 달라진다. 
	
	1001 1110 ->  signed : -98
				unsigned : (2^7 * 1) + (2^4 * 1) + (2^3 * 1) + (2^2 * 1) + (2^1 * 1)
				
	*/

	return 0;
}