#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>	// exit()
#include<sstream>
using namespace std; 

/*

<기본적인 파일 입출력>

*/

int main()
{
	// writing
	if (true)
	{
		// my_first_file.dat 파일이 존재하지 않는다면 생성 
		// 만약 존재한다면 모드에 따라 다시 열거나, 새로 생성하기도 함. 
		// 파일을 열 때는 아래와 같이 생성자의 파라미터를 통해 열거나, open 함수를 통해 열 수 있음. 
		
		// 파일 열기 
		ofstream ofs("my_first_file.dat");	// ios::app, ios::binary
		//ofs.open("my_first_file.dat");

		// append 모드로 파일 열기 : 파일이 이미 존재할 경우 해당 파일에 이어서 작업 진행
		// 해당 모드에서 파일을 쓸 경우 존재하던 파일에 이어서 데이터 작성 
		ofstream ofs("my_first_file.dat", ios::app);

		// 파일을 열 수가 없었다면 
		if (!ofs)
		{
			cerr << "Couldn't open file" << endl;
			exit(1);
		}

		// 아스키 포맷으로 파일 쓰기  
		// ofstream 도 stream 이므로, stream 형식처럼 사용 가능  
		//ofs << "Line 1" << endl;
		//ofs << "Line 2" << endl;

		//================================================================//

		// 바이너리 포맷으로 파일 쓰기 

		// 바이너리 포맷(2진수)으로 저장할 경우, 데이터를 분리하는 기준이 모호하므로
		// 어떠한 형태의 데이터가 몇 개가 있는지 명확하게 해야 함. 

		// 데이터의 개수 및 사이즈 저장 
		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; i++)
			ofs.write((char*)&i, sizeof(i));

		// 출력 할 데이터를 문자열에 담아서 저장 
		//stringstream ss;
		//ss << "Line 1" << endl;
		//ss << "Line 2" << endl;
		//string str = ss.str();

		//unsigned str_length = str.size();
		//ofs.write((char*)&str_length, sizeof(str_length));
		//ofs.write(str.c_str(), str_length);


		// 직접 close 함수를 사용하여 닫아줄 수 있지만, 
		// 영역을 벗어나면서 호출되는 소멸자가 자동으로 파일을 닫아줌. 
		//ofs.close();	// not necessary
	}

	// reading
	if (true)
	{
		// 파일 읽어들이기 
		// 보통 아스키 포맷의 파일일 경우 확장자를 .txt 로 사용 

		// 아스키 포맷으로 파일을 읽을 경우 바이너리에 비해 속도가 느림. 
		// 따라서 보통 게임 프로그램의 경우 바이너리 포맷을 많이 사용.

		ifstream ifs("my_first_file.dat");					// 아스키코드로 읽기  
		//ifstream ifs("my_first_file.dat", ios::binary);	// 바이너리로 읽기 

		// 만약 파일을 읽어오지 못한다면 에러메시지 출력 
		if (!ifs)
		{
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		// 아스키 포맷으로 파일 읽기 
		// 파일을 열 경우 데이터를 str에 한 줄씩 읽어들인다.
		//while (ifs)
		//{
		//	std::string str;
		//	getline(ifs, str);

		//	std::cout << str << endl;
		//}
	
		//================================================================//
	
		// 바이너리 포맷으로 파일 읽기 
		
		// 바이너리 포맷의 단점 : 문서 프로그램으로 읽어들여 값을 확인하는 것이 불가능 
		// 따라서 바이너리 포맷으로 파일 입출력 시 디버깅에 신경써야 함. 

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