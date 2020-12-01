#include<iostream>
#include<bitset>
using namespace std; 

int main()
{
	/*
	
	비트 플래그 
	
	*/

	//bool item1_flag = false; 
	//bool item2_flag = false; 
	//bool item3_flag = false; 
	//bool item4_flag = false; 
	// ...

	//unsigned char items_flag = 0;
	//cout << "No Item" << bitset<8>(items_flag) << endl; 

	//unsigned char opt[8];

	//for (int i = 0; i < 8; i++)
	//{
	//	opt[i] = 1 << i;
	//	cout << bitset<8>(opt[i]) << endl; 
	//}

	////item0 on 
	//items_flag |= opt[0];
	//cout << "item0 obtained " << bitset<8>(items_flag) << endl; 
	// 
	////item3 on 
	//items_flag |= opt[3];
	//cout << "item3 obtained " << bitset<8>(items_flag) << endl; 

	////item3 lost 
	//items_flag &= ~opt[3];
	//cout << "item3 lost " << bitset<8>(items_flag) << endl;

	////have item0 ?
	//if (items_flag & opt[0]) cout << "have item0" << endl;
	//else cout << "don't have item0" << endl;

	////have item1 ?
	//if (items_flag & opt[1]) cout << "have item1" << endl; 
	//else cout << "don't have item1" << endl; 

	////obtain item 4, 5
	//items_flag |= (opt[4] | opt[5]);
	//cout << "item4,5 obtained " << bitset<8>(items_flag) << endl;

	////아이템 0은 가지고 있고, 1은 가지고 있지 않을 때
	//if ((items_flag & opt[0]) && !(items_flag & opt[1]))
	//{
	//	//각 값을 반대로 취하기 
	//	//cout << bitset<8>(items_flag ^= opt[0]) << endl; 
	//	//cout << bitset<8>(items_flag ^= opt[1]) << endl;

	//	//items_flag ^= opt[2];
	//	//items_flag ^= opt[1];
	//	items_flag ^= (opt[0] | opt[1]);
	//}

	//cout << bitset<8>(items_flag) << endl;

	/*
	
	비트마스크 

	RGB 컬러를 나타내는 값 
	
	10진수 : (256, 256, 256) 
	16진수 : (FF, A5, 00) -> 이런 식으로 16진수 숫자 3개를 이어서 RR,GG,BB를 표현 
	
	이렇게 16진수 값이 3개 붙어있을 때 각 RGB 값을 어떻게 추출할까? 

	*/

	////각 색 영역을 구분하는 데 사용 할 변수 
	//const unsigned int red_mask = 0xFF0000;
	//const unsigned int green_mask = 0x00FF00;
	//const unsigned int blue_mask = 0x0000FF;

	//unsigned int pixel_color = 0xDAA520;
	//unsigned char red, green, blue; 

	//cout << std::bitset<32>(red_mask) << endl;
	//cout << std::bitset<32>(green_mask) << endl;
	//cout << std::bitset<32>(blue_mask) << endl;

	//cout << std::bitset<32>(pixel_color) << endl;

	//cout << endl; 

	//// >> right shift 연산을 하는 이유 
	//// char형 변수는 1바이트(8비트)이고, int형 변수(pixel_color)는 4바이트(32비트)
	//// char형 변수가 자신보다 크기가 큰 타입의 데이터형에서 받아올 수 있는 것은 마지막 8비트뿐
	//// 따라서 더 왼쪽에 있는 값인 red, green은 쉬프트 연산을 통해 마지막 오른쪽 8칸으로 땡겨야 함.  

	//red = (pixel_color & red_mask) >> 16;
	//green = (pixel_color & green_mask) >> 8;
	//blue = pixel_color & blue_mask;

	//cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;
	//cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
	//cout << "blue " << std::bitset<8>(blue) << " " << int(blue) << endl; 

	/*

	1. 다음 경우에 대해 플래그를 바꿔보세요. 
	
	- 기사를 봤을 때 
	- 기사의 좋아요를 클릭했을 때 
	- 기사의 좋아요를 다시 클릭했을 때 
	- 본 기사만 삭제할 때 
	
	*/

	unsigned char option_viewed  = 0x01;
	unsigned char option_edited  = 0x02;
	unsigned char option_liked	 = 0x04;
	unsigned char option_shared	 = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char article_flags = 0;


	//2. 아래 두 줄이 왜 동일하게 작동하는지 설명하세요. 

	//myflags &= ~(option4 | option5);
	//myflags &= ~option4 & ~option5;

	return 0; 
}