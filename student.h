#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

class Student {
public:
	string last_name;
	string first_name;
	string fathers_name;
	int age;
	string gender;
	void PrintInfo() {
		cout << "Your data: " << last_name << " " << first_name << " " << fathers_name << " " << age << " " << gender << '\n';
	}
};