#include<iostream>
#include<string>
#include<vector>
#include<cstdint>
using namespace std;

int main()
{
	/*
	
	�ڷ����� �̸��� ���� �����ؼ� ��� ���� 
	
	1) typedef
	2) using 
	 
	- �� �ڷ����� �̸��� ª�� ���� �� �־ �������� ������. 
	- ���� ���� �󿡼� �бⰡ ����. 
	- ������������ ���鿡�� �ɷ��� �ö�. 
	
	*/

	//distance_t��� �̸��� �ڷ����� double ���·� ����(�̸��� ���Ӱ� ��Ī�� ��)
	typedef double distance_t;

	//�����ʺ� ������ int8_t ���ο� �ڷ����� �ƴ϶� �̸��� ���Ӱ� ������ ��. 
	std::int8_t i(97);

	//�����Ϸ��� ���忡���� ������ ����. ���α׷����� ���Ǽ��� ���� ���. 
	double my_distance;
	distance_t home2work;
	distance_t home2school; 

	//����ϴٺ��� �Ÿ��� ���ϴ� ������ ������ �ٲٰų� �� �ʿ䰡 ���� �� �ִµ�
	//�׷� ���� distance_t�� �ڷ����� �ٲٸ� �Ǳ� ������ ���������� ����. 
	//���� ���ø� �� STL�� �Բ� ����ϸ� ��. 

	//1) type definition
	typedef vector<pair<string, int>> pairlist_t;

	//vector<pair<string, int>> pairlist1;
	//vector<pair<string, int>> pairlist2;

	pairlist_t pairlist1;
	pairlist_t pairlist2;

	
	//2)using Ű���� 
	//���� �����ڴ� assignment�� �ǹ̴� X 
	//������ �ڿ� ���� �ڷ����� �����ϴ� �ڷ����� �̸����� ����Ѵٴ� �ǹ� 
	using pairlist_t = vector<pair<string, int>>;

	return 0; 
}