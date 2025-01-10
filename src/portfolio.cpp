#include "portfolio.h"

StockPortfolio::StockPortfolio()
{
	//default
}

void StockPortfolio::addStock(const Stock& inStock)
{
	//adds stock to the map under key based on its symbol
	mStocks[inStock.getSymbol()] = inStock;
}

Money StockPortfolio::getTotalValue() const
{
	//new Money return value 
	Money totalValue = 0;
	
	//add the current amount of money in each stock to the total
	for(auto i: mStocks)
		{
			totalValue += i.second.getCurrPrice()*i.second.getNumShares();
		}
	return totalValue;
}

Money StockPortfolio::getOrigValue() const
{
	//new Money return value 
	Money origValue = 0;
	
	//add the  amount of money spent on each stock to the total
	for(auto i: mStocks)
		{
		origValue += i.second.getPurPrice()*i.second.getNumShares();
		}
	
	return origValue;
}

Money StockPortfolio::getProfit() const
{
	//new Money return value 
	Money totalProfit = 0;
	
	//calculate profit based on purchase price (p), current price (c), and num shares (n)
	//Profit = n*(c-p)
	for(auto i: mStocks)
	{
		totalProfit += (i.second.getCurrPrice()- i.second.getPurPrice())*i.second.getNumShares();
	}
	
	return totalProfit; 
}

std::vector<std::string> StockPortfolio::getAlphaList() 
{
	//initialize vector to return map data
	std::vector<std::string> retval;
	//map already organized alphabetically
	//add each piece of map to the vector based on its key
	for(const auto i: mStocks)
	{
		retval.push_back(i.second.getSymbol());
	}
	
	return retval;
}

std::vector<std::string> StockPortfolio::getValueList()
{
	//initialize vector to return map data
	std::vector<std::string> retval;
	//new map to iterate through
	std::map<std::string,Stock> StockPortfolio  = mStocks;
	//initialize both prices to minimum value (0)
	Money stockPrice = Money(0);
	Money maxPrice = Money(0);
	//create empty string to hold the stock symbol of the highest value
	std::string maxSymbol = "";

	//loop until every value is checked
	while (!StockPortfolio.empty())
	{
		//iterate through vector
		for(const auto i: StockPortfolio)
		{
			//compare each price to current max price
			stockPrice = i.second.getCurrPrice();
			if(stockPrice > maxPrice)
			{
				//target the max price and its symbol
				maxPrice = stockPrice;
				maxSymbol = i.second.getSymbol();
			}
		}
	//erase the highest price and its symbol to approach base case
	retval.push_back(maxSymbol);
    StockPortfolio.erase(maxSymbol);
	
	//set max to zero to make sure the program doesnt crash (took me a while to figure that out)
	maxPrice = Money(0);
	}
	
	return retval;
}

std::vector<std::string> StockPortfolio::getDiffList()
{ 
	//initialize vector to return map data
	std::vector<std::string> retval;
	
	//new map to iterate through
	std::map<std::string,Stock> StockPortfolio = mStocks;
	//initialize stock Diff
	Money stockDiff = Money(0);
	//set max difference to very large negative to ensure it is the lowest possible value
	Money maxDiff = Money(-10000000000000000000.0);
	//create empty string to hold the stock symbol of the highest value
	std::string maxSymbol = "";
	
	//loop until every value is checked
	while (!StockPortfolio.empty())
	{
		//iterate through vector
		for(const auto i: StockPortfolio)
		{
			//formula for difference (profit) = current - purchase
			stockDiff = (i.second.getCurrPrice() - i.second.getPurPrice());
			//check stock against current max
			if(stockDiff > maxDiff)
			{
				//update maximum value and symbol
				maxDiff = stockDiff;
				maxSymbol = i.second.getSymbol();
			}
		}
	//erase the highest price and its symbol to approach base case
	retval.push_back(maxSymbol);
    StockPortfolio.erase(maxSymbol);
	
	//resetset max to large negative 
	maxDiff = Money(-10000000000000000000.0);
	}

	return retval;
}

bool StockPortfolio::containsStock(const std::string& inSymbol) const
{
	//iterate through all stocks
	
	for(const auto i: mStocks)
		{
			//check if the symbol is same as input symbol
			if(i.second.getSymbol() == inSymbol)
			{
				return true;
			}
		}
	
	return false;
}

Stock& StockPortfolio::operator[](const std::string& inSymbol)
{
	//stocks can be accessed by their symbol in square brackets
	return mStocks[inSymbol];
}