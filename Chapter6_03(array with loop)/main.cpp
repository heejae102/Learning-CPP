#include<iostream>
#include<limits>
using namespace std; 

int main()
{
	//const int num_students = 5;
	int scores[/*num_students*/] = { 84, 92, 76, 81, 65 };
	
	const int num_students = sizeof(scores) / sizeof(int);
	
	int total_score = 0;
	int max_score = 0; 
	int min_score = numeric_limits<signed int>::max();

	for (int i = 0; i < num_students; i++)
	{
		total_score += scores[i];

		//���ҵ� �� �ִ밪 ���ϱ� 
		//if (max_score < scores[i]) max_score = scores[i];
		max_score = (max_score < scores[i]) ? scores[i] : max_score;

		//���ҵ� �� �ּҰ� ���ϱ� 
		//if (min_score > scores[i]) min_score = scores[i];
		min_score = (min_score > scores[i]) ? scores[i] : min_score;
	}

	double avg_score = static_cast<double>(total_score) / num_students;
	cout << max_score << endl; 
	cout << min_score << endl; 

	return 0;
}