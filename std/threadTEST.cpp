#include <iostream>
#include <string>
#include <thread>
#include <memory>

using namespace std;

int func(int a, char b, double c, string d)
{
	cout << "thread id: " <<  std::this_thread::get_id() << a << ','<< b << "," << c << ','<< d.c_str() << endl;

	return 0;
}

class Test
{
public:
	Test() {
		m_t_ptr = NULL;
		m_ptr = NULL;
	};

	~Test() {
		if (m_t.joinable()){
			m_t.join();
		}
		if (m_t_ptr && m_t_ptr->joinable()){
			m_t_ptr->join();
		}
		if (m_ptr && m_ptr->joinable()){
			m_ptr->join();
		}
	};

public:
	static void staticFunc(int size, string name){
		cout << "thread id: " << std::this_thread::get_id() << ", size: " << size << ", name: " << name.c_str() << endl;
	}

	void sum(int a, int b){
		cout << "thread id: " << std::this_thread::get_id() << ", sum: " << (a + b) << endl;
	}

	void priTest(){
		m_t = std::thread(&Test::print, this, 300);
	}

	void priTest2(){
		m_t_ptr.reset(new std::thread(&Test::print2, this, 5000));
	}

	void priTest3(){
		m_ptr = new std::thread(&Test::print3, this, 1000);
	}

private:
	void print(int value){
		cout << "thread id: " << m_t.get_id() << ", value: " << value << endl;
	}

	void print2(int value){
		cout << "thread id: " << std::this_thread::get_id() << ", data: " << value << endl;
	}

	void print3(int value){
		cout << "thread id: " << std::this_thread::get_id() << ", vvv: " << value << endl;
	}

private:
	std::thread m_t;
	std::thread *m_ptr;
	std::shared_ptr<std::thread> m_t_ptr;
};

void main(void)
{
	int a = 10;char b = 'c';double c = 3.5;string d = "thread test";

	Test t;
	t.priTest();
	t.priTest2();
	t.priTest3();

	std::thread t1(func, a, b, c, d);
	if (t1.joinable()){
		t1.join();
	}

	std::thread t2(&Test::staticFunc, 50, "static function");
	if (t2.joinable()){
		t2.join();
	}

	std::thread t3(&Test::sum, &t, 30, 50);
	if (t3.joinable()){
		t3.join();
	}

	system("pause");
}