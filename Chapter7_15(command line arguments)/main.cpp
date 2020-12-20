#include<iostream>
#include<string>
using namespace std; 

/*

<Command Line Arguments>

명령줄 인수 

*/

int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		string argv_single = argv[i];

		if (i == 1)
		{
			int input_number = stoi(argv_single);
			cout << input_number + 1 << endl; 
		}
		else cout << argv_single << endl; 

		//cout << argv[i] << endl; 
	}

	return 0;
}