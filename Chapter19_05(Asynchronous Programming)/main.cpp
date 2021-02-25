#include<iostream>
#include<future>
#include<thread>
using namespace std; 

/*

<�۾� ��� �񵿱� ���α׷���>

<future> ��������� ��Ŭ����Ͽ� �Ʒ� �Լ� ��� 
async, future, promise

*/

int main()
{
	/*
	// multi-threading
	{
		int result; 
		std::thread t([&] {result = 1 + 2; });

		// �����尡 ���� ���� ������ ��ٸ�.
		t.join();
		cout << result << endl;
	}

	// ������ ��� ���α׷��ֺ��� ��ȣ�Ǵ� �߼�
	// task-based parallelism
	{
		// main �Լ��� ������ async �Լ��� ������ ����. (�񵿱�)
		// return ������ ��ɹ��� ����Ǵµ� �󸶳� �ɸ��� �� �� �����Ƿ� �񵿱� ó��
		auto fut = std::async([] {return 1 + 2; });
		
		// async()�� ������ ���� ��ȯ�� ������ ��ٸ�.
		cout << fut.get() << endl;
	}
	*/

	/*
	// future and promise
	{
		std::promise<int> prom;
		auto fut = prom.get_future();

		// promise�� �Ķ���ͷ� �־��־�� ��. 
		auto t = std::thread([](std::promise<int>&& prom)
		{
			prom.set_value(1 + 2);
		}, std::move(prom));
	
		// prom�� set_value�� ���� ������� ���� ������ future�� ��ٸ�.
		cout << fut.get() << endl;

		// �������̹Ƿ� �Ʒ� �ڵ� �߰� �ʿ�.
		t.join();
	}
	*/

	{
		// async�� thread�� ���������� �����ϴ� ��Ŀ� ���̰� �ִ�. 
		
		// async�� ���� �� Main Function�� ���� ���� ���� 
		// thread�� ���� �� Main Function�� ���� ���߿� ���� 

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

		// async�� future�� ����Ǿ����� ���� ��� sequentialó�� ���������� ����  
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