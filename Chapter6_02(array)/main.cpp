#include<iostream>
using namespace std; 

//�Լ����� ���ڷ� �迭�� ���� ���, �迭�� ��� ���Ҹ� �����ؼ� 
//�������� ���� �ƴ϶� �迭�� �迭�� ù ��° ���� �ּҰ��� ����

//���� �Լ� ������ ���ڷ� �Ѿ�� ���������� �ش� �迭�� ���� ������ ���� �ƴϸ�,
//�ּҰ��� �����Ͽ� ������ ������ ���� ���̱� ������, �ش� ������ �ּ� ���� ����ϸ�
//������ ������ �ּ� ���� ��µǹǷ� ���ڷ� �ѱ� ������ �ּҰ��� �ٸ���. 

void doSomething(int students_scores[/*20*/])
{
	//���ڷ� �Ѱܹ��� ������ �ּҰ��� ������ �������� �ּҰ�
	cout << &students_scores << endl; 
	
	//��, �Ѱܹ��� �迭�� �ּҰ��� ����ϸ� �� ������ �ּҰ��� ��ġ 
	cout << students_scores << endl; 
	cout << &students_scores[0] << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << students_scores[3] << endl;

	//students_score�� �迭 ��ü�� �ƴ϶� �迭�� ù��° �ּ� ���� �����ϰ� �ִ�
	//������ �����̹Ƿ� �ش� ������ ����� �����ϸ� �������� ������ ���� ���´�.
	cout << sizeof(students_scores) << endl; 
	cout << sizeof(&students_scores) << endl; 
}

int main()
{
	const int num_students = 10;

	int students_scores[10];
	students_scores[0] = 1;
	students_scores[1] = 2;
	students_scores[2] = 3;
	students_scores[3] = 4;
	students_scores[4] = 5;

	//�迭���� ������(�ĺ���)�� ���������� �ּҷ� ���ȴ�.
	//���� �ּ� �����ڸ� ������� �ʾƵ� �������� �ּҷ� ����� �� �ִ�. 
	cout << students_scores << endl;
	cout << &students_scores << endl; 
	cout << &students_scores[0] << endl;
	cout << &students_scores[1] << endl;
	cout << &students_scores[2] << endl;
	cout << &students_scores[3] << endl;
	cout << &students_scores[4] << endl;

	cout << sizeof(students_scores) << endl; 

	cout << endl;
	doSomething(students_scores);

	return 0; 
}