#include<iostream>
#include<vector>
using namespace std; 

//std::vector

int main()
{
	//std::array�� �޸� �����Ҵ�Ǵ� �޸��̱� ������ 
	//arrayó�� �ʱ�ȭ �� ����� �������� �ʾƵ� �ȴ�. 

	//std::array<int, 5> array1;

	//vector<int> array2 = { 1,2,3,4,5 };

	//cout << array2.size() << endl; 

	//vector<int> array3 = { 1,2,3 };

	//cout << array3.size() << endl; 

	////uniform initialization�� ���� 
	//vector<int> array4{ 1,2,3 };

	//cout << array4.size() << endl; 

	vector<int> arr{ 1,2,3,4,5 };

	arr.resize(10);

	for (const auto &num : arr)
	{
		cout << num << endl; 
	}

	//index �ѹ��� ���� �������� ���� 
	cout << arr[0] << endl; 
	cout << arr.at(0) << endl; 

	//vector�� �� ����ϰ� ���� ��ȣ���� �����ų� return�� �� �޸𸮿��� ������.
	//���� �޸� ������ ���� ...��¥�ΰ�? �̰� ���߿� Ȯ���ʿ� 

	//������ �Լ��� ����� Ȯ���� �� �����Ƿ� �Լ��� �Ķ���ͷ� �Ѱܵ�
	//������ �Լ��� ������ ������ Ȯ���� �� �ִٴ� ������ ����.
	//�ʱ�ȭ�� ���Ŀ� resize �Լ��� ���� ����� Ű��ų� ���̴� �͵� ����
	//(resize �� ������ Ȯ���ؼ� ���Ҵ��ϱ� ������ �����ս��� ������)


	return 0;
}