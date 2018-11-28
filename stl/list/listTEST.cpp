#include <windows.h>
#include <psapi.h>
#include <iostream>
#include <list>

#pragma comment(lib,"psapi.lib") 

using namespace std;

void showMemoryInfo(void)
{
	HANDLE handle = GetCurrentProcess();
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(handle, &pmc, sizeof(pmc));
	cout << "memory info: " << pmc.WorkingSetSize / 1000 << "K/" << pmc.PeakWorkingSetSize / 1000 << "K + " << pmc.PagefileUsage / 1000 << "K/" << pmc.PeakPagefileUsage / 1000 << "K" << endl;
}

int main()
{
	list<int> lsTest(100000, 6);
	cout << "size: " << lsTest.size() << ", max size: " << lsTest.max_size() << endl;
	showMemoryInfo();

	lsTest.resize(10);
	cout << "size: " << lsTest.size() << endl;
	showMemoryInfo();

	lsTest.push_back(15);
	lsTest.push_front(20);
	cout << "front element: " << lsTest.front() << ", back element: " << lsTest.back() << endl;

	int &front = lsTest.front(); front += 1;
	int &back = lsTest.back(); back += 1;
	cout << "front element: " << lsTest.front() << ", back element: " << lsTest.back() << endl;

	lsTest.push_back(3);
	lsTest.push_back(5);
	lsTest.push_back(1);
	lsTest.push_back(50);

	list<int>::iterator it;
	for (it = lsTest.begin(); it != lsTest.end();it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	lsTest.sort();
	for (it = lsTest.begin(); it != lsTest.end(); it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	lsTest.reverse();
	for (it = lsTest.begin(); it != lsTest.end(); it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	for (it = lsTest.begin();; it != lsTest.end();){
		it = lsTest.erase(it);
	}
	cout << "size: " << lsTest.size() << endl;
	showMemoryInfo();

	system("pause");
	return 0;
}