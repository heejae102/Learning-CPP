#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>	// exit()
#include<sstream>
using namespace std; 

/*

<�⺻���� ���� �����>

*/

int main()
{
	// writing
	if (true)
	{
		// my_first_file.dat ������ �������� �ʴ´ٸ� ���� 
		// ���� �����Ѵٸ� ��忡 ���� �ٽ� ���ų�, ���� �����ϱ⵵ ��. 
		// ������ �� ���� �Ʒ��� ���� �������� �Ķ���͸� ���� ���ų�, open �Լ��� ���� �� �� ����. 
		
		// ���� ���� 
		ofstream ofs("my_first_file.dat");	// ios::app, ios::binary
		//ofs.open("my_first_file.dat");

		// append ���� ���� ���� : ������ �̹� ������ ��� �ش� ���Ͽ� �̾ �۾� ����
		// �ش� ��忡�� ������ �� ��� �����ϴ� ���Ͽ� �̾ ������ �ۼ� 
		ofstream ofs("my_first_file.dat", ios::app);

		// ������ �� ���� �����ٸ� 
		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		// �ƽ�Ű �������� ���� ����  
		// ofstream �� stream �̹Ƿ�, stream ����ó�� ��� ����  
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		//================================================================//

		// ���̳ʸ� �������� ���� ���� 

		// ���̳ʸ� ����(2����)���� ������ ���, �����͸� �и��ϴ� ������ ��ȣ�ϹǷ�
		// ��� ������ �����Ͱ� �� ���� �ִ��� ��Ȯ�ϰ� �ؾ� ��. 

		// �������� ���� �� ������ ���� 
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; i++)
			ofs.write((char*)&i, sizeof(i));

		// ��� �� �����͸� ���ڿ��� ��Ƽ� ���� 
		//stringstream ss;
		//ss << "Line 1" << endl;
		//ss << "Line 2" << endl;
		//string str = ss.str();

		//unsigned str_length = str.size();
		//ofs.write((char*)&str_length, sizeof(str_length));
		//ofs.write(str.c_str(), str_length);


		// ���� close �Լ��� ����Ͽ� �ݾ��� �� ������, 
		// ������ ����鼭 ȣ��Ǵ� �Ҹ��ڰ� �ڵ����� ������ �ݾ���. 
		//ofs.close();	// not necessary
	}

	// reading
	if (true)
	{
		// ���� �о���̱� 
		// ���� �ƽ�Ű ������ ������ ��� Ȯ���ڸ� .txt �� ��� 

		// �ƽ�Ű �������� ������ ���� ��� ���̳ʸ��� ���� �ӵ��� ����. 
		// ���� ���� ���� ���α׷��� ��� ���̳ʸ� ������ ���� ���.

		ifstream ifs("my_first_file.dat");					// �ƽ�Ű�ڵ�� �б�  
		//ifstream ifs("my_first_file.dat", ios::binary);	// ���̳ʸ��� �б� 

		// ���� ������ �о���� ���Ѵٸ� �����޽��� ��� 
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// �ƽ�Ű �������� ���� �б� 
		// ������ �� ��� �����͸� str�� �� �پ� �о���δ�.
		//while (ifs)
		//{
		//	std::string str;
		//	getline(ifs, str);

		//	std::cout << str << endl;
		//}
	
		//================================================================//
	
		// ���̳ʸ� �������� ���� �б� 
		
		// ���̳ʸ� ������ ���� : ���� ���α׷����� �о�鿩 ���� Ȯ���ϴ� ���� �Ұ��� 
		// ���� ���̳ʸ� �������� ���� ����� �� ����뿡 �Ű��� ��. 

		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));

		for (unsigned i = 0; i < num_data; i++)
		{
			int num;
			ifs.read((char*)&num, sizeof(num));

			std::cout << num << endl;
		}

		//unsigned str_len = 10;
		//ifs.read((char*)&str_len, sizeof(str_len));

		//string str;
		//str.resize(str_len);
		//ifs.read(&str[0], str_len);

		//cout << str << endl;

		ifs.close();	// not necessary
	}

	return 0;
}