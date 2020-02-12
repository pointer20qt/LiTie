#include "movecopy.h"
#include<iostream>
#include<string>

using namespace std;
class student{
	string name;

public:
	student(string name){
		this->name = name;
	}
	~student(){
		cout << "判断析构函数是否执行" << endl;
	}

};

class school{
public:
	string schoolName;
	string schollType;
	string address;
	student *stu;
	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schollType;
		this->address = address;
		this->stu = new student("111");
		cout << "普通构造函数" << endl;
	}
	school(const school& a) :schollType(a.schollType), address(a.address), schoolName(a.schoolName){
		cout << "深拷贝构造函数" << endl;
		cout << this->schoolName << "拷贝建立了" << endl;
		stu = new student(*(a.stu));
	}
	school(school&& t) :schollType(t.schollType), address(t.address), schoolName(t.schoolName){
		stu = t.stu;
		t.stu = NULL;
		cout << "移动构造函数" << endl;
	}
	~school(){
		delete stu;
	}

};

int main(){
	school s1("1", "1", "1");
	school s2(move(s1));
	return 0;


}