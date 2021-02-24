#include<iostream>
#include<string>
#include<thread>
#include<chrono>
#include<vector>
#include<mutex>
using namespace std;

/*

<std::thread와 멀티쓰레딩(multithreading)의 기초>

일반적으로 배우는 프로그래밍 문법은 단일코어를 가정하고 
하나의 프로세스에서 순차적으로 진행하는 것을 배움. 

하지만 최근에는 컴퓨팅 환경이 멀티코어 환경으로 변화하고 있음.
따라서 여러 개의 코어를 적절히 활용하는 프로그래밍을 할 수 있어야 함. 

C++17에 도입된 std::thread를 사용하여 멀티스레딩의 기초를 배워보자. 


//=====================================================================//


간단히 말했을 때 멀티스레딩은,
하나의 프로세스가 여러 개의 스레드(멀티스레드)를 관리하는 것.

프로세스 : 오퍼레이팅 시스템이 프로그램을 실행시킬 때 관리하는 단위 

멀티 프로세싱 : 하나의 프로그램을 만들고, 그 프로그램이 여러 개의 
스레드를 만들어서 여러 개의 코어를 동시에 활용하여 효율성이 높이는 방법. 

멀티 스레딩 : 하나의 CPU에 여러 개의 코어가 들어있는 경우, 
그 코어들을 활용해서 동시에 여러가지의 작업을 수행하는 것. 
멀티 스레딩에서는 여러 개의 스레드가 하나의 메모리를 공유하므로 
편리함과 동시에 위험을 초래할 수 있어 양날의 검과 같은 면이 있음. 

멀티 스레딩이 멀티 프로세싱보다 효율이 더 좋아서 
요즘은 멀티 스레딩을 더 많이 사용하는 추세 

*/

mutex mtx;	// mutual exclusion

int main()
{
	// CPU의 코어 개수(논리 프로세서 값)를 반환 
	cout << std::thread::hardware_concurrency() << endl;

	// main 함수가 실행되고 있는 스레드의 ID 
	cout << std::this_thread::get_id() << endl;


	//=====================================================================//


	// <멀티 스레딩>

	/*
	const int num_pro = std::thread::hardware_concurrency();
	cout << std::this_thread::get_id() << endl;

	// main 스레드에서 새로운 스레드를 생성해서 실행 
	// 그런데 새로운 스레드가 원래의 스레드와 의사소통을 해야 하는데 
	// main 함수가 끝나버려서 오류 발생 
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

	// 아래 코드 추가 시 오류 해결 
	// t1이 끝날 때까지 기다림.
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	*/

	//=====================================================================//


	// <멀티스레딩으로 CPU 100% 활용하기>

	// CPU 코어 사이즈만큼 스레드 돌리기
	// 근데 돌려보니까 100% 까지는 활용 못했음...ㅎ 
	
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
			// this thread를 잠깐 쉬도록 하기 
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

			// <mutex>
			// 출력하는 부분은 다른 스레드와 엉키게 하지 않도록 
			// 출력 작업은 동시에 하나의 스레드만 작업할 수 있도록 제한 

			// 하나의 스레드가 진입하면서 lock
			mtx.lock();

			cout << name << " " << std::this_thread::get_id() << " is working " << i << endl;
			
			// unlock을 하지 않을 경우, 나머지 스레드가 작업할 수 없음. 
			mtx.unlock();
		}
	};

	// 싱글 스레딩 
	// Jack이 일하는 동안 Dash는 놀게 되므로 비효율적 
	//work_func("Jack");
	//work_func("Dash");

	// 멀티 스레딩
	// Jack과 Dash가 동시에 일을 하게 됨. 
	// 단, 동시에 작업을 진행하기 때문에 출력 명령 시
	// 문자들이 뒤엉켜서 난잡하게 출력될 수 있다. 
	std::thread t1 = std::thread(work_func, "Jack");
	std::thread t2 = std::thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}