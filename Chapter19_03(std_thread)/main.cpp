#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>
using namespace std;

/*

<std::thread�� ��Ƽ������(multithreading)�� ����>

�Ϲ������� ���� ���α׷��� ������ �����ھ �����ϰ� 
�ϳ��� ���μ������� ���������� �����ϴ� ���� ���. 

������ �ֱٿ��� ��ǻ�� ȯ���� ��Ƽ�ھ� ȯ������ ��ȭ�ϰ� ����.
���� ���� ���� �ھ ������ Ȱ���ϴ� ���α׷����� �� �� �־�� ��. 

C++17�� ���Ե� std::thread�� ����Ͽ� ��Ƽ�������� ���ʸ� �������. 


//=====================================================================//


������ ������ �� ��Ƽ��������,
�ϳ��� ���μ����� ���� ���� ������(��Ƽ������)�� �����ϴ� ��.

���μ��� : ���۷����� �ý����� ���α׷��� �����ų �� �����ϴ� ���� 

��Ƽ ���μ��� : �ϳ��� ���α׷��� �����, �� ���α׷��� ���� ���� 
�����带 ���� ���� ���� �ھ ���ÿ� Ȱ���Ͽ� ȿ������ ���̴� ���. 

��Ƽ ������ : �ϳ��� CPU�� ���� ���� �ھ ����ִ� ���, 
�� �ھ���� Ȱ���ؼ� ���ÿ� ���������� �۾��� �����ϴ� ��. 
��Ƽ ������������ ���� ���� �����尡 �ϳ��� �޸𸮸� �����ϹǷ� 
���԰� ���ÿ� ������ �ʷ��� �� �־� �糯�� �˰� ���� ���� ����. 

��Ƽ �������� ��Ƽ ���μ��̺��� ȿ���� �� ���Ƽ� 
������ ��Ƽ �������� �� ���� ����ϴ� �߼� 

*/

mutex mtx;	// mutual exclusion

int main()
{
	// CPU�� �ھ� ����(�� ���μ��� ��)�� ��ȯ 
	cout << std::thread::hardware_concurrency() << endl;

	// main �Լ��� ����ǰ� �ִ� �������� ID 
	cout << std::this_thread::get_id() << endl;


	//=====================================================================//


	// <��Ƽ ������>

	/*
	const int num_pro = std::thread::hardware_concurrency();
	cout << std::this_thread::get_id() << endl;

	// main �����忡�� ���ο� �����带 �����ؼ� ���� 
	// �׷��� ���ο� �����尡 ������ ������� �ǻ������ �ؾ� �ϴµ� 
	// main �Լ��� ���������� ���� �߻� 
	std::thread t1 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;		
		while (true) {}});

	std::thread t2 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t3 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t4 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	std::thread t5 = std::thread([]() {
		cout << std::this_thread::get_id() << endl;
		while (true) {}});

	// �Ʒ� �ڵ� �߰� �� ���� �ذ� 
	// t1�� ���� ������ ��ٸ�.
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	*/

	//=====================================================================//


	// <��Ƽ���������� CPU 100% Ȱ���ϱ�>

	// CPU �ھ� �����ŭ ������ ������
	// �ٵ� �������ϱ� 100% ������ Ȱ�� ������...�� 
	
	/*
	const int num_pro = std::thread::hardware_concurrency();
	cout << std::this_thread::get_id() << endl;

	vector<std::thread> my_threads;
	my_threads.resize(num_pro);

	for (auto &e : my_threads)
	{
		e = std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}});
	}

	for (auto &e : my_threads)
	{
		e.join();
	}
	*/

	//=====================================================================//


	auto work_func = [](const string &name)
	{
		for (int i = 0; i < 5; i++)
		{
			// this thread�� ��� ������ �ϱ� 
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			// <mutex>
			// ����ϴ� �κ��� �ٸ� ������� ��Ű�� ���� �ʵ��� 
			// ��� �۾��� ���ÿ� �ϳ��� �����常 �۾��� �� �ֵ��� ���� 

			// �ϳ��� �����尡 �����ϸ鼭 lock
			mtx.lock();

			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			
			// unlock�� ���� ���� ���, ������ �����尡 �۾��� �� ����. 
			mtx.unlock();
		}
	};

	// �̱� ������ 
	// Jack�� ���ϴ� ���� Dash�� ��� �ǹǷ� ��ȿ���� 
	//work_func("Jack");
	//work_func("Dash");

	// ��Ƽ ������
	// Jack�� Dash�� ���ÿ� ���� �ϰ� ��. 
	// ��, ���ÿ� �۾��� �����ϱ� ������ ��� ��� ��
	// ���ڵ��� �ھ��Ѽ� �����ϰ� ��µ� �� �ִ�. 
	std::thread t1 = std::thread(work_func, "Jack");
	std::thread t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}