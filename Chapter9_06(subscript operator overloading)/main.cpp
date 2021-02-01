#include<iostream>
#include<cassert>
using namespace std; 

/*

<÷�� ������ �����ε�>

*/

class IntList
{
private:
	int _list[10];

public:
	void setItem(int index, int value)
	{
		_list[index] = value;
	}

	int getItem(int index)
	{
		return _list[index];
	}

	int* getList()
	{
		return _list;
	}

	// ÷�� ������ �����ε� 
	int& operator [] (const int index)
	{
		// �迭�� ���ҿ� �����ϴ� �ε����� ������ �������־�� �����ʰ� ������ �߻����� ����.
		// ÷�� ������ �����ε��� ����� ����ϴ� �Լ��̹Ƿ� if�����ٴ� assert�� ����ϴ� ���� �����ս��� ���� 
		assert(index >= 0);
		assert(index < 10);

		// ���� ���� �аų� �ٲٴ� �� ��� �����ϰ� �ϱ� ���� ���۷��� �� ���� 
		// ���� ���� �׻� �ּҸ� ������ L value���� �ϹǷ� ���۷����� ����
		return _list[index];
	}

	// Ŭ������ const������ �����Ͽ� ����ϴ� ��� ���� �ҷ����� ����
	// �����ϰ� �ϱ� ���� const�� �Լ��� �����ε� 
	const int& operator [] (const int index) const
	{
		// �迭�� ���ҿ� �����ϴ� �ε����� ������ �������־�� �����ʰ� ������ �߻����� ����.
		// ÷�� ������ �����ε��� ����� ����ϴ� �Լ��̹Ƿ� if�����ٴ� assert�� ����ϴ� ���� �����ս��� ���� 
		assert(index >= 0);
		assert(index < 10);

		// �Լ� ������ ����� �������� �ʴ� const�� �Լ��� ���������Ƿ�, �������� const������ ����
		// ���� �ҷ����� ���� ���������� �ҷ��� ���� �����ϴ� ���� �Ұ��� 
		return _list[index];
	}
};

int main()
{
	//IntList my_list;

	//my_list.setItem(3, 1);
	//cout << my_list.getItem(3) << endl; 

	//my_list.getList()[3] = 10;
	//cout << my_list.getList()[3] << endl;

	//--------------------------------------------------------------//

	IntList my_list;

	my_list[3] = 10;
	cout << my_list[3] << endl; 

	// ����Ʈ�� ������������ ����ϴ� ���, ÷�� �����ڸ� �����ε��Ͽ� ����� �� �����ڸ� �ٷ� ����ϸ� X
	// ���� ���۷����� �� ������ �����ڸ� ȣ���ؾ� ��. 
	IntList *list = new IntList;

	// �Ʒ� ������ list�� �迭�� �ǹǷ� ���������� �ǵ��� �ٸ��ٰ� �� �� �ִ�. 
	
	//list[3] = *list;	// �ǵ��� �ٸ�.	 
	//list[3] = 10;		// Wrong
	(*list)[3] = 10;	// OK

	return 0;
}