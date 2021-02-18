#include<iostream>
#include<cstring>
using namespace std; 

int main()
{
	// 문자열에는 해당 문자열을 구성하고 있는 문자들 외에 
	// 문자열 마지막에 '\0' null 원소가 포함되어 있다. 
	// 따라서 문자열 사이즈는 해당 문자열의 문자 개수 + 1 

	//char myString[] = "string";

	//for (int i = 0; i < (int)strlen(myString) + 1; i++)
	//{
	//	cout << (int)myString[i] << endl;
	//}

	//cout << sizeof(myString) / sizeof(myString[0]) << endl;

	// NULL 문자를 삽입했더니, 뒤에 문자열이 더 있음에도 불구하고 
	// NULL 문자 바로 앞까지만 문자열을 출력 
	// ★문자열 출력 시 NULL 문자를 만날때까지 출력하기 때문★

	//char str[256];

	////cin >> str; 
	////str[0] = 'A';
	////str[2] = '\0';
	////getline(cin, str);
	//cin.getline(str, sizeof(str));

	////공백문자와 널 문자는 다르다. 아스키코드 값을 출력해보면 
	////공백문자는 32, NULL 문자는 0 
	//int idx = 0;
	//while (true)
	//{
	//	if (str[idx] == '\0') break; 
	//	cout << str[idx] << ' ' << (int)str[idx] << endl; 
	//	idx++;
	//}

	//strcpy(A, B) : B의 문자열을 A에 복사하는 함수 
	//복사하고자 하는 문자열의 길이가 복사 할 문자열의 길이보다 긴 경우 오류 발생

	char source[] = "Copy this!";
	char dest[50];
	strcpy_s(dest, source);
	//strcpy_s(dest, sizeof(source), source);

	cout << source << endl; 
	cout << dest << endl; 

	//strcat : 문자열 뒤에 다른 문자열을 붙이는 함수 
	//strcmp : 문자열이 같은지 비교하는 함수 

	char basic[50] = "basic";
	strcat_s(basic, "append");
	cout << basic << endl; 

	//문자열을 비교하여 서로 같을 경우  0 반환
	//문자열을 비교하여 같지 않을 경우 -1 반환 
	cout << strcmp(dest, source) << endl; 
	cout << strcmp(dest, basic) << endl; 

	return 0; 
}