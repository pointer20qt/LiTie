#include<iostream>
#include<memory>

using namespace std;


int main(){
	unique_ptr<int>ptr1(new int(7));
	cout << "u1 value :" << *ptr1 << endl;
	unique_ptr<int>ptr2 = move(ptr1);
	cout << "u2 value :" << *ptr2 << endl;
	return 0;
}
