#include <iostream>
#include <functional>
#include <string>

using namespace std;

int func(int a, char b, double c, string d)
{
	cout << a << ','<< b << "," << c << ','<< d.c_str() << endl;

	return 0;
}

class Test
{
public:
	Test() {};
	~Test() {};

public:
	static int staticFunc(int size, string name){
		cout << "size: " << size << ", name: " << name.c_str() << endl;
		return 0;
	}

	int sum(int a, int b){
		cout << "sum: " << (a + b) << endl;
		return (a + b);
	}
};

void main(void)
{
	//全部参数通过占位符传递
	std::function<int(int, char, double, string)> func1 =
		std::bind(func, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
	func1(10, 'v', 3.14, "snow");

	//预留参数
	std::function<int(string, char)> func2 =
		std::bind(func, 20, std::placeholders::_2, 5.6, std::placeholders::_1);
	func2("subway", 'r');

	//类的静态函数
	std::function<int(int, string)> func3 =
		std::bind(&Test::staticFunc, std::placeholders::_1, std::placeholders::_2);
	func3(35, "bind static func of class");

	//类的成员函数,传递类指针
	Test test;
	std::function<int(int, int)> func4 =
		std::bind(&Test::sum, &test, std::placeholders::_1, std::placeholders::_2);
	func4(45,55);

	system("pause");
}