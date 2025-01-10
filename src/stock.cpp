#include "stock.h"

Stock::Stock()
{
	//default
	mName = "";
	mSymbol = "";
	mPurchasePrice = 0;
	mCurrentPrice = 0;
	mNumShares = 0;
}

Stock::Stock(const std::string& inName, const std::string& inSymbol, 
	const Money& inPurPrice, double inNumShares)
{
	//constructor - initialize to private members
	mName = inName;
	mSymbol = inSymbol;
	mPurchasePrice = inPurPrice;
	mCurrentPrice = inPurPrice;
	mNumShares = inNumShares;
}

//Getters
Money Stock::getCurrPrice() const
{
	return mCurrentPrice;
}

Money Stock::getPurPrice() const
{
	return mPurchasePrice;
}

Money Stock::getChange() const
{
	return (mCurrentPrice - mPurchasePrice)*mNumShares;
}

std::string Stock::getSymbol() const
{
	return mSymbol;
}

std::string Stock::getName() const
{
	return mName;
}

double Stock::getNumShares() const
{
	return mNumShares;
}

//Setter
void Stock::setCurrentPrice(const Money& inCurrPrice)
{
	mCurrentPrice = inCurrPrice;
}

//Format how to output a stocks info
std::ostream& operator<<(std::ostream& out, const Stock& stock)
{
	out << stock.mSymbol << " : "<< stock.mNumShares<<" @ "<<stock.mCurrentPrice;
	return out;
}
