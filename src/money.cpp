#include "money.h"
#include <iomanip>

Money::Money()
{
	//default
	mCents = 0;
}

Money::Money(double inDollars)
{
	//convert dollars to cents
	mCents = 100*inDollars;
}

Money::Money(long long inDollars, long long inCents)
{
	//convert dollars and cents to cents
	mCents = 100*(inDollars) + inCents;
}

Money::Money(long long inCents)
{
	//keep cents as cents
	mCents = inCents;
}

Money::Money(int inCents)
{
	//keep cents as cents
	mCents = inCents;
}

long long Money::getCents()
{
	return mCents; 
}

Money& Money::operator+=(const Money& right)
{
	//redefine mCents when Money() is added
	this-> mCents += right.mCents;
	return *(new Money(mCents));
}

Money& Money::operator-=(const Money& right)
{
	//redefine mCents when Money() is subtracted
	this-> mCents -= right.mCents;
	return *(new Money(mCents));
}

Money& Money::operator*=(double right)
{
	//redefine mCents when multiplied by double
	this-> mCents *= right;
	return *(new Money(mCents));
}

Money& Money::operator/=(double right)
{
	//redefine mCents when divided by double
	this -> mCents /= right;
	return *(new Money(mCents));
}

Money operator+(const Money& left, const Money& right)
{
	//new variable of same type (long long) to handle Money addition
	long long newCents = left.mCents + right.mCents;
	return Money(newCents);
}


Money operator-(const Money& left, const Money& right)
{
	//new variable of same type (long long) to handle Money subtraction
	long long newCents = left.mCents - right.mCents;
	return Money(newCents);
}

Money operator*(const Money& left, double right)
{
	//new variable of same type (long long) to handle Money multiplication
	long long newCents = left.mCents * right;
	return Money(newCents);
}

Money operator/(const Money& left, double right)
{
	//new variable of same type (long long) to handle Money division
	long long newCents = left.mCents / right;
	return Money(newCents);
}

bool operator==(const Money& left, const Money& right)
{
	//define what it means if (Money(x) == Money(y))
	bool compare = false;
		if(left.mCents == right.mCents){
			compare = true;
		}
	return compare;
}

bool operator!=(const Money& left, const Money& right)
{
	//define what it means if (Money(x) != Money(y))
	bool compare = false;
		if(left.mCents != right.mCents){
			compare = true;
		}
	return compare;
}

bool operator<(const Money& left, const Money& right)
{
	//define what it means if (Money(x) < Money(y))
	bool compare = false;
		if(left.mCents < right.mCents){
			compare = true;
		}
	return compare;
}

bool operator>(const Money& left, const Money& right)
{
	//define what it means if (Money(x) > Money(y))
	bool compare = false;
		if(left.mCents > right.mCents){
			compare = true;
		}
	return compare;	
}
bool operator<=(const Money& left, const Money& right)
{
	//define what it means if (Money(x) <= Money(y))
	bool compare = false;
		if(left.mCents <= right.mCents){
			compare = true;
		}
	return compare;	
}

bool operator>=(const Money& left, const Money& right)
{
	//define what it means if (Money(x) >= Money(y))
	bool compare = false;
		if(left.mCents >= right.mCents){
			compare = true;
		}
	return compare;	
}

std::ostream& operator<<(std::ostream& out, const Money& money)
{
	//format for positive money ammount, acounting for dollars and cents
	if(money.mCents>=0){
		out << "$" << money.mCents / 100 << "." << std::setfill('0')<<std::setw(2) << money.mCents % 100;
	}
	//format for negative money ammount, acounting for dollars and cents
	else if(money.mCents<0){
		out <<"$-" << abs(money.mCents) / 100 << "." << std::setfill('0')<<std::setw(2) << abs(money.mCents) % 100;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Money& money)
{
	//initialize new double to be conveted to mCents when inputted
	double tempDollars;
	in>> tempDollars;
	money.mCents = tempDollars*100;
	return in;
}

