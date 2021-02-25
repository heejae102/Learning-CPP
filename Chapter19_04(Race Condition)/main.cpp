#include<iostream>
#include<thread>
#include<atomic>
#include<mutex>
#include<chrono>
using namespace std; 

/*

<���̽� �����>

std::atomic, std::scoped_lock

��Ƽ�������� ���� ���� ��������� �ϳ��� �޸� ������ �����ϵ���
�ϱ� ������ �ٸ� ����ó�� ����鿡 ���ؼ� �����ϱ� �ξ� ��

������ ���� �޸� ������ ���������ν� ������ 
������ �߻��ϱ⵵ �ϴµ� �̷��� ��츦 '���̽� �����'�̶�� �θ���. 

*/

mutex mtx;

int main()
{
	int shared_memory(0);
	
	// ���� �ذ� ���1. atomic ���� ������ �����ϱ� 
	// ��, �Ϲ� ������ ����� ������ �����ս��� �������� ������ 
	// ������ �ʿ��� �������� ����ؾ� �Ѵ�. 
	//atomic<int> shared_memory(0);

	auto count_func = [&]() 
	{
		for (int i = 0; i < 1000; i++)
		{
			// �Ʒ� �ڵ带 �������� ���� ���, ���� �������� ��µǴµ�,
			// ������ �ذ�� ���� �ƴ϶� ����ó���� �̷������ �ʾƼ� 
			// ������ �߻����� ���� �ͻ���. �Ʒ� �ڵ� ���� �� 
			// ��������� ���������� ���ÿ� �۾��� �����ϴ� ���� �߻��ϸ鼭 
			// ������ �߻��ϰ� �Ǵ� ��. 
			this_thread::sleep_for(chrono::milliseconds(1));
			
			// ���� �ذ� ���2. mutex�� ����Ͽ� ��Ÿ���� ���ٸ� ���
			// ��, mutex�� ����� ��� �ݵ�� lock�� �� ���� unlock�� ���־�� �ϴµ�, 
			// �Ǽ��� ���߸��ų�, ����ó�� �� �ǳʶٴ� ��Ȳ ������ ���� 
			// unlock�� ���� ���ϴ� ��Ȳ�� �߻��� �� �����Ƿ� ���� �ʿ�. 
			//mtx.lock();

			// ���� �ذ� ���3. lock_guard ����ϱ� 
			// lock ������ ���Ե� ������ ������ unlock���� �ʾƵ� ��.
			// �Ϲ������� mutext�� ���� ����ϴ� �ͺ��� lock_guard�� ����ϴ� ���� ����.
			//std::lock_guard<std::mutex> lock(mtx);

			// ���� �ذ� ���4. C++17�� scoped_lock ����ϱ� 
			// lock_guard���� ������ �� ����. ������ ���Ե� �������� ����� ����
			// ���� �ڵ����� ����(unlock)�ȴ�. 
			std::scoped_lock<std::mutex> lock(mtx);

			shared_memory++;
			//shared_memory.fetch_add(1);	// ++; �� ���� ���
		
			//mtx.unlock();
		}
	};

	// �� �����尡 1000�� ���ϸ� shared_memory ���� ���� 2000�� ���;� ������, 
	// 2000�� �� ��ġ�� ���� �����ϰ� ����. (ex. 1985, 1989)

	// <���� �߻� ����>
	// �ϳ��� �����尡 shared_memory ���� �ҷ����̸� +1 �� �غ� �� ��(10), 
	// �ٸ� �����尡 ���� ������Ű��(11), shared_memory�� +1�� ���� �� ���� ���� ����� �ȴ�.(11)
	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();

	cout << "After" << endl;
	cout << shared_memory << endl;

	return 0;
}