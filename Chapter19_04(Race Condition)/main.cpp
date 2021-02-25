#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<chrono>
using namespace std; 

/*

<레이스 컨디션>

std::atomic, std::scoped_lock

멀티스레딩은 여러 개의 스레드들이 하나의 메모리 공간을 공유하도록
하기 때문에 다른 병렬처리 기법들에 비해서 구현하기 훨씬 편리

하지만 같은 메모리 공간을 공유함으로써 때때로 
오류가 발생하기도 하는데 이러한 경우를 '레이스 컨디션'이라고 부른다. 

*/

mutex mtx;

int main()
{
	int shared_memory(0);
	
	// 오류 해결 방법1. atomic 으로 변수를 선언하기 
	// 단, 일반 변수를 사용할 때보다 퍼포먼스가 떨어지기 때문에 
	// 정말로 필요한 순간에만 사용해야 한다. 
	//atomic<int> shared_memory(0);

	auto count_func = [&]() 
	{
		for (int i = 0; i < 1000; i++)
		{
			// 아래 코드를 실행하지 않을 경우, 값이 문제없이 출력되는데,
			// 문제가 해결된 것이 아니라 병렬처리가 이루어지지 않아서 
			// 문제가 발생하지 않은 것뿐임. 아래 코드 실행 시 
			// 스레드들이 병렬적으로 동시에 작업을 수행하는 일이 발생하면서 
			// 오류가 발생하게 되는 것. 
			this_thread::sleep_for(chrono::milliseconds(1));
			
			// 오류 해결 방법2. mutex를 사용하여 배타적인 접근만 허용
			// 단, mutex를 사용할 경우 반드시 lock을 한 이후 unlock을 해주어야 하는데, 
			// 실수로 빠뜨리거나, 예외처리 중 건너뛰는 상황 등으로 인해 
			// unlock을 하지 못하는 상황이 발생할 수 있으므로 주의 필요. 
			//mtx.lock();

			// 오류 해결 방법3. lock_guard 사용하기 
			// lock 변수가 포함된 스코프 내에서 unlock하지 않아도 됨.
			// 일반적으로 mutext를 직접 사용하는 것보다 lock_guard를 사용하는 것을 권장.
			//std::lock_guard<std::mutex> lock(mtx);

			// 오류 해결 방법4. C++17의 scoped_lock 사용하기 
			// lock_guard보다 진보된 락 형태. 변수가 포함된 스코프를 벗어나는 순간
			// 락이 자동으로 해제(unlock)된다. 
			std::scoped_lock<std::mutex> lock(mtx);

			shared_memory++;
			//shared_memory.fetch_add(1);	// ++; 와 같은 기능
		
			//mtx.unlock();
		}
	};

	// 각 스레드가 1000을 더하면 shared_memory 값이 도합 2000이 나와야 하지만, 
	// 2000에 못 미치는 값이 랜덤하게 나옴. (ex. 1985, 1989)

	// <오류 발생 원인>
	// 하나의 스레드가 shared_memory 값을 불러들이며 +1 할 준비를 할 때(10), 
	// 다른 스레드가 값을 증가시키면(11), shared_memory가 +1을 했을 때 값을 덮어 씌우게 된다.(11)
	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}