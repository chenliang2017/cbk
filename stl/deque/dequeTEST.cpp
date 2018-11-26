#include <windows.h>
#include <psapi.h> 
#include <iostream>
#include <deque>

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
	//size and memory info
	deque<int> dqe(100000);
	cout << "size: " << dqe.size() << endl;
	showMemoryInfo();

	dqe.resize(10);
	cout << "resize to: " << dqe.size() << endl;
	showMemoryInfo();

	dqe.shrink_to_fit();
	cout << "shrink to fit" << endl;
	showMemoryInfo();

	//set value by at()
	for (int i = 0; i < 10;i++){
		dqe[i] = i;	
	}

	//set value by iterator
	deque<int>::iterator it = dqe.begin();
	for (; it != dqe.end(); it++){
		cout << " " << *it << ", ";
		*it = *it * 2;
	}
	cout << endl;

	it = dqe.begin();
	for (; it != dqe.end(); it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	//use iterator to remove all elements safely
	it = dqe.begin();
	for (; it != dqe.end(); ){
		it = dqe.erase(it);
	}
	cout << "size: " << dqe.size() << endl;

	//insert
	it = dqe.begin();
	it = dqe.insert(it, 3, 10);
	it = dqe.insert(it + 2, 3, 200);
	for (; it != dqe.end(); it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	it = dqe.begin();
	for (; it != dqe.end(); it++){
		cout << " " << *it << ", ";
	}
	cout << endl;

	dqe.clear();
	cout << "size: " << dqe.size() << endl;

	system("pause");
	return 0;
}