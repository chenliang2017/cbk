#include <iostream>
#include <map>

using namespace std;

int main()
{
	//size(), max_size()
	map<int, string> keyInfo;
	keyInfo[1] = "first";
	keyInfo[5] = "five";
	keyInfo[3] = "three";
	keyInfo[9] = "nine";
	cout << "size: " << keyInfo.size() << ", max size: " << keyInfo.max_size() << endl;

	//begin(), end()
	map<int, string>::iterator it;
	for (it = keyInfo.begin(); it != keyInfo.end(); it++){
		cout << it->first << "<->" << it->second.c_str() << endl;
	}

	//[], at()
	//keyInfo.at(10);	//key 10 not exist in keInfo, coredump
	cout << keyInfo[10].c_str() << ", size: " << keyInfo.size() << endl;
	
	//use iterator to change key-value
	for (it = keyInfo.begin(); it != keyInfo.end(); it++){
		it->second += " flower";
	}
	for (it = keyInfo.begin(); it != keyInfo.end(); it++){
		cout << it->first << "<->" << it->second.c_str() << endl;
	}

	//find() and count()
	it = keyInfo.find(5);
	if (it != keyInfo.end()){
		cout << it->first << "<->" << it->second.c_str() << endl;
	}
	it = keyInfo.find(6);
	if (it == keyInfo.end()){
		cout << "can't find key '6' in map" << endl;
	}
	if (keyInfo.count(9)){
		cout << "find key '9' in map" << endl;
	} else {
		cout << "can't find key '9' in map" << endl;
	}
	cout << "key '7' " << (keyInfo.count(7) ? "exist in map" : "not exist in map") << endl;

	//insert() and find()
	keyInfo.insert(pair<int, string>(7, "seven"));
	keyInfo.insert(pair<int, string>(6, "six"));

	pair<map<int, string>::iterator, bool> ret;
	ret = keyInfo.insert(pair<int, string>(6,"sixer"));
	if (false == ret.second){
		cout << "insert key '6' error, " << "value " << ret.first->second.c_str() << endl;
	}
	
	//erase()
	it = keyInfo.begin();
	for (; it != keyInfo.end();){
		keyInfo.erase(it++);
	}
	cout << "map size: " << keyInfo.size() << endl;

	system("pause");
	return 0;
}
