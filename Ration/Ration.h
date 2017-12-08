#pragma once
#include <iostream>
using namespace std;
class Ration
{
public:
	Ration();
	Ration(const Ration&); //
	Ration(long q);
	Ration(long q, long m);
	~Ration();
private:
	long q_, m_;
	long noz(const long m1, const long m2);
	void sokr();
public:
	friend Ration operator+(const Ration &ob1, long in1);
	friend Ration operator+(long in1, const Ration &ob1);
	Ration operator+(const Ration &ob1);
	Ration operator-(const Ration &ob1);
	Ration operator*(const Ration &ob1);
	Ration operator/(const Ration &ob1);
	Ration operator=(const Ration &ob1);
	bool operator==(const Ration &ob1);
	friend ostream &operator<<(ostream &out,const Ration &ob1);
	friend istream &operator>>(istream &out, Ration &ob1);

};

