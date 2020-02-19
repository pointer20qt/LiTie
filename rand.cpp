#include <iostream>
#include<time.h>
#include<math.h>

using namespace std;

bool rrand(double num){
	double p = ((double)rand()) / RAND_MAX;
	if (p >= num){
		return false;
		cout << "中奖啦！！" << endl;
	}
	else{
		return true;
		cout << "没中奖，下次再来" << endl;
	}
}

int main(){
	srand(time(0));
	for (int i = 0; i < 100; i++){
		if (rrand(0.1)){
			cout << "中奖" << endl;
		}
		else{
			cout << "没中奖" << endl;
		}
	}

}