#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	for (int i = 0; i < 20; i++){
		vec.push_back(i);
	}
	cout << "vec size:" << vec.size() << ", capacity:" << vec.capacity() << endl;
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	vec.resize(10);
	cout << "vec size:" << vec.size() << ", capacity:" << vec.capacity() << endl;
	for (int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
	cout << endl;

	//use iterator to delete all element safely
	for (vector<int>::iterator iter = vec.begin(); iter != vec.end();){
		iter = vec.erase(iter);
	}
	cout << "vec size:" << vec.size() << ", capacity:" << vec.capacity() << endl;

	system("pause");
	return 0;
}