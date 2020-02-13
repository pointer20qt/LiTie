#include "Polymorphism.h"
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
	}

};

class school{
private:
	string schoolName;
	string schollType;
	string address;
public:	school(string schoolName, string schoolType, string address){
		this->schoolName = schoolName;
		this->schollType = schollType;
		this->address = address;
		cout << "普通构造函数" << endl;
	}
		school(){
			cout << "普通构造" << endl;
		}
	virtual void getschool(){
		cout << "学校开学啦" << endl;
	}
	string getschoolName(){
		return schoolName;
	}
	virtual ~school(){
		cout << "析构：大学" << endl;
	}
};
class highschool :public school{
public:
	student* s1;
	highschool():school("温岭中学", "高中", "温岭"){
		cout << "高中的构造函数" << endl;
	}

	virtual void getschool(){
		cout << "在高中校长的带领下，" << getschoolName() << endl;
		s1 = new student("xx");
	}
	virtual ~highschool(){
		cout << "析构：高中" << endl;
		delete s1;
	}
};


void printschool(school* school){
	school->getschool();
	delete school;
}
void printschool(school& school){
	school.getschool();
	delete &school;
}

int main(){
	highschool h1;
	school* a = &h1;
	a->getschool();
	school* s = new school("xx学校", "学校", "xx地");
	highschool* hs = new highschool();
	printschool(s);
	printschool(hs);
	highschool h2;
	h2.getschool();
	
	
	

}
