#include <iostream>
#include <set>

using namespace std;

static int g_num = 1;

typedef struct Test
{
public:
	Test(int key){
		m_key = key;
		m_pri = g_num++;
	}
	~Test(){}

public:
	int m_key;
	int m_pri;
} Test;

struct setCmp{
	bool operator()(const Test &a, const Test &b) {
		return a.m_key < b.m_key;
	}
};

void main(void)
{
	multiset<Test, setCmp> s;
	for (int i = 0; i < 5; i++){
		s.insert(Test(i));
	}
	for (multiset<Test, setCmp>::iterator it = s.begin(); it != s.end(); it++){
		cout << "key: " << it->m_key << " pri: " << it->m_pri << endl;
	}

	s.insert(Test(3));
	s.insert(Test(2));
	for (multiset<Test, setCmp>::iterator it = s.begin(); it != s.end(); it++){
		cout << "key: " << it->m_key << " pri: " << it->m_pri << endl;
	}

	cout << "exit main fun" << endl;

	system("pause");
}