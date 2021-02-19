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

// 시퀀스 컨테이너 
// 데이터를 선형으로 저장하며, 특별한 제약이나 규칙이 없는 일반적인 컨테이너
// 삽입된 원소의 순서가 그대로 유지된다. 
void sequence_containers()
{
	// vector
	// 동적인 배열 
	// 배열의 마지막 위치에 원소 추가/삭제 가능  
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
	// 동적인 배열 (중간 삽입/삭제가 느린 벡터를 보완)
	// 양방향으로 삽입/삭제 가능 
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

	// 그외 list, forward_list
}

// 연관 컨테이너 
// key-value 처럼 관련있는 데이터를 하나의 쌍으로 저장하는 컨테이너. 
// 키와 값을 이용한 연관 컨테이너는 요소들에 대한 빠른 접근을 제공 
// 반면, 삽입되는 요소의 위치를 지정할 수는 X
void associative_containers()
{
	// set
	// key라는 원소를 저장 
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");	// 중복된 원소는 추가하지 않고 무시

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
		str_multiset.insert("Hello");	// 중복된 원소 허용

		cout << str_multiset.size() << endl;

		for (auto &e : str_multiset)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	// map 
	// 원소 key-value 를 한 쌍으로 저장 
	{
		// char : key
		// int  : value

		// key가 존재하지 않는 경우 생성 
		std::map<char, int> map; 
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;

		cout << map['a'] << endl; 

		// key가 존재하는 경우 값을 갱신 
		map['a'] = 100;

		cout << map['a'] << endl; 

		for (auto &e : map)
		{
			// 원소.first  : 원소의 key
			// 원소.second : 원소의 value
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

// 컨테이너 어댑터 
// 기존 컨테이너의 인터스페이스를 제한하여 만든 기능이 제한되거나 변형된 컨테이너 
// 이러한 컨테이너 어댑터는 각각의 기초가 되는 클래스의 인터페이스를 제한하여, 특정 형태의 동작만을 수행
// 단, 반복자를 지원하지 않으므로 STL 알고리즘에서는 사용할 수 X
void container_adapters()
{
	// stack (LIFO)
	{
		cout << "Stack" << endl; 

		std::stack<int> stack;
		stack.push(1);				// push adds a copy (복사)
		stack.emplace(2);			// emplace constructs a new object (새 객체 생성)
		stack.emplace(3);

		cout << stack.top() << endl;	// 가장 위에 있는 원소 peek 기능 
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
	// 큐 + 우선순위에 맞게 정렬하는 기능 
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