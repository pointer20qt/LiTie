#include<iostream>
#include<Initializer_List>
#include<string>

using namespace::std;
class vec{
private:
	int* LiFe;
public:
	vec(initializer_list<int> arr)
	{
		LiFe = new int[arr.size()];
		for (int i = 0; i < arr.size(); i++){
			LiFe[i] = *(arr.begin() + i);
		}
	}
	int& operator[](unsigned int num){
		return LiFe[num];
	}
};

int main(){
	vec c{ 1, 2, 3, 4, 5 };
	cout << c[3] << endl;
	c[4] = 6;
	cout <<c[4] << endl;

}