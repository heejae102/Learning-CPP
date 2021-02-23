#include<iostream>
#include<regex>
using namespace std; 

/*

<���� ǥ���� �Ұ�>

Regular Expressions

�Է¹��� �����Ͱ� Ư���� ���Ŀ� �°� �ԷµǾ����� 
�����ϴ� �� �����ϰ� ����� �� �ִ� ���̺귯�� �Լ� 

*/

int main()
{
	// regular expression

	// \\d : 1�ڸ� ���� �ϳ��� digit(����)���� �Ǻ�
	regex re("\\d");

	// \\d+ : 1�ڸ� �� �̻��� ���ڰ� digit(����)���� �Ǻ�
	//regex re("\\d+");

	// [[:digit:]]    : digit�̸� true 
	// [[:digit:]]{n} : digit�̰� n�ڸ� ������ true (012, 345, 678)
	// �Էµ� ���� n�ڸ� ������ �߶� ��� 
	//regex re("[[:digit:]]{3}");
	
	// [A-Z]+ : ���ĺ� A-Z����, 1�ڸ� �� �̻��̸� true
	//regex re("[A-Z]+");

	// [A-Z]{1, 5} : ���ĺ� A-Z����, �ּ� 1�ڸ�, �ִ� 5�ڸ� ����� true
	//regex re("[A-Z]{1, 5}");

	// 0-9 ���� 1�� �̻� / - �ְų� ��� �� / 0-9 ���� 1�� �̻� 4�� ���� true 
	//regex re("([0-9]{1})([-]?)([0-9]{1,4})");

	string str; 

	while (true)
	{
		// getline���� ���ڿ� �� ���� �Է� ����. 
		getline(cin, str);

		// ���ǵ� regex ������ �˻��Ͽ� match �ϴ��� ����� ���� 
		if (std::regex_match(str, re))
			cout << "Match" << endl;
		else
			cout << "No Match" << endl;

		// Print Matches
		{
			auto begin = std::sregex_iterator(str.begin(), str.end(), re);
			auto end = std::sregex_iterator();
		
			for (auto itr = begin; itr != end; itr++)
			{
				std::smatch match = *itr;
			}
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}