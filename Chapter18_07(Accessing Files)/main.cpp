#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>	// exit()
#include<sstream>
using namespace std; 

/*

<파일의 임의 위치 접근하기>

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

		// 파일의 처음 위치에서 5바이트 이동한 뒤 파일을 읽어들여라.
		ifs.seekg(5);	//ifs.seekg(5, ios::beg);
		cout << (char)ifs.get() << endl;

		// cur 위치에서 5바이트 이동한 뒤 파일을 읽어들여라.
		ifs.seekg(5, ios::cur);
		cout << (char)ifs.get() << endl;

		// end 위치에서부터 -5바이트 이동한 뒤 파일 읽기.  
		//ifs.seekg(-5, ios::end);

		// end 위치에서부터 0바이트 이동(마지막 위치)한 뒤 파일 읽기.
		//ifs.seekg(0, ios::end);
		
		// ifs.tellg() : 현재 위치를 알려줌. 
		//cout << ifs.tellg() << endl;
	
		// ifs 위치 이동 후 getline 시 그 이후의 데이터를 읽어 옴.  
		string str;
		getline(ifs, str);

		cout << str << endl;
	}

	{
		// 파일을 한 번 열어서 읽기도, 쓰기도 하는 방법

		// 아래처럼 플래그를 설정해주어도 되지만, 그렇게 하지 않아도 읽기-쓰기 작동
		//fstream iofs(filename, ios::in | ios::out);
		fstream iofs(filename);

		// 5바이트 이동해서 파일 읽기
		iofs.seekg(5);
		cout << (char)iofs.get() << endl;	// read
	
		// 5바이트 이동해서 파일에 A 쓰기 
		iofs.seekg(5);
		iofs.put('A');	// write
	}

	return 0;
}