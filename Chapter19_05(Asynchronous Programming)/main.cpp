#include<iostream>
#include<future>
#include<thread>
using namespace std; 

/*

<작업 기반 비동기 프로그래밍>

<future> 헤더파일을 인클루드하여 아래 함수 사용 
async, future, promise

*/

int main()
{
	/*
	// multi-threading
	{
		int result; 
		std::thread t([&] {result = 1 + 2; });

		// 스레드가 일을 끝낼 때까지 기다림.
		t.join();
		cout << result << endl;
	}

	// 스레드 기반 프로그래밍보다 선호되는 추세
	// task-based parallelism
	{
		// main 함수와 별도로 async 함수의 동작이 수행. (비동기)
		// return 이하의 명령문이 실행되는데 얼마나 걸릴지 알 수 없으므로 비동기 처리
		auto fut = std::async([] {return 1 + 2; });
		
		// async()가 끝나고 답이 반환될 때까지 기다림.
		cout << fut.get() << endl;
	}
	*/

	/*
	// future and promise
	{
		std::promise<int> prom;
		auto fut = prom.get_future();

		// promise를 파라미터로 넣어주어야 함. 
		auto t = std::thread([](std::promise<int>&& prom)
		{
			prom.set_value(1 + 2);
		}, std::move(prom));
	
		// prom이 set_value를 통해 결과값을 받을 때까지 future가 기다림.
		cout << fut.get() << endl;

		// 스레드이므로 아래 코드 추가 필요.
		t.join();
	}
	*/

	{
		// async와 thread는 내부적으로 동작하는 방식에 차이가 있다. 
		
		// async로 실행 시 Main Function이 제일 먼저 실행 
		// thread로 실행 시 Main Function이 가장 나중에 실행 

		/*
		auto f1 = std::async([] {

			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;

		});

		auto f2 = std::async([] {
		
			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
		
		});
		*/

		// async가 future와 연결되어있지 않은 경우 sequential처럼 순차적으로 실행  
		std::async([] {

			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;

		});

		std::async([] {

			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;

		});

		/*
		auto f1 = std::thread([] {

			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;

		});

		auto f2 = std::thread([] {

			cout << "async2 start" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;

		});

		f1.join();
		f2.join();
		*/

		std::cout << "Main Function" << endl;
	}

	return 0;
}