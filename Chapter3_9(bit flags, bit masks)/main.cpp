#include<iostream>
#include<bitset>
using namespace std; 

int main()
{
	/*
	
	��Ʈ �÷��� 
	
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

	////������ 0�� ������ �ְ�, 1�� ������ ���� ���� ��
	//if ((items_flag & opt[0]) && !(items_flag & opt[1]))
	//{
	//	//�� ���� �ݴ�� ���ϱ� 
	//	//cout << bitset<8>(items_flag ^= opt[0]) << endl; 
	//	//cout << bitset<8>(items_flag ^= opt[1]) << endl;

	//	//items_flag ^= opt[2];
	//	//items_flag ^= opt[1];
	//	items_flag ^= (opt[0] | opt[1]);
	//}

	//cout << bitset<8>(items_flag) << endl;

	/*
	
	��Ʈ����ũ 

	RGB �÷��� ��Ÿ���� �� 
	
	10���� : (256, 256, 256) 
	16���� : (FF, A5, 00) -> �̷� ������ 16���� ���� 3���� �̾ RR,GG,BB�� ǥ�� 
	
	�̷��� 16���� ���� 3�� �پ����� �� �� RGB ���� ��� �����ұ�? 

	*/

	////�� �� ������ �����ϴ� �� ��� �� ���� 
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

	//// >> right shift ������ �ϴ� ���� 
	//// char�� ������ 1����Ʈ(8��Ʈ)�̰�, int�� ����(pixel_color)�� 4����Ʈ(32��Ʈ)
	//// char�� ������ �ڽź��� ũ�Ⱑ ū Ÿ���� ������������ �޾ƿ� �� �ִ� ���� ������ 8��Ʈ��
	//// ���� �� ���ʿ� �ִ� ���� red, green�� ����Ʈ ������ ���� ������ ������ 8ĭ���� ���ܾ� ��.  

	//red = (pixel_color & red_mask) >> 16;
	//green = (pixel_color & green_mask) >> 8;
	//blue = pixel_color & blue_mask;

	//cout << "red " << std::bitset<8>(red) << " " << int(red) << endl;
	//cout << "green " << std::bitset<8>(green) << " " << int(green) << endl;
	//cout << "blue " << std::bitset<8>(blue) << " " << int(blue) << endl; 

	/*

	1. ���� ��쿡 ���� �÷��׸� �ٲ㺸����. 
	
	- ��縦 ���� �� 
	- ����� ���ƿ並 Ŭ������ �� 
	- ����� ���ƿ並 �ٽ� Ŭ������ �� 
	- �� ��縸 ������ �� 
	
	*/

	unsigned char option_viewed  = 0x01;
	unsigned char option_edited  = 0x02;
	unsigned char option_liked	 = 0x04;
	unsigned char option_shared	 = 0x08;
	unsigned char option_deleted = 0x80;

	unsigned char article_flags = 0;


	//2. �Ʒ� �� ���� �� �����ϰ� �۵��ϴ��� �����ϼ���. 

	//myflags &= ~(option4 | option5);
	//myflags &= ~option4 & ~option5;

	return 0; 
}