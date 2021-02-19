#include<iostream>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
using namespace std; 

/*

<STL : Standard Template Library>

*/

// ������ �����̳� 
// �����͸� �������� �����ϸ�, Ư���� �����̳� ��Ģ�� ���� �Ϲ����� �����̳�
// ���Ե� ������ ������ �״�� �����ȴ�. 
void sequence_containers()
{
	// vector
	// ������ �迭 
	// �迭�� ������ ��ġ�� ���� �߰�/���� ����  
	{
		vector<int> vec;	// #include <vector>

		for (int i = 0; i < 10; i++)
		{
			vec.push_back(i);
		}

		for (auto &e : vec)
		{
			cout << e << " ";
		}
		cout << endl; 
	}

	// deque
	// ������ �迭 (�߰� ����/������ ���� ���͸� ����)
	// ��������� ����/���� ���� 
	{
		deque<int> deq;		// #include <deque>

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}

		for (auto &e : deq)
		{
			cout << e << " ";
		}
		cout << endl; 
	}

	// �׿� list, forward_list
}

// ���� �����̳� 
// key-value ó�� �����ִ� �����͸� �ϳ��� ������ �����ϴ� �����̳�. 
// Ű�� ���� �̿��� ���� �����̳ʴ� ��ҵ鿡 ���� ���� ������ ���� 
// �ݸ�, ���ԵǴ� ����� ��ġ�� ������ ���� X
void associative_containers()
{
	// set
	// key��� ���Ҹ� ���� 
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");	// �ߺ��� ���Ҵ� �߰����� �ʰ� ����

		cout << str_set.size() << endl; 

		for (auto &e : str_set)
		{
			cout << e << " ";
		}
		cout << endl; 
	}

	// multiset : duplication is allowed.
	{
		multiset<string> str_multiset;

		str_multiset.insert("Hello");
		str_multiset.insert("World");
		str_multiset.insert("Hello");	// �ߺ��� ���� ���

		cout << str_multiset.size() << endl;

		for (auto &e : str_multiset)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// map 
	// ���� key-value �� �� ������ ���� 
	{
		// char : key
		// int  : value

		// key�� �������� �ʴ� ��� ���� 
		std::map<char, int> map; 
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;

		cout << map['a'] << endl; 

		// key�� �����ϴ� ��� ���� ���� 
		map['a'] = 100;

		cout << map['a'] << endl; 

		for (auto &e : map)
		{
			// ����.first  : ������ key
			// ����.second : ������ value
			cout << e.first << " " << e.second << " ";
		}
		cout << endl; 
	}

	// multimap : duplication is allowed. 
	{
		std::multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10));
		multimap.insert(pair<char, int>('b', 10));
		multimap.insert(pair<char, int>('c', 10));
		multimap.insert(pair<char, int>('a', 100));

		cout << multimap.count('a') << endl;

		for (auto &e : multimap)
		{
			cout << e.first << " " << e.second << " ";
		}
		cout << endl;
	}
}

// �����̳� ����� 
// ���� �����̳��� ���ͽ����̽��� �����Ͽ� ���� ����� ���ѵǰų� ������ �����̳� 
// �̷��� �����̳� ����ʹ� ������ ���ʰ� �Ǵ� Ŭ������ �������̽��� �����Ͽ�, Ư�� ������ ���۸��� ����
// ��, �ݺ��ڸ� �������� �����Ƿ� STL �˰��򿡼��� ����� �� X
void container_adapters()
{
	// stack (LIFO)
	{
		cout << "Stack" << endl; 

		std::stack<int> stack;
		stack.push(1);				// push adds a copy (����)
		stack.emplace(2);			// emplace constructs a new object (�� ��ü ����)
		stack.emplace(3);

		cout << stack.top() << endl;	// ���� ���� �ִ� ���� peek ��� 
		stack.pop();
		cout << stack.top() << endl; 
	}

	// queue (FIFO)
	//{
	//	cout << "Queue" << endl; 

	//	std::queue<int> queue;

	//	queue.push(1);
	//	queue.push(2);
	//	queue.push(3);

	//	cout << queue.front() << " " << queue.back() << endl; 
	//	queue.pop();
	//	cout << queue.front() << " " << queue.back() << endl;
	//}

	// priority queue
	// ť + �켱������ �°� �����ϴ� ��� 
	{
		cout << "Priority queue" << endl; 

		std::priority_queue<int> queue;

		for (const int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
		{
			queue.push(n);
		}

		for (int i = 0; i < 10; i++)
		{
			cout << queue.top() << endl; 
			queue.pop();
		}
	}
}

int main()
{
	//sequence_containers();

	//associative_containers();

	container_adapters();

	return 0;
}