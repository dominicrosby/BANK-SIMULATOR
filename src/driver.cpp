#include "driver.h"
#include "strlib.h"
#include "portfolio.h"
#include "stock.h"
#include "money.h"


bool buyStock(StockPortfolio& inPort, const std::string& inString)
{
	//set splitter to '|'
    std::vector<std::string> stockSections = strSplit(inString, '|');

    //set each section to the correct place
    std::string inSymbol = stockSections[0];
    std::string inName = stockSections[1];
    Money inPurchasePrice = Money(std::stod(stockSections[2]));
    double inNumShares = std::stod(stockSections[3]);

    //use addstock from constucted stock to add to portfolio 
    inPort.addStock(Stock(inName, inSymbol, inPurchasePrice, inNumShares));
    return inPort.containsStock(inSymbol);
}

bool updateStock(StockPortfolio& inPort, const std::string& inString)
{
    std::vector<std::string> stockSections = strSplit(inString, '|');

    //initialize the new money amount
    std::string inSymbol = stockSections[0];
    Money change = Money (std::stod(stockSections[1]));
    //check if stock is in portfolio
    if(inPort.containsStock(inSymbol))
    {
        //update new money amount
        (inPort[inSymbol]).setCurrentPrice(change);
        return true;
    }
    else
    {
        return false; 
    }
	 
}


bool processFile(StockPortfolio& inPort, const std::string& inString)
{
    //new objects for file and its
    std::string text;
    std::ifstream textfile;

    //open file
    textfile.open(inString);
   
    //check status
    if(textfile.fail())
    {
        return false;
    }

    //
    while(!textfile.eof())
    {
        //set the file text to the string
        std::getline(textfile,text);
        if (text == "")
        {
            continue;
        }
        else if(text[0] == '+')
        {
            if(!updateStock(inPort, text.substr(1,text.length())))
            return false;
        }
        else
        {
            if(!buyStock(inPort,text))
            {
                return false;
            }
        }
    }

    //close file
    textfile.close();
    return true;
}