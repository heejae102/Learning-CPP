#include<iostream>
#include<chrono>
#include<mutex>
#include<thread>
#include<random>
#include<utility>
#include<vector>
#include<atomic>
#include<future>
#include<numeric>		// std::inner_product
#include<execution>		// parallel execution
using namespace std; 

/*

<멀티스레딩 예제>

벡터 내적 

*/

mutex mtx; 

void dotProductNaive(const vector<int>& v0, const vector<int>& v1,
	const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
	for (unsigned i = i_start; i < i_end; i++)
	{
		sum += v0[i] * v1[i];
	}
}

// 결과는 잘 나오지만 퍼포먼스가 많이 떨어진다. 
void dotProductLock(const vector<int>& v0, const vector<int> &v1,
	const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
	cout << "Thread Start" << endl; 

	for (unsigned i = i_start; i < i_end; i++)
	{
		// 락을 거는 부분은 한 번에 한 스레드만 들어올 수 있기 때문에 
		// 락을 거는 부분이 많거나, 락을 거는 부분이 너무 자주 실행되거나
		// 락을 거는 구문이 길면 멀티스레딩을 함에도 오히려 퍼포먼스가 떨어진다. 

		std::scoped_lock lock(mtx);		// c++17
	
		sum += v0[i] * v1[i];
	}

	cout << "Thread End" << endl;
}

// 락 가드 걸어주는 것에 비해 구현이 간단 
// 결과는 잘 나오지만 일반 변수 연산에 비해서 느리다. 
// 빈번하게 호출되는 곳에 atomic 연산을 넣으면 퍼포먼스가 떨어진다. 
void dotProductAtomic(const vector<int>& v0, const vector<int> &v1,
	const unsigned i_start, const unsigned i_end, unsigned long long &sum)
{
	for (unsigned i = i_start; i < i_end; i++)
	{
		sum += v0[i] * v1[i];
	}
}

auto dotProductFuture(const vector<int>& v0, const vector<int> &v1,
	const unsigned i_start, const unsigned i_end)
{
	int sum = 0;	// local sum 

	for (unsigned i = i_start; i < i_end; i++)
	{
		sum += v0[i] * v1[i];
	}

	return sum;
}


int main()
{
	const long long n_data = 100'000'000;
	const unsigned n_threads = 4;

	// initialize vectors
	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	// 랜덤 넘버 생성 위해 제너레이터 생성 
	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; i++)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	// 순진한 멀티스레딩 
	cout << "Naive" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	// assumes remainder = 0
	
		for (unsigned t = 0; t < n_threads; t++)
		{
			threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1),
				t*n_per_thread, (t + 1)*n_per_thread, std::ref(sum));

			for (unsigned t = 0; t < n_threads; t++)
			{
				threads[t].join();
			}

			const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

			cout << dur.count() << endl;
			cout << sum << endl << endl;
		}
	}

	/*
	cout << "Lockguard" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		unsigned long long sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	// assumes remainder = 0

		for (unsigned t = 0; t < n_threads; t++)
		{
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t*n_per_thread, (t + 1)*n_per_thread, std::ref(sum));

			for (unsigned t = 0; t < n_threads; t++)
			{
				threads[t].join();
			}

			const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

			cout << dur.count() << endl;
			cout << sum << endl << endl;
		}
	}
	*/
	
	/*
	cout << "Atomic" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<thread> threads;
		threads.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	// assumes remainder = 0

		for (unsigned t = 0; t < n_threads; t++)
		{
			threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1),
				t*n_per_thread, (t + 1)*n_per_thread, std::ref(sum));

			for (unsigned t = 0; t < n_threads; t++)
			{
				threads[t].join();
			}

			const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

			cout << dur.count() << endl;
			cout << sum << endl << endl;
		}
	}
	*/

	// 결과 값도 잘 나오고 퍼포먼스도 일반적인 방법보다 높다. 
	//cout << "Future" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		atomic<unsigned long long> sum = 0;

		vector<std::future<int>> futures;
		futures.resize(n_threads);

		const unsigned n_per_thread = n_data / n_threads;	// assumes remainder = 0

		for (unsigned t = 0; t < n_threads; t++)
		{
			futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1),
				t*n_per_thread, (t + 1)*n_per_thread);

			for (unsigned t = 0; t < n_threads; t++)
			{
				sum += futures[t].get();
			}

			const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

			cout << dur.count() << endl;
			cout << sum << endl << endl;
		}
	}

	cout << "std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	return 0;
}

