#include <iostream>
#include <set>

using namespace std;

typedef struct Test
{
public:
	Test(int key){
		m_key = key;
	}
	~Test(){
		cout << "destruct, key: " << m_key << endl;
	}

public:
	int m_key;
} Test;

struct setCmp{
	bool operator()(const Test &a, const Test &b) {
		return a.m_key > b.m_key;
	}
};

struct setCmp2{
	bool operator()(const Test *a, const Test *b) {
		return a->m_key > b->m_key;
	}
};

void main(void)
{
	{
		cout << "enter cs work space..." << endl;
		set<Test, setCmp> cs;
		for (int i = 20; i < 22; i++){
			Test t(i);
			cs.insert(t);
		}
		cout << "leave cs work space..." << endl;
	}

	{
		cout << "enter css work space..." << endl;
		set<Test*, setCmp2> css;
		for (int i = 30; i < 32; i++){
			Test *t = new Test(i);
			css.insert(t);
			// test whether ~set() will delete t
		}
		cout << "leave css work space..." << endl;
	}

	{
		cout << "enter csss work space..." << endl;
		set<Test*, setCmp2> csss;
		for (int i = 40; i < 42; i++){
			Test *t = new Test(i);
			csss.insert(t);
			// test whether clear() will delete t
		}
		csss.clear();
		cout << "csss size = " << csss.size() << endl;
		cout << "leave css work space..." << endl;
	}

	set<int> s;
	for (int i = 0; i < 10; i++){
		s.insert(i);
	}
	for (set<int>::iterator it = s.begin(); it != s.end();){
		cout << " " << *it << " ";
		s.erase(it++);
	}
	cout << endl;
	cout << "size: " << s.size() << endl;

	cout << "exit main fun" << endl;

	system("pause");
}