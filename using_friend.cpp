#include "using_friend.h"
#include<iostream>
using namespace std;
using D = double;
class house
{
	D width;
public:
	friend void printWidth(house h);
	void setWidth(D w);
};

void house::setWidth(D w){
	width = w;
}


void printWidth(house h){
	cout << "·¿×ÓµÄ¿í£º" << h.width << endl;
}

int main(){
	house h;
	h.setWidth(100.0);
	printWidth(h);
	return 0;

}