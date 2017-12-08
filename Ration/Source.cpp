#include "Ration.h"
#include <iostream>
using namespace std;
int main(){
	Ration r1(1234, 345);
	Ration r2;
	cin >> r2;
	cout << r2 << endl;
	Ration r3(3, 2);
	cout << r1 << endl;
	r1 = r1 + r3;
	cout << r1 << endl;
	r1 = r1 * r3;
	cout << r1 << endl;
	r1 = r1 / r1;
	cout << r1 << endl;
	system("pause");
}