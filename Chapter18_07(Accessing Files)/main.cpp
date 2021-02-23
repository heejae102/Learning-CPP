#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>	// exit()
#include<sstream>
using namespace std; 

/*

<������ ���� ��ġ �����ϱ�>

*/

int main()
{
	const string filename = "my_file.txt";

	// make a file
	{
		ofstream ofs(filename);

		for (char i = 'a'; i <= 'z'; i++)
		{
			ofs << i;
		}
		ofs << endl;
	}

	// read the file
	{
		ifstream ifs(filename);

		// ������ ó�� ��ġ���� 5����Ʈ �̵��� �� ������ �о�鿩��.
		ifs.seekg(5);	//ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		// cur ��ġ���� 5����Ʈ �̵��� �� ������ �о�鿩��.
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		// end ��ġ�������� -5����Ʈ �̵��� �� ���� �б�.  
		//ifs.seekg(-5, ios::end);

		// end ��ġ�������� 0����Ʈ �̵�(������ ��ġ)�� �� ���� �б�.
		//ifs.seekg(0, ios::end);
		
		// ifs.tellg() : ���� ��ġ�� �˷���. 
		//cout << ifs.tellg() << endl;
	
		// ifs ��ġ �̵� �� getline �� �� ������ �����͸� �о� ��.  
		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	{
		// ������ �� �� ��� �б⵵, ���⵵ �ϴ� ���

		// �Ʒ�ó�� �÷��׸� �������־ ������, �׷��� ���� �ʾƵ� �б�-���� �۵�
		//fstream iofs(filename, ios::in | ios::out);
		fstream iofs(filename);

		// 5����Ʈ �̵��ؼ� ���� �б�
		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read
	
		// 5����Ʈ �̵��ؼ� ���Ͽ� A ���� 
		iofs.seekg(5);
		iofs.put('A');	// write
	}

	return 0;
}