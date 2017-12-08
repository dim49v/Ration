#include "Ration.h"
#include <iostream>
using namespace std;

Ration::Ration() : q_(1), m_(1)
{
}
Ration::Ration(const Ration& ob1) : q_(ob1.q_), m_(ob1.m_)
{
}
Ration::Ration(long q) : q_(q), m_(1)
{

}
Ration::Ration(long q, long m)
{
	if (m != 0){
		q_ = q;
		m_ = m;
		sokr();
	}
	else{
		try{
			throw "Denominator don't can be null";
		}
		catch (char* err){
			cout << err << endl;
			system("pause");
			exit(1);
		}
	}
}

Ration::~Ration()
{
}

Ration operator+(const Ration &ob1, long in1){
	Ration temp(ob1.q_ + (in1 * ob1.m_), ob1.m_);
	return temp;
}
Ration operator+(long in1, const Ration &ob1){
	Ration temp(ob1.q_ + (in1 * ob1.m_), ob1.m_);
	return temp;
}
Ration Ration::operator+(const Ration &ob1){
	Ration temp;
	if (q_ != 0 && ob1.q_ != 0){
		long oz = noz(ob1.m_, m_);
		temp.q_ = (ob1.m_ / oz)*q_ + (m_ / oz)*ob1.q_;
		temp.m_ = ob1.m_ / oz * m_;
		temp.sokr();
	}
	else{
		temp.q_ = q_ + ob1.q_;
		temp.m_ = ob1.m_ * m_;
	}
	return temp;
}
Ration Ration::operator-(const Ration &ob1){
  	Ration temp;
	if (q_ != 0 && ob1.q_ != 0){
		long oz = noz(ob1.m_, m_);
		temp.q_ = (ob1.m_ / oz)*q_ - (m_ / oz)*ob1.q_;
		temp.m_ = ob1.m_ / oz * m_;
		temp.sokr();
	}
	else{
		temp.q_ = q_ == 0 ? -ob1.q_ : ob1.q_;
		temp.m_ = ob1.m_ * m_;
	}
	return temp;
}
Ration Ration::operator*(const Ration &ob1){
	Ration temp;
	if (q_ != 0 && ob1.q_ != 0){
		long oz1 = noz(ob1.m_, q_);
		long oz2 = noz(ob1.q_, m_);
		temp.q_ = (q_ / oz1) * (ob1.q_ / oz2);
		temp.m_ = (m_ / oz2) * (ob1.m_ / oz1);
		temp.sokr();
	}
	else{
		temp.q_ = 0;
		temp.m_ = 1;
	}
	return temp;
}
Ration Ration::operator/(const Ration &ob1){
	Ration temp(q_,m_);
	temp = temp * Ration(ob1.m_, ob1.q_);
	return temp;
}
Ration Ration::operator=(const Ration &ob1){
	q_ = ob1.q_;
	m_ = ob1.m_;
	return *this;
}
bool Ration::operator==(const Ration &ob1){
	return (q_ == ob1.q_ && m_ == ob1.m_);
}
ostream &operator<<(ostream& out,const Ration &ob1){
	out << ob1.q_ << "/" << ob1.m_;
	return out;
}
istream &operator>>(istream &in, Ration &ob1){
	cout << "q= ";
	in >> ob1.q_;
	if (!in){
		cout << "Error in";
			system("pause");
			exit(1);
	}
	cout << "m= ";
	in >> ob1.m_;
	if (!in){
		cout << "Error in" << endl;
		system("pause");
		exit(1);
	}
	return in;
}

long Ration::noz(const long m1, const long m2){
	long x = abs(m1), y = abs(m2);
	if (x != 0){
		while (x != y){
			if (x > y){
				x -= y;
			}
			else{
				y -= x;
			}
		}
	}
	return x;
}
void Ration::sokr(){
	int x = noz(q_, m_);
	if (x != 0){
		q_ /= x;
		m_ /= x;
		if (q_ < 0 && m_ > 0 || q_ > 0 && m_ < 0){
			q_ = -abs(q_);
			m_ = abs(m_);
		}
		else{
			q_ = abs(q_);
			m_ = abs(m_);
		}
	}
	else{
		q_ = 0;
		m_ = 1;
	}
}